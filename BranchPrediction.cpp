#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

static std::vector<int> generate_data(size_t size)
{
    using value_type = int;
    static std::uniform_int_distribution<value_type> distribution(
        std::numeric_limits<value_type>::min(),
        std::numeric_limits<value_type>::max());
    static std::default_random_engine generator;

    std::vector<value_type> data(size);
    std::generate(data.begin(), data.end(), []() { return distribution(generator); });
    return data;
}

void unpredictable(std::vector<int>& a_vector)
{
    int vec_size = static_cast<int>(a_vector.size());
	if(std::count_if(a_vector.begin(), a_vector.end(),
			[&vec_size](int const elem) { return elem >= vec_size; }) > vec_size % 2)
	{
        std::sort(a_vector.begin(), a_vector.end());
	}
}

void predictable(std::vector<int>& a_vector)
{
    int vec_size = static_cast<int>(a_vector.size());
    if (std::count_if(a_vector.begin(), a_vector.end(),
        [&vec_size](int const elem) { return elem >= vec_size; }) > 0)
    {
        std::sort(a_vector.begin(), a_vector.end());
    }
}

int main()
{
    std::vector<int> vec = generate_data(10000);

	auto t1 = high_resolution_clock::now();
    unpredictable(vec);
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> delay = t2 - t1;

    std::cout << "Unpredictable when count:\n";
    std::cout << delay.count() << "ms\n";

    std::cout << "-------------------------\n";
    std::cout << "Predictable when count:\n";
    t1 = high_resolution_clock::now();
    predictable(vec);
    t2 = high_resolution_clock::now();
    delay = t2 - t1;

    std::cout << delay.count() << "ms\n";

    system("pause");
    return 0;
}
