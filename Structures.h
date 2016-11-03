#ifndef STRUCTURES_H
#define STRUCTURES_H

struct periodic
{
	long long int capacity;
	long long int timePeriod;
};

struct aperiodic
{
	long long int arrivalTime;
	long long int capacity;
};

struct totalInQueue
{
	long long int arrivalTime;
	long long int capacity;
	long long int deadline;
};

struct readyQueue
{
	long long int arrivalTime;
	long long int capacity;
	long long int deadline;
};

#endif