#include <stdio.h>

void main(){
    int n, i, j, bt[10], tat[10], wt[10], p[10], sum=0, sum2=0;
    float avgtat, avgwt;
    printf("Enter Number of Processes:");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter Burst Time:");
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }
    int temp;
    for(i=0; i<n; i++){
        for(j=0; j<n-1; j++){
            if(bt[j] > bt[j+1]){
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0; j<i; j++){
            wt[i] += bt[j];
        }
        sum += wt[i];
    }
    avgwt = (float)sum/n;
    for(i=0; i<n; i++){
        tat[i] = wt[i] + bt[i];
        sum2 += tat[i];
    }
    avgtat = (float)sum2/n;
    printf("Process\tBT\tWT\tTAT\n");
    for(i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
}