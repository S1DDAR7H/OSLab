
#include <stdio.h>

#define MAX_PROCESSES 10

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[MAX_PROCESSES], arrival_time[MAX_PROCESSES], burst_time[MAX_PROCESSES];
    int remaining_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES], waiting_time[MAX_PROCESSES];
    int time_quantum;

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    int current_time = 0, completed = 0;

    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= current_time && remaining_time[i] > 0) {
                if (remaining_time[i] <= time_quantum) {
                    current_time += remaining_time[i];
                    turnaround_time[i] = current_time - arrival_time[i];
                    waiting_time[i] = turnaround_time[i] - burst_time[i];
                    remaining_time[i] = 0;
                    completed++;
                } else {
                    current_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
            }
        }
    }

    float total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", process[i], turnaround_time[i], waiting_time[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);

    return 0;
}
