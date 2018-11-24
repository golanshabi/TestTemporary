#include "WorkloadD.h"
#include "common.h"
#include "WorkloadInterface.h"

namespace WorkloadD
{

WorkloadUInt64 GenWorkload16M()
{
	const int N = 16000000;
	const int Q = 20000000;
	WorkloadUInt64 workload;
	workload.AllocateMemory(N, Q);
	rep(i, 0, N-1)
	{
		uint64_t key = 0;
		rep(k, 2, 7)
		{
			key = key * 256 + rand() % 5 + 48;
		}
		rep(k, 0, 1)
		{
			key = key * 256 + rand() % 64 + 32;
		}
		workload.initialValues[i] = key;
	}
	rep(i, 0, Q-1)
	{
		workload.operations[i].type = WorkloadOperationType::LOWER_BOUND;
		uint64_t key = 0;
		rep(k, 2, 7)
		{
			key = key * 256 + rand() % 5 + 48;
		}
		rep(k, 0, 1)
		{
			key = key * 256 + rand() % 64 + 32;
		}
		workload.operations[i].key = key;
	}
	workload.PopulateExpectedResultsUsingStdSet();
	return workload;
}

WorkloadUInt64 GenWorkload80M()
{
	const int N = 80000000;
	const int Q = 20000000;
	WorkloadUInt64 workload;
	workload.AllocateMemory(N, Q);
	rep(i, 0, N-1)
	{
		uint64_t key = 0;
		rep(k, 2, 7)
		{
			key = key * 256 + rand() % 6 + 48;
		}
		rep(k, 0, 1)
		{
			key = key * 256 + rand() % 96 + 32;
		}
		workload.initialValues[i] = key;
	}
	rep(i, 0, Q-1)
	{
		workload.operations[i].type = WorkloadOperationType::LOWER_BOUND;
		uint64_t key = 0;
		rep(k, 2, 7)
		{
			key = key * 256 + rand() % 6 + 48;
		}
		rep(k, 0, 1)
		{
			key = key * 256 + rand() % 96 + 32;
		}
		workload.operations[i].key = key;
	}
	workload.PopulateExpectedResultsUsingStdSet();
	return workload;
}

}	// namespace WorkloadD

