#pragma once
#include <vector>
#include <algorithm>
#include <random>

template <typename T>
inline std::vector<T>* generate_data(size_t size)
{
	std::vector<T>* data = new std::vector<T>(size);
	std::uniform_int_distribution<T> distribution(
		(std::numeric_limits<T>::min()),
		(std::numeric_limits<T>::max()));
	std::default_random_engine generator;

	std::generate(data->begin(), data->end(), [&]() { return distribution(generator); });
	return data;
}
