#include <stdio.h>

void main(){
    int bt[10], tat[10], wt[10], n, i, j, temp;
    printf("Enter Number of Processes:");
    scanf("%d", &n);
    printf("Enter Burst Time for each Process:\n");
    for(i=0; i<n; i++){
        printf("P[%d]:", i+1);
        scanf("%d", &bt[i]);
    }
    //calucalte waiting time
    wt[0] = 0;
    for(i=1; i<n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }
    //calucalte turn around time
    tat[0] = bt[0];
    for(i=1; i<n; i++){
        tat[i] = bt[i] + wt[i];
    }
    //calculate average waiting time
    int sum1 = 0;
    for(i=0; i<n; i++){
        sum1 += wt[i];
    }
    float avg_wt = (float)sum1/n;
    //calculate average tat time
    sum1 = 0;
    for(i=0; i<n; i++){
        sum1 += tat[i];
    }
    float avg_tat = (float)sum1/n;
    //print all the values
    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0; i<n; i++){
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %f\n", avg_wt);
    printf("Average Turn Around Time: %f\n", avg_tat);
}