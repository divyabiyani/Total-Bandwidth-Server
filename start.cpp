#include <bits/stdc++.h>
#include "function_str.cpp"
#include "gantt_chart.cpp"

using namespace std;

void gantt_display(vector<struct nam> finalOutput,vector<struct totalQueue> totalTasks,long long int noPeriodic,long long int noAperiodic)
{
	ALLEGRO_DISPLAY *display = NULL;
    if(!al_init()) return;
    al_init_primitives_addon();
    display = al_create_display(750, 500);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    if(!display) return;
    
    al_clear_to_color(al_map_rgb(255, 255, 255));
   
    gantt gt;
    long long int y = 100;
    //printf("3\n");
    for(long long int i = 0; i<signed(finalOutput.size()); i++) 
    {
        al_clear_to_color(al_map_rgb(255, 255, 255));
        //gt.translate(x1, y1, 2, 0);
        //gt.translate(x2, y2, 2, 0);

        for(long long int j=0;j<(noPeriodic+1);j++)
        {
        	gt.drawRoad(y + (100*j));
        }

        if(finalOutput[i].POrA=='P')
        {
        	gt.drawRectangle(i*50,(y+(100*(finalOutput[i].no-1)))-50,(i+1)*50,(y+(100*(finalOutput[i].no-1))),'P');
        }
        else
        {
        	gt.drawRectangle(i*50,(y+(100*(noPeriodic)))-50,(i+1)*50,(y+(100*(noPeriodic))),'A');
        }
        
        //e.drawWheel(x1 + 25, y2 + 10, 10, 3, i);
        //e.drawWheel(x1 + 75, y2 + 10, 10, 3, i);
        //e.drawWheel(x1 + 100, y2 + 10, 10, 3, i);
        //e.drawSmoke(x1 + 100, y1 + 5, x1 + 110, y2 - 50, i);

        al_flip_display();
        al_rest(0.25);
    }
    al_destroy_display(display);
}

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
	vector<struct totalQueue> totalTasks;
	vector<struct nam> finalOutput;
	totalTasks=totalBandwidthCalculation(noPeriodic,periodicTasks,noAperiodic,aperiodicTasks,&finalOutput);

	gantt_display(finalOutput,totalTasks,noPeriodic,noAperiodic);

	return 0;
}
