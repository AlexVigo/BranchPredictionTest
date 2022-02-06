#pragma once
#include <vector>
#include <algorithm>
#include <random>

template <typename T>
void generate_data(std::vector<T> &a_vector)
{
	std::uniform_int_distribution<T> distribution(
		(std::numeric_limits<T>::min()),
		(std::numeric_limits<T>::max()));
	std::default_random_engine generator;

	std::generate(a_vector.begin(), a_vector.end(), [&]() { return distribution(generator); });
}
