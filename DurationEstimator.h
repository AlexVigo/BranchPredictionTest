#pragma once
#include <iostream>
#include <chrono>
#include <source_location>
#include <vector>
#include <string>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::milliseconds;

template <typename T>
void showFunctionDuration(std::string(*afunc)(std::vector<T>&), std::vector<T>& avec)
{
    const auto t1 = high_resolution_clock::now();
    std::string func_name = afunc(avec);
    const auto t2 = high_resolution_clock::now();

    const duration<double, std::milli> delay = t2 - t1;

    std::cout << "Execution time of __" << func_name << "__: " << delay.count() << "ms\n";
}
