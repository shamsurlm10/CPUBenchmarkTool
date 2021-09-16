#include "stdafx.h"
#include "algorithms.h"

void* benchmarkInteger(void* args) {
    if (args != NULL)
        SetThreadAffinityMask(GetCurrentThread(), GetCurrentProcessorNumber());

    uint64_t i;
    for (i = 0; i < 1e10; i++) {
        auto result = 560 % 88 * (i - 88 + 88);
    }
    return NULL;
}

void* benchmarkFloat(void* args) {
    if (args != NULL)
        SetThreadAffinityMask(GetCurrentThread(), GetCurrentProcessorNumber());

    double i;
    for (i = 0.5; i < 1e10; i++) {
        auto result = (4 + 560) / 88.893642 * (i - 820);
    }
    return NULL;
}

void* benchmarkPrimeNumber(void* args) {
    if (args != NULL)
        SetThreadAffinityMask(GetCurrentThread(), GetCurrentProcessorNumber());

    bool flag;
    uint32_t i, j;
    for (i = 2; i < 1e7; i++) {
        flag = true;
        for (j = 2; j < sqrt(i) + 1; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
    }
    return NULL;
}
