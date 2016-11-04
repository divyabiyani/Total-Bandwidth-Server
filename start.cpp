#include <bits/stdc++.h>
#include "function_str.cpp"
#include "gantt_chart.cpp"

using namespace std;

void gantt_display(vector<struct nam> finalOutput,long long int noPeriodic,long long int noAperiodic)
{
	ALLEGRO_DISPLAY *display = NULL;
    if(!al_init()) return;
    al_init_primitives_addon();
    display = al_create_display(750, 500);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    if(!display) return;
    
    al_clear_to_color(al_map_rgb(255, 255, 255));
   
    gantt gt;
    float x1 = 0,y1 = 220, x2 = 125, y2 = 100;
    //printf("3\n");
    for(float i = 0; i + 120 < 1500; i += 2) {
        al_clear_to_color(al_map_rgb(255, 255, 255));
        gt.translate(x1, y1, 2, 0);
        gt.translate(x2, y2, 2, 0);

        for(long long int j=0;j<(noPeriodic+1);j++)
        {
        	gt.drawRoad(y2 + (100*j));
        }
        
        //e.drawWheel(x1 + 25, y2 + 10, 10, 3, i);
        //e.drawWheel(x1 + 75, y2 + 10, 10, 3, i);
        //e.drawWheel(x1 + 100, y2 + 10, 10, 3, i);
        //e.drawSmoke(x1 + 100, y1 + 5, x1 + 110, y2 - 50, i);

        al_flip_display();
        al_rest(0.025);
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

	// for(long long int i=0;i<signed(totalTasks.size());i++)
	// {
	// 	cout<<totalTasks[i].arrivalTime<<endl;
	// }

	// for(long long int i=0;i<signed(finalOutput.size());i++)
	// {
	// 	cout<<finalOutput[i].POrA<<finalOutput[i].no<<endl;
	// }

	gantt_display(finalOutput,noPeriodic,noAperiodic);

	return 0;
}
