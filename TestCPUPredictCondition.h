#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::string CPU_estimate_UNpredictable_condition(std::vector<T>& a_vector)
{
    /*const int vec_size = static_cast<int>(a_vector.size());
    if (std::count_if(a_vector.begin(), a_vector.end(),
        [&vec_size](int const elem) { return elem >= vec_size; }) > vec_size % 2)
    {
        std::cout << "_";
    }*/
    constexpr auto comparer = 0;
    for (size_t iter = 0; iter < 100; iter++)
    {
        for (auto it = a_vector.begin(); it != a_vector.end(); ++it)
        {
            if (*it > comparer)
                ++(*it);
        }
    }
    return std::source_location::current().function_name();
}

template <typename T>
std::string CPU_estimate_predictable_condition(std::vector<T>& a_vector)
{
    /*int vec_size = static_cast<int>(a_vector.size());
    if (std::count_if(a_vector.begin(), a_vector.end(),
        [&vec_size](int const elem) { return elem >= vec_size; }) > 0)
    {
        std::cout << "_";

    }*/
    constexpr auto comparer = 0;
   for (size_t iter = 0; iter < 100; iter++ )
    {
	    for (auto it = a_vector.begin(); it != a_vector.end(); ++it)
	    {
	        if (*it > comparer) 
				++(*it);
	    }
    }
    return std::source_location::current().function_name();
}
