#include <iostream>
#include <dds/sub/ddssub.hpp>
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>
#include <thread>
#include <dds/core/cond/WaitSet.hpp>
#include <dds/core/QosProvider.hpp>
#include <data_types/QoS.hpp>
#include <data_types/QoSPlugin.hpp>
#include <dps/application.hpp>

using namespace std::chrono_literals;

void start_application();
void stop_application();
bool is_running();
void send_msg();
bool stop = false;
std::thread thread1;
std::thread thread2;
dds::core::cond::WaitSet waitset;
dds::pub::DataWriter<Types::Information> w_msg = dds::core::null;
dds::sub::DataReader<Types::Information> r_msg = dds::core::null;

 
void start_application() {
    thread1 = std::thread(send_msg);
   //
   // 
   //  thread2 = std::thread(send_msg_not_secure);
}

void stop_application() {
    stop = true;
    std::cout << "Application was shutdowned." << std::endl;
    thread1.join();
    thread2.join();
}

bool is_running() {
    return thread1.joinable() || thread2.joinable();
}

void send_msg() {

    Types::Information sample;

    while (!stop) {

        sample.Data(123);
        w_msg.write(sample);

        waitset.dispatch(dds::core::Duration(1));
    }
}



void handle_msg() {

    for (auto msg : r_msg.take()) {
        if (msg.info().valid()) {
           std::cout << msg.data().Data() << std::endl;
           waitset.dispatch(dds::core::Duration(1));
        }
    }
}


int main(int argc, char* argv[]) {

    std::signal(SIGINT, application::application_stop_handler);
    std::signal(SIGTERM, application::application_stop_handler);

    rti::core::QosProviderParams provider_params;
    provider_params.url_profile({"../InformationModel/QoS.xml", "../InformationModel/entities.xml"});
    rti::core::default_qos_provider_params(provider_params);
    rti::domain::register_type<Types::Information>("Information");

    auto default_provider = dds::core::QosProvider::Default();
    auto dp = default_provider.extensions().create_participant_from_config("Secure::Alice");
    
    r_msg = rti::sub::find_datareader_by_name <dds::sub::DataReader<Types::Information>>(dp, "s_msg::r_msg");
    if (r_msg == dds::core::null) {
        std::cout << "r_msg wasn't found!" << std::endl;
        throw std::runtime_error("w_msg wasn't found!");
    }
    waitset.attach_condition(dds::sub::cond::ReadCondition(
        r_msg,
        dds::sub::status::DataState::any(),
        std::bind(handle_msg)));

    w_msg = rti::pub::find_datawriter_by_name <dds::pub::DataWriter<Types::Information>>(dp, "p_msg::w_msg");
    if (w_msg == dds::core::null) {
        std::cout << "w_msg wasn't found!" << std::endl;
        throw std::runtime_error("w_msg wasn't found!");
    }
  
    start_application();

    while (application::run_application && is_running()) {
        std::this_thread::sleep_for(1s);
    }

    stop_application();

    return EXIT_SUCCESS;

}