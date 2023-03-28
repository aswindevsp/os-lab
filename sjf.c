#include<stdio.h>

void printLines(int n) {
	printf("\n");
	for(int i=0; i<n; i++) 
		printf("----------------");
		
	printf("\n");
}
void main() {

    int wt[20], bt[20], tt[20], n, p[20];
    float wt_avg = 0, tt_avg = 0;
    int temp;

    printf("Enter the number of processes: ");
    scanf("%d", & n);
    printf("\nEnter the burst time of each process:\n");

    for (int i = 0; i < n; i++) 
    {
        printf("P%d: ", i + 1);
        scanf("%d", & bt[i]);
        p[i] = i+1;
    }
    
    for(int i=0;i<n-1;i++) 
    {
    	for(int j=0;j<n-i-i;j++)
    	{	 
            if(bt[j]>bt[j+1])
            {
	          temp=p[j];
                  p[j]=p[j+1];
                  p[j+1]=temp;

                  temp=bt[j];
                  bt[j]=bt[j+1];
                  bt[j+1]=temp;
            }
       }
    }
    wt[0] = 0;
    
    for (int i = 1; i < n; i++) 
    {
        wt[i] = bt[i - 1] + wt[i - 1];
        wt_avg += wt[i];
    }
    
    wt_avg /= n;
    
    for (int i = 0; i < n; i++) 
    {
        tt[i] = wt[i] + bt[i];
        tt_avg += tt[i];
    }
    tt_avg /= n;
    
    printf("\nProcess\t\t Burst Time\t\t Waiting Time\t\t Turnaround Time\n");

    for (int i = 0; i < n; i++) 
    {
        printf("P%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i], bt[i], wt[i], tt[i]);
    }
    printf("\nAverage Waiting Time: %f", wt_avg);
    printf("\nAverage Turnaround Time: %f\n", tt_avg);
    printf("\n\t\tGantt Chart\n");
    printLines(n);
    
    for (int i = 0; i < n; i++) 
    {
        printf("|\tP%d\t|", p[i]);
    }
    printLines(n);
    
    for (int i = 0; i < n; i++) 
    {
        printf("%d\t \t", wt[i]);
    }
    
    printf("%d", tt[n - 1]);
    printLines(n);
}



/*
Enter the number of processes: 3

Enter the burst time of each process:
P1: 9
P2: 1
P3: 4

Process		 Burst Time		 Waiting Time		 Turnaround Time
P2			1			0			1
P3			4			1			5
P1			9			5			14

Average Waiting Time: 2.000000
Average Turnaround Time: 6.666667

		Gantt Chart

------------------------------------------------
|	P2	||	P3	||	P1	|
------------------------------------------------
0	 	1	 	5	 	14
------------------------------------------------

*/
