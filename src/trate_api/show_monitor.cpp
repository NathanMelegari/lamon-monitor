#include <string>
#include <iostream>
#include <iomanip>
#include "./include/trate_api_incl.hpp"
#include "./include/stats.hpp"

void Api::show_monitor(const Stats& stats, const std::string& url) {

	std::cout << std::left;

        std::cout << std::setw(20) << "API: " << url << std::endl;
        std::cout << std::setw(20) << "Status: " << stats.status_code << std::endl;
        std::cout << std::setw(20) << "Latency: " << stats.last_latency << "ms" << std::endl;
        std::cout << std::setw(20) << "Min. Latency: " << stats.min_latency << "ms" << std::endl
;
        std::cout << std::setw(20) << "Max. Latency: " << stats.max_latency << "ms" << std::endl
;
        std::cout << std::setw(20) << "Avg. Latency: " << stats.avg_latency << "ms" << std::endl
;
        std::cout << std::setw(20) << "Total Requests: " << stats.total_requests << std::endl;
        std::cout << std::setw(20) << "Total Errors: " << stats.total_erros << std::endl;
        std::cout << std::setw(20) << "Errors Rate: " << stats.errors_rate << "%" << std::endl;
}
