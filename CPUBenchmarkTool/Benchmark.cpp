#include "stdafx.h"
#include "Benchmark.h"
#include "algorithms.h"

Benchmark::Benchmark(DWORD total_cores) {
	this->total_cores = total_cores;
	this->single_integer_score = -1;
	this->single_floating_point_score = -1;
	this->single_prime_number_score = -1;
	this->multi_integer_score = -1;
	this->multi_floating_point_score = -1;
	this->multi_prime_number_score = -1;
}

int Benchmark::get_total_cpu() {
	return (int) this->total_cores;
}

void Benchmark::single_thread_benchmark_run() {
	pthread_t thread;
	std::chrono::steady_clock::time_point start, end;
	std::chrono::duration<double> passed;

	std::cout << "\t\t\t\t\tRunning Integer Operations Benchmark..." << std::endl;
	start = std::chrono::steady_clock::now();
	pthread_create(&thread, NULL, benchmarkInteger, (void*)1);
	pthread_join(thread, NULL);
	end = std::chrono::steady_clock::now();
	passed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	double int_benchmark_time = passed.count();

	std::cout << "\t\t\t\t\tRunning Floating Point Operations Benchmark..." << std::endl;
	start = std::chrono::steady_clock::now();
	pthread_create(&thread, NULL, benchmarkFloat, (void*)1);
	pthread_join(thread, NULL);
	end = std::chrono::steady_clock::now();
	passed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	double float_benchmark_time = passed.count();

	std::cout << "\t\t\t\t\tRunning Prime Number Benchmark..." << std::endl;
	start = std::chrono::steady_clock::now();
	pthread_create(&thread, NULL, benchmarkPrimeNumber, (void*)1);
	pthread_join(thread, NULL);
	end = std::chrono::steady_clock::now();
	passed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	double prime_number_benchmark_time = passed.count();

	// std::cout << "\t\t\t\t\tInteger Operations Executed Time: " << int_benchmark_time << " s" << std::endl;
	// std::cout << "\t\t\t\t\tFloating Point Operations Executed Time: " << float_benchmark_time << " s" << std::endl;
	// std::cout << "\t\t\t\t\tPrime Number Operation Executed Time: " << prime_number_benchmark_time << " s" << std::endl;

	this->single_integer_score = 1 / int_benchmark_time;
	this->single_floating_point_score = 1 / float_benchmark_time;
	this->single_prime_number_score = 1 / prime_number_benchmark_time;

	this->PrintSingleCorePerformance();
	double average_score = (this->single_integer_score + this->single_floating_point_score + this->single_prime_number_score) / 3;
	std::cout << "\t\t\t\t\tTotal Score: " << average_score << std::endl;
}

double Benchmark::multi_thread_benchmark_run(int cores) {
	return 0.1;
}

void Benchmark::PrintSingleCorePerformance() {
	std::cout << "\t\t\t\t\tInteger Operations Score: " << this->single_integer_score << std::endl;
	std::cout << "\t\t\t\t\tFloating Point Operations Score: " << this->single_floating_point_score << std::endl;
	std::cout << "\t\t\t\t\tPrime Number Operation Score: " << this->single_prime_number_score << std::endl;
}
void Benchmark::PrintMultiCorePerformance() {
	// std::cout << "\t\t\t\t\tInteger Operations Executed Time: " << int_benchmark_time << " s" << std::endl;
	// std::cout << "\t\t\t\t\tFloating Point Operations Executed Time: " << float_benchmark_time << " s" << std::endl;
	// std::cout << "\t\t\t\t\tPrime Number Operation Executed Time: " << prime_number_benchmark_time << " s" << std::endl;
}
