#include<stdio.h>
#include<conio.h>
int main()
{
  printf("----------------------- CSE316 ASSIGNMENT-----------------------\n");
  printf("-----------------------  CPU Scheduling  -----------------------\n\n");
  long int n,i=0,j=0;
  printf("Enter Number of Processes : ");
  scanf("%ld",&n );
  double priority[n],avg_waiting,avg_turnaround,burstTime[n],arrivalTime[n],waitingTime[n],turnaroundTime[n], process[n], temp, completionTime[n],min,sum=0,sum2=0,wait_final, turnaround_final, wait_avg, turnaround_avg;
  for(i=0;i<n;i++)
  {
  	printf("\nEnter Arrival Time for Process [%d] : ", i+1 );
    scanf("%lf", &arrivalTime[i] );
    printf("Enter Burst Time for Process [%d] : ", i+1 );
    scanf("%lf", &burstTime[i]);
    process[i]=i+1;
  }

  printf("\n\n -------------- Entered Values are --------------\n\n");
  printf(" ---------------------------------------\n");
  printf(" | Process | Arrival Time | Burst Time |\n");
  printf("---------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf(" |  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",process[i],arrivalTime[i],burstTime[i]);
  }
  printf(" ---------------------------------------\n");
  printf("\n\n -------- Sorting Processes according to Arrivaltime --------\n");
  /*Arranging the table according to Arrival time*/

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(arrivalTime[i]<arrivalTime[j])
      {

        temp = burstTime[j];
        burstTime[j] = burstTime[i];
        burstTime [i] = temp;

	      temp = process[j];
        process[j] = process[i];
        process[i] = temp;

	      temp = arrivalTime[j];
        arrivalTime[j] = arrivalTime[i];
        arrivalTime[i] = temp;

      }
    }
  }
  printf(" ---------------------------------------\n");
  printf(" | Process | Arrival Time | Burst Time |\n");
  printf(" ---------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf(" |  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",process[i],arrivalTime[i],burstTime[i]);
  }
    printf(" ---------------------------------------\n");


/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/


  long int k = 1;
  double b_time = 0;
  for(j=0;j<n;j++)
  {
    b_time = b_time + burstTime[j];
    min = burstTime[k];

    for(i=k;i<n;i++)
    {
      if((b_time >= arrivalTime[i])&&(burstTime[i]<min))
      {
        temp = burstTime[k];
        burstTime[k] = burstTime[i];
        burstTime[i] = temp;

        temp = arrivalTime[k];
        arrivalTime[k] = arrivalTime[i];
        arrivalTime[i] = temp;

        temp = process[k];
        process[k] = process[i];
        process[i] = temp;
      }
    }
    k++;
  }
  waitingTime[0] = 0;
  for(i=1;i<n;i++)
  {
    sum += burstTime[i-1];
    waitingTime[i] = sum - arrivalTime[i];
    wait_final += waitingTime[i];
  }
  wait_avg = wait_final/n;
  for(i=0;i<n;i++)
  {
    sum2 += burstTime[i];
    turnaroundTime[i] = sum2 - arrivalTime[i];
    turnaround_final += turnaroundTime[i];
  }
  turnaround_avg=turnaround_final/n;
printf("\n  -------------- Values without Priority --------------\n\n");
  printf(" -----------------------------------------------------------------------------\n");
  printf(" | Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
  printf(" -----------------------------------------------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf(" |  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[i],arrivalTime[i],burstTime[i],waitingTime[i],turnaroundTime[i]);
  }
    printf(" -----------------------------------------------------------------------------\n");



  /*Now we have to prioritize the processes according to the formulae
      Priority = 1+ Waiting time / Estimated run time
  */


  completionTime[0] = burstTime[0];
  for(i=1;i<n;i++)
  {
    completionTime[i] = completionTime[i-1] + burstTime[i];
  }

  for(i=0;i<n;i++)
  {
    priority[i] = 1+waitingTime[i]/completionTime[i];
}
    printf("\n ---- Priority of Process after calculation ----\n\n");
    printf(" -----------------------\n");
    printf(" | Process | Priority  |\n");
    printf(" -----------------------\n");
  for(i=0;i<n;i++)
  {
    printf(" |  P[%0.0lf]  |  %lf |\n ",process[i],priority[i]);
  }
    printf(" ----------------------\n");
    


  printf("\n\n  -------------- Final Result with Priority --------------\n\n");
  printf(" -----------------------------------------------------------------------------\n");
  printf(" | Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
  printf(" -----------------------------------------------------------------------------\n");
  printf(" |  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[0],arrivalTime[0],burstTime[0],waitingTime[0],turnaroundTime[0]);
  for(i=n-1;i>0;i--)
  {
    printf(" |  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[i],arrivalTime[i],burstTime[i],waitingTime[i],turnaroundTime[i]);
  }
    printf(" -----------------------------------------------------------------------------\n");

  printf("\n\n\n Average Turn Around Time : %lf",turnaround_avg);
  printf("\n Average Waiting Time     : %lf\n\n",wait_avg);

  getch();
  return 0;
}
