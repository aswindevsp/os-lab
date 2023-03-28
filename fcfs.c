#include<stdio.h>

void printLines(int n) {
	printf("\n");
	for(int i=0; i<n; i++) 
		printf("----------------");
		
	printf("\n");
}
void main() {

    int wt[20], bt[20], tt[20], n;
    float wt_avg = 0, tt_avg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", & n);
    printf("\nEnter the burst time of each process:\n");

    for (int i = 0; i < n; i++) 
    {
        printf("P%d: ", i + 1);
        scanf("%d", & bt[i]);
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
        printf("P%d\t\t\t%d\t\t\t%d\t\t\t%d\n", i + 1, bt[i], wt[i], tt[i]);
    }
    printf("\nAverage Waiting Time: %f", wt_avg);
    printf("\nAverage Turnaround Time: %f\n", tt_avg);
    printf("\n\t\tGantt Chart\n");
    printLines(n);
    
    for (int i = 0; i < n; i++) 
    {
        printf("|\tP%d\t|", i + 1);
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
P1: 2
P2: 3
P3: 4

Process		 Burst Time		 Waiting Time		 Turnaround Time
P1			2			0			2
P2			3			2			5
P3			4			5			9

Average Waiting Time: 2.333333
Average Turnaround Time: 5.333333

		Gantt Chart

------------------------------------------------
|	P1	||	P2	||	P3	|
------------------------------------------------
0	 	2	 	5	 	9
------------------------------------------------

*/

