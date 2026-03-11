#include <chrono>
#include <cstdlib>
#include <thread>
#include <curl/curl.h>
#include <iostream>
#include <csignal>
#include <string>
#include "./trate_api/include/trate_api_incl.hpp"
#include "./trate_api/include/stats.hpp"
#include "lamon_commands.hpp"


//RESTORE THE CURSOR CLOSING THE PROGRAM
void restore_cursor(int) {
	std::cout << "\033[?25h";
	std::cout.flush();
	std::exit(0);
}

int main(int argc, char *argv[]) {

	if(argc < 2) {
		std::cout << "Use: lamon \033[36m[url]\033[0m" << std::endl;
		return 1;
	}

	std::string usr_arg = argv[1];
	const std::string url = usr_arg;
        Stats stats;
	Api api;

	if (usr_arg == "--version" || usr_arg == "-v") {
		Command::view_version();
		return 1;
	}
	//CALL THE showHelp FUNCTION
	else if(usr_arg == "--help" || usr_arg == "-h") {
		Command::help_msg();
		return 1;
	}
	else if(usr_arg.empty() || (usr_arg.rfind("http://", 0) != 0 && usr_arg.rfind("https://", 0) != 0)) {
		std::cout << "Invalid argument!" << std::endl;
		std::cout << "Use: lamon \033[36m[--help]\033[0m" << std::endl;
		return 1;
	}

	std::signal(SIGINT, restore_cursor);
        std::cout << "\033[?25l";

	curl_global_init(CURL_GLOBAL_DEFAULT);

	//PRINCIPAL LOOP
	//actually update in 1 second
	while (true) {
		std::cout << "\033[2J\033[H";

		api.request_api(stats, url);
		api.show_monitor(stats, url);	

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	curl_global_cleanup();	
}
