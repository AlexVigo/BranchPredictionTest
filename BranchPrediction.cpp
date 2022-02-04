#include <iostream>
#include <vector>

#include "DurationEstimator.h"
#include "SequenceGenerator.h"
#include "TestCPUParallelIterations.h"
#include "TestCPUPredictCondition.h"

int main()
{
	constexpr size_t vec_size = 100000;
	std::vector<int>* vec = generate_data<int>(vec_size);

	showFunctionDuration(CPU_cant_parallel_terations, *vec);
	showFunctionDuration(CPU_parallel_terations, *vec);

	std::cout << "----------------------------------------------------\n";

	showFunctionDuration(CPU_estimate_UNpredictable_condition, *vec);
	std::sort(vec->begin(), vec->end());
	showFunctionDuration(CPU_estimate_predictable_condition, *vec);

	

	

	std::cout << std::flush;
	delete vec;
    system("pause");
    return 0;
}
