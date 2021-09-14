// CPUBenchmarkTool.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "stdafx.h"
#include "algorithms.h"


int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, benchmarkFloat, (void*) 1);
    pthread_join(thread, NULL);
    
    system("pause;");
}
