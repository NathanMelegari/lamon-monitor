#pragma once

#include <string>
#include <curl/curl.h>
#include "stats.hpp"

struct Stats;

class Api {

	public:
		void read_file ([[maybe_unused]] const std::string& file);
		void listen_endpoints ([[maybe_unused]] const std::string& endpoints);
		void request_api(Stats& stats, const std::string& url);
		void update_stats (Stats& stats, CURL* curl);
		void show_monitor (const Stats& stats, const std::string& url);
};
