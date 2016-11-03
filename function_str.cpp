#include <bits/stdc++.h>
#include "Structures.h"

using namespace std;

bool sort_by_timePeriod( struct periodic lhs, struct periodic rhs )
{
   return lhs.timePeriod < rhs.timePeriod;
}

bool sort_by_arrivalTime( struct aperiodic lhs, struct aperiodic rhs )
{
   return lhs.arrivalTime < rhs.arrivalTime;
}

double UtilizationP(long long int noPeriodic,struct periodic periodicTasks[])
{
	double Up=0.00;

	for (long long int i=0;i<noPeriodic;i++)
	{
		Up=Up+(periodicTasks[i].capacity/(periodicTasks[i].timePeriod*1.00));
	}

	return Up;
}

void deadlineCalculator(vector<struct totalQueue> *totalTasks,long long int noAperiodic,struct aperiodic aperiodicTasks[],double Us)
{
	long long int lastDeadline=0;
	struct totalQueue tQ;
	long long int UIs=(1/Us);
	for(long long int i=0;i<noAperiodic;i++)
	{
		tQ.arrivalTime=aperiodicTasks[i].arrivalTime;
		tQ.capacity=aperiodicTasks[i].capacity;
		tQ.deadline=max(tQ.arrivalTime,lastDeadline) + (tQ.capacity*UIs);
		lastDeadline=tQ.deadline;	
		totalTasks->push_back(tQ);
	}

	return;
}

void totalBandwidthCalculation(long long int noPeriodic,struct periodic periodicTasks[],long long int noAperiodic,struct aperiodic aperiodicTasks[])
{
	sort( periodicTasks, periodicTasks+noPeriodic, sort_by_timePeriod );
	sort( aperiodicTasks, aperiodicTasks+noAperiodic, sort_by_arrivalTime );

	double Up=UtilizationP(noPeriodic,periodicTasks);
	double Us=1-Up;

	vector<struct totalQueue> totalTasks;

	deadlineCalculator(&totalTasks,noAperiodic,aperiodicTasks,Us);
}
