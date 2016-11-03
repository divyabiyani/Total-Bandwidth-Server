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

bool TotalQueue_sort_by_arrivalTime( struct totalQueue lhs, struct totalQueue rhs )
{
   return lhs.arrivalTime < rhs.arrivalTime;
}

bool sort_by_deadline( struct totalQueue lhs, struct totalQueue rhs )
{
   return lhs.deadline < rhs.deadline;
}

void pop_front(vector<struct totalQueue>* v)
{
    assert(!v->empty());
    v->erase(v->begin());
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
		tQ.name=aperiodicTasks[i].name;
		lastDeadline=tQ.deadline;	
		totalTasks->push_back(tQ);
	}

	return;
}

void periodicTasksAddition(vector<struct totalQueue> *totalTasks,long long int noPeriodic,struct periodic periodicTasks[],long long int endLimit)
{
	for(long long int i=0;i<noPeriodic;i++)
	{
		long long int p=0;
		while(p<=endLimit)
		{
			struct totalQueue tQ;
			tQ.arrivalTime=p;
			p+=periodicTasks[i].timePeriod;
			tQ.capacity=periodicTasks[i].capacity;
			tQ.name=periodicTasks[i].name;
			tQ.deadline=p;
			totalTasks->push_back(tQ);
		}
	}
	return;
}

void EDF(vector<struct totalQueue> totalTasks)
{
	long long int t=0;
	vector<struct totalQueue> readyTasks;
	vector<struct nam> finalOutput;

	struct nam empty;
	empty.POrA='Z';
	empty.no=-1;

	for(long long int i=0;i<totalTasks.size();i++)
	{
		cout<<totalTasks[i].name.POrA<<totalTasks[i].name.no<<" "<<totalTasks[i].arrivalTime<<" "<<totalTasks[i].deadline<<" "<<totalTasks[i].capacity<<endl;
	}

	while(!totalTasks.empty() || !readyTasks.empty())
	{
		long long int i=0;
		while(totalTasks[i].arrivalTime<=t && !totalTasks.empty())
		{
			readyTasks.push_back(totalTasks[i]);
			pop_front(&totalTasks);
		}

		sort( readyTasks.begin(), readyTasks.end(), sort_by_deadline );

		if(!readyTasks.empty())
		{
			finalOutput.push_back(readyTasks[0].name);
			readyTasks[0].capacity=readyTasks[0].capacity-1;
			//cout<<readyTasks[0].name.no<<" "<<readyTasks[0].capacity<<endl;
			if(readyTasks[0].capacity==0)
			{
				pop_front(&readyTasks);
			}
		}
		else
			finalOutput.push_back(empty);

		t++;
	}
	//cout<<"size:"<<finalOutput.size()<<endl;;
	for(long long int i=0;i<finalOutput.size();i++)
	{
		cout<<finalOutput[i].POrA<<finalOutput[i].no<<endl;
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

	periodicTasksAddition(&totalTasks,noPeriodic,periodicTasks,totalTasks.back().deadline);

	sort( totalTasks.begin(), totalTasks.end(), TotalQueue_sort_by_arrivalTime );

	EDF(totalTasks);

}
