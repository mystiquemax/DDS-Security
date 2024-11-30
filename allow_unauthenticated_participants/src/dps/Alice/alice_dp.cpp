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
#include <dds/domain/ddsdomain.hpp>

using namespace std::chrono_literals;

void start_application();
void stop_application();
bool is_running();
void send_msg();
void send_msg_not_secret();
bool stop = false;
std::thread thread1;
dds::core::cond::WaitSet waitset;

dds::pub::DataWriter<Not_Secret::Not_Secret> w_msg_not_secret = dds::core::null;

 
void start_application() {
    thread1 = std::thread(send_msg_not_secret);
}

void stop_application() {
    stop = true;
    std::cout << "Application was shutdowned." << std::endl;
    thread1.join();
}

bool is_running() {
    return thread1.joinable();
}

void send_msg_not_secret() 
{
    Not_Secret::Not_Secret sample;

    while (!stop) {
        sample.Data(777);
        w_msg_not_secret.write(sample);
        waitset.dispatch(dds::core::Duration(1));
    }
}

int main(int argc, char* argv[]) {

    std::signal(SIGINT, application::application_stop_handler);
    std::signal(SIGTERM, application::application_stop_handler);

    rti::core::QosProviderParams provider_params;
    provider_params.url_profile({"../InformationModel/QoS.xml", "../InformationModel/entities.xml"});
    rti::core::default_qos_provider_params(provider_params);
    rti::domain::register_type<Not_Secret::Not_Secret>("Not_Secret");

    auto default_provider = dds::core::QosProvider::Default();
    auto dp = default_provider.extensions().create_participant_from_config("Secure::Alice");
    
    dds::domain::ignore(dp, dp.instance_handle());
    
    w_msg_not_secret = rti::pub::find_datawriter_by_name <dds::pub::DataWriter<Not_Secret::Not_Secret>>(dp, "p_msg_not_secret::w_msg_not_secret");
    if (w_msg_not_secret == dds::core::null) {
        std::cout << "w_msg_not_secret wasn't found!" << std::endl;
        throw std::runtime_error("w_msg_not_secret wasn't found!");
    }
  
    start_application();

    while (application::run_application) {
        std::this_thread::sleep_for(1s);
    }

    stop_application();

    return EXIT_SUCCESS;

}