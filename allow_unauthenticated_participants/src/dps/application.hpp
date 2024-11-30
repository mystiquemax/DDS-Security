#include <string>
#include <csignal>

namespace application
{
	volatile std::atomic_bool run_application = true;

	void application_stop_handler(int)
	{
		run_application = false;
		// signals have to be re-registered 
		std::signal(SIGINT, application_stop_handler);
		std::signal(SIGTERM, application_stop_handler);
	}
	inline void setup_signal_handlers()
	{
		std::signal(SIGINT, application_stop_handler);
		std::signal(SIGTERM, application_stop_handler);
	}

}
