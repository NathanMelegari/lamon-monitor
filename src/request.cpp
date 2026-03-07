#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <iomanip>
#include <ostream>
#include "../include/request.hpp"
#include "../include/stats.hpp"

void Request::request_api(Stats& stats, const std::string& url) {

	//INITALIZE libcurl
	CURL* curl = curl_easy_init();
	if(!curl) {
		std::cout << "Curl init failed!" << std::endl;;
		return;
	}

	//STANDARD CONFIG
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
	curl_easy_setopt(curl, CURLOPT_USERAGENT, "lamon/1.1");
	curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

	//VIEWING IF API IS ONLINE OR NOT
	//if not, the program goes waiting a conection
	//else show the data
	CURLcode res = curl_easy_perform(curl);
	stats.total_requests++;
	if (res != CURLE_OK) {
		std::cout << "Requisition failed: " << curl_easy_strerror(res) << std::endl;
		stats.total_erros++;
		std::cout << "\a" << std::flush;
	} else {
		update_stats(stats, curl);
	}

	curl_easy_cleanup(curl);

}

void Request::update_stats(Stats& stats, CURL* curl) {

	//GET DATA FROM libcurl
        //(Status and Latency)
	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &stats.status_code);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &stats.total_time);
	//LOGIC OF MAX, MIN AND AVG. LATENCY
	stats.last_latency = stats.total_time * 1000;

	if (stats.status_code >= 400) {
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
	stats.errors_rate = (double)(stats.total_erros * 100.00) / stats.total_requests;
}

void Request::show_monitor(const Stats& stats, const std::string& url) {

	std::cout << std::left;

	std::cout << std::setw(20) << "API: " << url << std::endl;
	std::cout << std::setw(20) << "Status: " << stats.status_code << std::endl;
	std::cout << std::setw(20) << "Latency: " << stats.last_latency << "ms" << std::endl;
	std::cout << std::setw(20) << "Min. Latency: " << stats.min_latency << "ms" << std::endl;
	std::cout << std::setw(20) << "Max. Latency: " << stats.max_latency << "ms" << std::endl;
	std::cout << std::setw(20) << "Avg. Latency: " << stats.avg_latency << "ms" << std::endl;
	std::cout << std::setw(20) << "Total Requests: " << stats.total_requests << std::endl;
	std::cout << std::setw(20) << "Total Errors: " << stats.total_erros << std::endl;
	std::cout << std::setw(20) << "Errors Rate: " << stats.errors_rate << "%" << std::endl;
}
