#include <stdio.h>

struct process {
    int pid;
    int bt, at, rt, ft, wt, tt;
};

int main() {
    printf("Aswin Dev SP 17\n\n");
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    struct process p[n], temp;

    printf("\nEnter the burst time and arrival time of each process:\n");
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        scanf("%d %d", &p[i].bt, &p[i].at);
        p[i].rt = p[i].bt;
    }

    printf("\nGantt Chart:\n");

    int time = 0, completed = 0;
    while(completed < n) {
        int flag = 0;
        for(int i = 0; i < n; i++) {
            if(p[i].rt > 0 && p[i].at <= time) {
                if(p[i].rt > quantum) {
                    time += quantum;
                    p[i].rt -= quantum;
                    printf("|   P%d    ", p[i].pid);
                } else {
                    time += p[i].rt;
                    p[i].rt = 0;
                    printf("|   P%d    ", p[i].pid);
                    p[i].ft = time;
                    p[i].tt = p[i].ft - p[i].at;
                    p[i].wt = p[i].tt - p[i].bt;
                    completed++;
                    flag = 1;
                }
            }
        }
        if(flag == 0) {
            time++;
        }
    }
    printf("|\n");

    printf("\n\nProcess ID\t Burst Time\t Arrival Time\t Waiting Time\t Turnaround Time\n");
    float avgWt = 0, avgTt = 0;
    for(int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i].pid, p[i].bt, p[i].at, p[i].wt, p[i].tt);
        avgWt += p[i].wt;
        avgTt += p[i].tt;
    }

    avgWt /= n;
    avgTt /= n;

    printf("Average Waiting Time = %.2f\n", avgWt);
    printf("Average Turnaround Time = %.2f\n", avgTt);
    return 0;
}