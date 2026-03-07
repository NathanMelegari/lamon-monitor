#include <chrono>
#include <cstdlib>
#include <thread>
#include <curl/curl.h>
#include <iostream>
#include <csignal>
#include <string>
#include "../include/request.hpp"
#include "../include/stats.hpp"

//THE HELP COMMAND
//new features coming soon
void showHelp() {
	std::cout << R"(
	Lamon - API Monitor CLI

	Usage:
		lamon [URL]
	
	Options:
		-h, --help	Show this help message

	Examples:
		lamon https://api.github.com
	)";
}

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

	if (usr_arg == "--version" || usr_arg == "-v") {
		std::cout << "lamon 1.1" << std::endl;
		return 1;
	}
	//CALL THE showHelp FUNCTION
	else if(usr_arg == "--help" || usr_arg == "-h") {
		showHelp();
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

		Request::request_api(stats, url);
		Request::show_monitor(stats, url);		

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	curl_global_cleanup();	
}
