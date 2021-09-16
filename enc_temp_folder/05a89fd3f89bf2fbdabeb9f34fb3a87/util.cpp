#include "stdafx.h"
#include "Benchmark.h"

void show_info() {
	std::cout << std::endl;
	std::cout << "\t\t\t\t\t" << "CPU Benchmarking Tool" << std::endl;
	std::cout << "\t\t\t\t\t" << "=====================================" << std::endl;
	std::cout << "\t\t\t\t\t" << "INFO=================================" << std::endl;
	std::cout << "\t\t\t\t\t" << "Processor Architecture: " << tpf::GetProcessorArchitecture() << std::endl;
	std::cout << "\t\t\t\t\t" << "Processor Type: " << tpf::GetProcessorType() << std::endl;
	std::cout << "\t\t\t\t\t" << "Allocation Granularity: " << tpf::GetAllocationGranularity() << std::endl;
	std::cout << "\t\t\t\t\t" << "Processor Level: " << tpf::GetProcessorLevel() << std::endl;
	std::cout << "\t\t\t\t\t" << "Number of Processors: " << tpf::GetNumberOfProcessors() << std::endl;
	std::cout << "\t\t\t\t\t" << "=====================================" << std::endl;
}

int get_choice(int to, int from, std::string msg) {
	int result = -1;
	std::cout << "\t\t\t\t\t" << msg << std::endl;
	std::cout << "\t\t\t\t\t>> ";
	std::cin >> result;
	if (result >= to && result < from)
		return result;
	return -1;
}

void menu(Benchmark benchmark) {
	bool flag = TRUE;
	while (flag) {
		show_info();
		std::cout << "\t\t\t\t\t" << "Benchmarking Test====================" << std::endl;
		int op = get_choice(0, 3, "[1] Single Thread. [2] Multi Thread.\n\t\t\t\t\tEnter 0 to exit");

		switch (op) {
		case 0:
			flag = FALSE;
			break;
		case 1: {
			benchmark.single_thread_benchmark_run();
			break;
		}
		case 2: {
			int cores = get_choice(2, benchmark.get_total_cpu()+1, "How many threads benchmark you want?");
			if (cores == -1)
				std::cout << "\t\t\t\t\tSorry! Invalid input. Try again." << std::endl;
			else
				benchmark.multi_thread_benchmark_run(cores);
			break;
		}
		default:
			break;
		}
	}
}
