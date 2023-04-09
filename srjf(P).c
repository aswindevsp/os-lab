#include <stdio.h>

struct process{
    int pid;
    int bt, at, rt, ft, wt, tt;
};


int main() {
    printf("Aswin Dev SP 17\n\n");
    int n;
    struct process p[20], temp;

    printf("Enter the number of process: ");
    scanf("%d", &n);


    printf("Enter the burst time and arrival time of each process: \n");
    for(int i=0; i<n; i++) {
        p[i].pid = i + 1;
        scanf("%d %d", &p[i].bt, &p[i].at);
        p[i].rt = p[i].bt;
    }


    printf("\nGantt Chart: \n");

    
    int minTime = __INT_MAX__, shortestPid;
    int time = 0, completed = 0;

    while(completed < n) {
        shortestPid  = -1;
        for(int i=0; i<n; i++) {
            if((p[i].at <= time) && (p[i].rt < minTime) && (p[i].rt > 0)) {
                minTime = p[i].rt;
                shortestPid = i;
            }
        }

       
        if(shortestPid == -1) {
            printf("|  IDLE   ");
        } else {
            minTime = --p[shortestPid].rt;

            if(minTime == 0) {
                minTime = __INT_MAX__;
            }
            printf("|   P%d    ", p[shortestPid].pid);

            if(p[shortestPid].rt == 0) {
                completed++;
                p[shortestPid].ft = time + 1;

                p[shortestPid].tt = p[shortestPid].ft - p[shortestPid].at;
                p[shortestPid].wt = p[shortestPid].tt - p[shortestPid].bt;
            }
        }
        time++;
    }
    printf("|\n");

    //finding the start time
    int startTime = __INT_MAX__;
    for(int i=0; i<n; i++) {
        if(p[i].at < startTime)
            startTime = p[i].at;
    }

    for(int i=startTime; i<=time+startTime; i++) {
        printf("%d         ", i);
    } 


    float avgWt, avgTt;
    printf("\n\nProcess ID\t Burst Time\t Arrival Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        avgWt = avgWt + p[i].wt;
        avgTt = avgTt + p[i].tt;

        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i].pid, p[i].bt, p[i].at, p[i].wt, p[i].tt);
    }

    avgWt/=n;
    avgTt/=n;

    printf("Average Waiting Time = %.2f\n", avgWt);
    printf("Average Turnaround Time = %.2f\n", avgTt);
}