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
