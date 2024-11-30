#include <string>
#include <csignal>

namespace application
{
	volatile std::atomic_bool run_application = true;

	void application_stop_handler(int val)
	{
		run_application = false;
		std::signal(SIGINT, application_stop_handler);
		std::signal(SIGTERM, application_stop_handler);
	}
}
