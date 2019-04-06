#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
main()
{
	int n;
	printf("\n-------------------------------------PRIORITY_SCHEDULING--------------------------------------\n");
	printf("\nEnter number of process :");
	scanf("%d",&n);
	int burst_time[n],priority[n],temp,refer[n],p[n];
	for(int i=0;i<n;i++)
	{
	printf("\nEnter BURST-TIME for process-%d :",i+1);
	scanf("%d",&burst_time[i]);
	p[i]=i+1;
	refer[i]=burst_time[i];
	}
	
    for (int i = 0; i < n-1; i++)   
	{
       for (int j = 0; j < n-i-1; j++) 
	   { 
           if (refer[j] > refer[j+1]) 
           {
           	 temp=refer[j];
           	 refer[j]=refer[j+1];
           	 refer[j+1]=temp;
		   }
    	}
	}
    printf("\n--------------------PRIORITY-ALLOCATION-----------------------"); 
    printf("\n\n(NOTE:The process with lowest CPU burst is given the highest priority\nif processes have same burst time then it follows FCFS)\n\n");
	for(int i=0;i<=n;i++)
	{	
	    for(int j=0;j<n;j++)
	    {
			if(burst_time[i]==refer[j])
			{
				priority[i]=j+1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		   if(burst_time[i]==burst_time[i+j+1])
		  {
			   	priority[i]=priority[i]-1;
		  }	
		}
	}

	printf("______________________________________________________________\n");
	printf("\n\tPROCESS\t\t   BURST-TIME\t\t   PRIORITY\n");
	printf("______________________________________________________________\n");
    for(int i=0;i<n;i++)
	{
		printf("\n\tP-%d\t\t\t%d\t\t\t%d",p[i],burst_time[i],priority[i]);	
	}	 
	
}
