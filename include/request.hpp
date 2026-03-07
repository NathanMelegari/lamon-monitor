#pragma once

#include <string>
#include <curl/curl.h>

struct Stats;

namespace Request {

	void request_api(Stats& stats, const std::string& url);
	void update_stats(Stats& stats, CURL* curl);
	void show_monitor(const Stats& stats, const std::string& url);
};

//void request_api(Stats& stats, const char* url);
//void update_stats();
