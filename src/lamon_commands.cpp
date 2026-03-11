#include <string>
#include <iostream>
#include "lamon_commands.hpp"

void Command::help_msg() {


	std::string message[5] = {
		"For execute: lamon [url] or lamon [endpoints_file.txt]\n",
		"\n",
		"Commands:\n",
		"--help or -h		-	Show the help message\n",
		"--version or -v 	-	Show ocurrent version of the program\n"
	};

	for(const auto& line : message) {
		std::cout << line << std::endl;
	};
}

void Command::view_version() {
	std::cout << "v1.0.1" << std::endl;
}
