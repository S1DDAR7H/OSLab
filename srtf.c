#include <stdio.h>

#define MAX_PROCESSES 10

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[MAX_PROCESSES], arrival_time[MAX_PROCESSES], burst_time[MAX_PROCESSES];
    int remaining_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES], waiting_time[MAX_PROCESSES];
    int current_time = 0, completed = 0;

    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    while (completed != n) {
        int shortest = -1, min_burst = 9999;

        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= current_time && remaining_time[i] > 0 && remaining_time[i] < min_burst) {
                shortest = i;
                min_burst = remaining_time[i];
            }
        }

        if (shortest == -1) {
            current_time++;
            continue;
        }

        remaining_time[shortest]--;

        if (remaining_time[shortest] == 0) {
            completed++;

            int finish_time = current_time + 1;
            turnaround_time[shortest] = finish_time - arrival_time[shortest];
            waiting_time[shortest] = turnaround_time[shortest] - burst_time[shortest];
        }

        current_time++;
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
