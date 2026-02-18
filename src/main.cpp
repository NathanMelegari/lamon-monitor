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
};

//RESTORE THE CURSOR CLOSING THE PROGRAM
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
	if (argc > 1 && std::string(argv[1]) == "--version") {
		std::cout << "lamon 0.1.0\n";
		return 0;
	}
	*/

	//CALL THE showHelp FUNCTION
	if(argc == 1 || std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
		showHelp();
		return 0;
	}

	const char* url = argv[1];
	Stats stats;

	curl_global_init(CURL_GLOBAL_DEFAULT);

	//PRINCIPAL LOOP
	//actually update in 1 second
	while (true) {
		std::cout << "\033[2J\033[H";
        	std::cout << " Lamon - API Monitor | " << url << "\n";
        	std::cout << "____________________________________________________________________________\n\n";

		request_api(stats, url);

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	curl_global_cleanup();
	
};
