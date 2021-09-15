#include "stdafx.h"
#include "algorithms.h"
#include "Benchmark.h"
#include "util.h"

int main() {
    Benchmark benchmark = Benchmark(tpf::GetNumberOfProcessors());
    menu(benchmark);
}
