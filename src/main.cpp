#include <chrono>
#include <cstdlib>
#include <thread>
#include <curl/curl.h>
#include <iostream>
#include <csignal>
#include <string>
#include "../include/request.hpp"
#include "../include/stats.hpp"

void restore_cursor(int) {
	std::cout << "\033[?25h";
	std::cout.flush();
	std::exit(0);
};

int main(int argc, char *argv[]) {
	
	std::signal(SIGINT, restore_cursor);
	std::cout << "\033[?25l";

	if(argc < 2) {
		std::cout << "Usage: lamon <url>\n";
		return 1;
	}
	/*
	if(arg == "--help") {
		std::cout << "Usage: lamon <url> | for monitoring\n";
		std::cout << "Usage: lamon --help | for commands\n";
		return 1;
	};
*/
	const char* url = argv[1];
	Stats stats;

	curl_global_init(CURL_GLOBAL_DEFAULT);

	while (true) {
		std::cout << "\033[2J\033[H";
        	std::cout << " Lamon Monitor | " << url << "\n";
        	std::cout << "____________________________________________________________________________\n\n";

		request_api(stats, url);

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	curl_global_cleanup();
	
};
