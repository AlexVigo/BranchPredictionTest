#include <iostream>
#include <vector>

#include "DurationEstimator.h"
#include "SequenceGenerator.h"
#include "TestCPUParallelIterations.h"
#include "TestCPUPredictCondition.h"

constexpr size_t vec_size = 100000;

int main()
{
	
	auto vec =  std::vector<int>(vec_size);
	generate_data(vec);

	showFunctionDuration(CPU_cant_parallel_terations, vec);
	showFunctionDuration(CPU_parallel_terations, vec);

	std::cout << "----------------------------------------------------\n";

	showFunctionDuration(CPU_estimate_UNpredictable_condition, vec);
	std::sort(vec.begin(), vec.end());
	showFunctionDuration(CPU_estimate_predictable_condition, vec);

    system("pause");
    return 0;
}
