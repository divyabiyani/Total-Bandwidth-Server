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
        long long int j=0;
        
        for(j=0;j<(noPeriodic+1);j++)
        {
        	gt.drawRoad(y + (100*j));
        }
        for(j=0;j<=i;j++)
        {
            long long int k=0;
            while(totalTasks[k].arrivalTime<=i)
            {
                if(totalTasks[k].name.POrA=='P')
                    gt.drawVerticalRoad((totalTasks[k].arrivalTime+1)*25,(y+(100*(totalTasks[k].name.no-1))));
                else if(totalTasks[k].name.POrA=='A')
                    gt.drawVerticalRoad((totalTasks[k].arrivalTime+1)*25,(y+(100*(noPeriodic))));
                k++;
            }

            k=0;

            while(k<=signed(totalTasks.size()))
            {
                if(totalTasks[k].deadline<=i)
                {
                    if(totalTasks[k].name.POrA=='P')
                        gt.drawVerticalRoadDead((totalTasks[k].deadline+1)*25,(y+(100*(totalTasks[k].name.no-1))));
                    else if(totalTasks[k].name.POrA=='A')
                        gt.drawVerticalRoadDead((totalTasks[k].deadline+1)*25,(y+(100*(noPeriodic))));
                }
                k++;
            }
            while(totalTasks[k].arrivalTime<=i)
            {
                if(totalTasks[k].name.POrA=='P')
                    gt.drawVerticalRoad((totalTasks[k].arrivalTime+1)*25,(y+(100*(totalTasks[k].name.no-1))));
                else if(totalTasks[k].name.POrA=='A')
                    gt.drawVerticalRoad((totalTasks[k].arrivalTime+1)*25,(y+(100*(noPeriodic))));
                k++;
            }
            if(finalOutput[j].POrA=='P')
            {
            	gt.drawRectangle((j+1)*25,(y+(100*(finalOutput[j].no-1)))-50,(j+2)*25,(y+(100*(finalOutput[j].no-1))),'P');
            }
            else if(finalOutput[j].POrA=='A')
            {
            	gt.drawRectangle((j+1)*25,(y+(100*(noPeriodic)))-50,(j+2)*25,(y+(100*(noPeriodic))),'A');
            }
        }

        al_flip_display();
        al_rest(0.25);
    }
    al_rest(1.0);
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
