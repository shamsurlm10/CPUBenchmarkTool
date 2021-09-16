#pragma once
#include "stdafx.h"

class Benchmark {
private:
	DWORD total_cores;
	double single_integer_score;
	double multi_integer_score;
	double single_floating_point_score;
	double multi_floating_point_score;
	double single_prime_number_score;
	double multi_prime_number_score;
public:
	Benchmark(DWORD total_cores);
	int get_total_cpu();
	void single_thread_benchmark_run();
	void multi_thread_benchmark_run(int cores);
	void PrintSingleCorePerformance();
	void PrintMultiCorePerformance();
};

