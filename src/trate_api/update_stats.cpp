#include <curl/curl.h>
#include <iostream>
#include <ostream>
#include "./include/trate_api_incl.hpp"
#include "./include/stats.hpp"

void Api::update_stats(Stats& stats, CURL* curl) {

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
