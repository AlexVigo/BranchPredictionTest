#pragma once
#include <vector>
#include <string>

template <typename T>
std::string CPU_parallel_terations(std::vector<T>& a_vector)
{
    for (auto it = a_vector.begin(); it != a_vector.end(); ++it)
    {
        ++* it;
    }
    return std::source_location::current().function_name();
}

template <typename T>
std::string CPU_cant_parallel_terations(std::vector<T>& a_vector)
{
    for (auto it = a_vector.begin(); it != a_vector.end(); ++it)
    {
        ++* a_vector.begin();
    }
    return std::source_location::current().function_name();
}