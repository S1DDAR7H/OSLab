#include <stdio.h>

void main(){
    int i, j, n, temp, sum=0, sum2=0, bt[10], at[10], prio[10], p[10], rt[10], wt[10], tat[10];
    float avgwt, avgtat;
    printf("Enter Number of Processes:");
    scanf("%d", &n);
    printf("Enter Burst Time, Arrival Time and Priority:\n");
    for(i=0; i<n; i++){
        printf("P[%d]:", i+1);
        scanf("%d %d %d", &bt[i], &at[i], &prio[i]);
        p[i] = i+1;
        rt[i] = bt[i];
    }
    int completed=0, shortest=0, current_time=0,  min_priority=9999;
    while(completed != 0){
        for(i=0; i<n; i++){
            if(at[i] <= current_time && prio[i] < min_priority && rt[i] > 0){
                min_priority = prio[i];
                shortest = i;
            }
        }
        rt[shortest]--;
        if(rt[shortest] == 0){
            completed ++;
            min_priority = 9999;

            int finish_time = current_time + 1;
            tat[shortest] = finish_time - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            sum += wt[shortest];
            sum2 += tat[shortest];
        }
        current_time++;
    }
    avgwt = (float)sum/n;
    avgtat = (float)sum2/n;

    printf("\nProcess\tArrival\tBurst\tPriority\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], prio[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", avgtat);
    printf("\nAverage Waiting Time: %.2f\n", avgwt);
}
/*
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[n], burst_time[n], arrival_time[n], priority[n];
    int remaining_time[n], turnaround_time[n], waiting_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter priority for P%d: ", i + 1);
        scanf("%d", &priority[i]);
        remaining_time[i] = burst_time[i];
    }

    int current_time = 0, completed = 0, shortest = 0, min_priority = 9999;

    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= current_time && priority[i] < min_priority && remaining_time[i] > 0) {
                min_priority = priority[i];
                shortest = i;
            }
        }

        remaining_time[shortest]--;

        if (remaining_time[shortest] == 0) {
            completed++;
            min_priority = 9999;

            int finish_time = current_time + 1;
            turnaround_time[shortest] = finish_time - arrival_time[shortest];
            waiting_time[shortest] = turnaround_time[shortest] - burst_time[shortest];

            total_waiting_time += waiting_time[shortest];
            total_turnaround_time += turnaround_time[shortest];
        }

        current_time++;
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nProcess\tArrival\tBurst\tPriority\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", process[i], arrival_time[i], burst_time[i], priority[i], turnaround_time[i], waiting_time[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);

    return 0;
}
*/