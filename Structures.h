#ifndef STRUCTURES_H
#define STRUCTURES_H

struct nam
{
	char POrA;
	long long int no;
};

struct periodic
{
	struct nam name;
	long long int capacity;
	long long int timePeriod;
};

struct aperiodic
{
	struct nam name;
	long long int arrivalTime;
	long long int capacity;
};

struct totalQueue
{
	struct nam name;
	long long int arrivalTime;
	long long int capacity;
	long long int deadline;
};

#endif