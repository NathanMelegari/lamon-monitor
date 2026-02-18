#include <curl/curl.h>
#include <iostream>
#include <iomanip>
#include <ostream>
#include "../include/request.hpp"
#include "../include/stats.hpp"

void request_api(Stats& stats, const char* url) {

	//INITALIZE libcurl
	CURL* curl = curl_easy_init();
	if(!curl) {
		std::cout << "Curl init failed!\n";
		return;
	}

	//STANDARD CONFIG
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
	curl_easy_setopt(curl, CURLOPT_USERAGENT, "lamon/1.0");
	curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

	//VIEWING IF API IS ONLINE OR NOT
	//if not, the program goes waiting a conection
	//else show the data
	CURLcode res = curl_easy_perform(curl);
	stats.total_requests++;
	if (res != CURLE_OK) {
		std::cout << "Requisition failed: " << curl_easy_strerror(res) << "\n";
		stats.total_erros++;
		std::cout << "\a" << std::flush;
	}else {
	
		long server_stats = 0;
		double total_time = 0;

		//GET DATA FROM libcurl
		//(Status and Latency)
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &server_stats);
		curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &total_time);

		//LOGIC OF MAX, MIN AND AVG. LATENCY
                stats.last_latency = total_time * 1000;

		if (server_stats >= 400) {
			stats.total_erros++;
		}
		if (stats.total_requests == 1 || stats.last_latency < stats.min_latency) {
			stats.min_latency = stats.last_latency;
		}
		if (stats.last_latency > stats.max_latency) {
			stats.max_latency = stats.last_latency;
		}

		stats.avg_latency = ((stats.avg_latency * (stats.total_requests - 1)) + stats.last_latency) / stats.total_requests;

		//THE RATE OF ERRORS
		double errors_rate = (double)(stats.total_erros * 100.00) / stats.total_requests;

		//SHOW AT CLI MONITOR
		//architecture updates coming soon
		std::cout << std::left;

		std::cout << std::setw(20) << "Status: " << server_stats << "\n";
		std::cout << std::setw(20) << "Latency: " << stats.last_latency << "ms\n";
		std::cout << std::setw(20) << "Min. Latency: " << stats.min_latency << "ms\n";
		std::cout << std::setw(20) << "Max. Latency: " << stats.max_latency << "ms\n";
		std::cout << std::setw(20) << "Avg. Latency: " << stats.avg_latency << "ms\n";
		std::cout << std::setw(20) << "Total Requests: " << stats.total_requests << "\n";
		std::cout << std::setw(20) << "Total Errors: " << stats.total_erros << "\n";
		std::cout << std::setw(20) << "Errors Rate: " << errors_rate << "%\n";
	}

};
