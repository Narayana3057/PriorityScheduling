#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void Arrival_sort();
void Process_sort();
int Check_Arrival_Time();
struct PriorityScheduling
{
    int priority;
	int burst_time;
	int refer,complete_time,waiting_time,turnaround_time;
	int status;
	int process;
	int arrival_time;
}P[100];
int n;
main()
{
	int b=0,time=0,largest;
	float TAT_sum=0.0,WT_sum=0.0;
	float wait_time = 0, turnaround_time = 0, average_waiting_time;
	printf("\n-----------------------------------------------------PRIORITY_SCHEDULING-----------------------------------------------");
	printf("\nEnter number of process :");
	scanf("%d",&n);
	int temp;
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("\nEnter  BURST-TIME  for process-[%d]:",i+1);
		scanf("%d",&P[i].burst_time);
		printf("\nEnter ARRIVAL-TIME for process-[%d]:",i+1);
		scanf("%d",&P[i].arrival_time);
		P[i].process=i+1;
		P[i].refer=P[i].burst_time;
		P[i].status=0;
		b=b+P[i].burst_time;
	}
	
    for (i = 0; i < n-1; i++)   
	{
       for (j = 0; j < n-i-1; j++) 
	   { 
           if (P[j].refer < P[j+1].refer) 
           {
           	 temp=P[j].refer;
           	 P[j].refer=P[j+1].refer;
           	 P[j+1].refer=temp;
		   }
    	}
	}
   printf("\n---------------------------------------------PRIORITY_ALLOCATION---------------------------------------\n");
    printf("\n(NOTE:The process with lowest CPU burst is given the highest priority && if processes have same burst time then it follows FCFS && Higher priority has highest number)\n\n");
	for(i=0;i<n;i++)
	{	
	    for(j=0;j<n;j++)
	    {
			if(P[i].burst_time==P[j].refer)
			{
				P[i].priority=j+1;
			}
		}
	}
	printf("_____________________________________________________________________________________\n");
	printf("\n\tPROCESS\t\t   BURST-TIME\t\t   ARRIVAL-TIME\t\t   PRIORITY\n");
	printf("_____________________________________________________________________________________\n");
    for(i=0;i<n;i++)
	{
		printf("\n\tP-%d\t\t\t%d\t\t\t%d\t\t\t%d",P[i].process,P[i].burst_time,P[i].arrival_time,P[i].priority);	
	}	
	printf("\n_____________________________________________________________________________________\n");
	Check_Arrival_Time();
    Arrival_sort();
	P[9].priority=-9999;
	for(time=P[0].arrival_time;time<b;)
	 {
	 	largest=9;
	 	for(i=0;i<n;i++)
	 	{
	 		if(P[i].arrival_time<=time && P[i].status!=1 && P[i].priority>P[largest].priority)
	 		{
	 			largest=i;

			 }
		 }
		   
			 time=time+P[largest].burst_time;
			 P[largest].complete_time=time;
			 P[largest].waiting_time=P[largest].complete_time-P[largest].arrival_time-P[largest].burst_time;
			 P[largest].turnaround_time=P[largest].complete_time-P[largest].arrival_time;
			 P[largest].status=1;
			printf("\nthe process P%d completes in %d\n",P[largest].process,P[largest].complete_time);
			 TAT_sum=TAT_sum+P[largest].turnaround_time;
			 WT_sum=WT_sum+P[largest].waiting_time;
	}
	Process_sort();
	printf("\n---------------------------------------------TURNAROUND TIME & WAITING TIME---------------------------------------\n");
	printf("______________________________________________________________________\n");
	printf("\n\tPROCESS\t\tTURNAROUND-TIME\t\t	WAITING-TIME");
	printf("\n______________________________________________________________________");
    
	for(i=0;i<n;i++)
	{
		
		printf("\n\tP-%d\t\t\t%d\t\t\t%d",P[i].process,P[i].turnaround_time,P[i].waiting_time);

	}
	float AVG_TAT= (float)TAT_sum/n;
	float AVG_WT= (float)WT_sum/n;
	printf("\n______________________________________________________________________");
	printf("\n\nAVERAGE TURNAROUND_TIME IS :%f",AVG_TAT);
	printf("\nAVERAGE WAITING_TIME IS    :%f",AVG_WT);
	
	
}

void Process_sort()
{
    struct PriorityScheduling temp;
    int i, j;
    for(i = 0; i < n- 1; i++)
      {
            for(j = i + 1; j < n; j++)
            {
                  if(P[i].process > P[j].process)
                  {
                      temp =P[i];
                      P[i] =P[j];
                      P[j] = temp;
                  }
            }
      }
	
}

void Arrival_sort()
{
    struct PriorityScheduling temp;
    int i, j;
    for(i = 0; i < n- 1; i++)
      {
            for(j = i + 1; j < n; j++)
            {
                  if(P[i].arrival_time >P[j].arrival_time)
                  {
                        temp =P[i];
                       P[i] =P[j];
                      P[j] = temp;
                  }
            }
      }
}
int Check_Arrival_Time()
{
	int i,j;
	for (i = 0; i < n-1; i++)   
	{
       for (j = 0; j < n-i-1; j++) 
	   { 
           if (P[j].arrival_time == P[j+1].arrival_time) 
           {
           	  printf("\n\n\nHERE TWO OR MORE PROCESS ARE ARRIVING AT SAME TIME . (according to question)->NO CALCULATION OF TAT AND WT ");
           	  exit(0);
		   }
    	}
	}
}
