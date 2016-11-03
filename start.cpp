#include <bits/stdc++.h>
#include "function_str.cpp"

using namespace std;

int main()
{
	long long int noAperiodic,noPeriodic,i;

	printf("Enter the no. of periodic tasks:");
	scanf("%lld",&noPeriodic);
	struct periodic periodicTasks[noPeriodic];
	printf("Enter the details for %lld periodic tasks\n",noPeriodic);
	for(i=0;i<noPeriodic;i++)
	{
		printf("Enter the computation time of periodic task %lld:",i+1);
		scanf("%lld",&periodicTasks[i].capacity);
		printf("Enter the time period of periodic task %lld:",i+1);
		scanf("%lld",&periodicTasks[i].timePeriod);
		periodicTasks[i].name.POrA='P';
		periodicTasks[i].name.no=i+1;
	}

	printf("Enter the no. of Aperiodic requests:");
	scanf("%lld",&noAperiodic);
	struct aperiodic aperiodicTasks[noAperiodic];
	printf("Enter the details for %lld aperiodic requests\n",noAperiodic);
	for(i=0;i<noAperiodic;i++)
	{
		printf("Enter the arrival time of aperiodic request %lld:",i+1);
		scanf("%lld",&aperiodicTasks[i].arrivalTime);
		printf("Enter the computation time of aperiod request %lld:",i+1);
		scanf("%lld",&aperiodicTasks[i].capacity);
		aperiodicTasks[i].name.POrA='A';
		aperiodicTasks[i].name.no=i+1;
	}

	totalBandwidthCalculation(noPeriodic,periodicTasks,noAperiodic,aperiodicTasks);

	return 0;
}
