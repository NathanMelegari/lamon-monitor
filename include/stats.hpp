#pragma once

#include <limits>

struct Stats {
//	long stats = 0;
	long total_requests = 0;
	long total_erros = 0;

	double last_latency = 0;
	double min_latency = std::numeric_limits<double>::max();
	double max_latency = 0;
	double avg_latency = 0;

	
}; 
