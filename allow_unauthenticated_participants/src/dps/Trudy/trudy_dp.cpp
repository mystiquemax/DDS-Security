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
void handle_msg();
bool stop = false;
std::thread thread;
dds::core::cond::WaitSet waitset;

dds::sub::DataReader<Not_Secret::Not_Secret> r_msg_not_secret = dds::core::null;

void start_application() {
    while (true) {
        handle_msg();
    }
}

void stop_application() {
    stop = true;
    std::cout << "Application was shutdowned." << std::endl;
    thread.join();
}

bool is_running() {
    return thread.joinable();
}


void handle_msg() {

    for (auto msg : r_msg_not_secret.take()) {
        if (msg.info().valid()) {
            std::cout << msg.data() << std::endl;  
            waitset.dispatch(dds::core::Duration(1));
        }
    }
}

int main(int argc, char* argv[]) {


    rti::core::QosProviderParams provider_params;
    provider_params.url_profile({ "../InformationModel/QoS.xml", "../InformationModel/entities.xml" });
    rti::core::default_qos_provider_params(provider_params);
    rti::domain::register_type<Not_Secret::Not_Secret>("Not_Secret");

    auto default_provider = dds::core::QosProvider::Default();
    auto dp = default_provider.extensions().create_participant_from_config("Secure::Trudy");

    //dds::domain::ignore(dp, dp.instance_handle());

    r_msg_not_secret = rti::sub::find_datareader_by_name <dds::sub::DataReader<Not_Secret::Not_Secret>>(dp, "s_msg_not_secret::r_msg_not_secret");
 
    waitset.attach_condition(dds::sub::cond::ReadCondition(
        r_msg_not_secret,
        dds::sub::status::DataState::any(),
        std::bind(handle_msg)));

    if (r_msg_not_secret == dds::core::null) {
        std::cout << "r_msg_not_secret wasn't found!" << std::endl;
        throw std::runtime_error("r_msg_not_secret wasn't found!");
    }

    start_application();
    while (application::run_application) {
        std::this_thread::sleep_for(1s);
    }
    stop_application();

    return EXIT_SUCCESS;

}