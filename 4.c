#include <stdio.h>

int main() {
    int n, i, j;
    int pid[20], at[20], bt[20], ct[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time and Burst Time for process %d: ", i + 1);
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
    }

    // Sort by arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                int tmp;
                tmp = pid[i]; pid[i] = pid[j]; pid[j] = tmp;
                tmp = at[i]; at[i] = at[j]; at[j] = tmp;
                tmp = bt[i]; bt[i] = bt[j]; bt[j] = tmp;
            }
        }
    }

    int current_time = 0;
    printf("\nGantt Chart:\n|");

    for (i = 0; i < n; i++) {
        if (current_time < at[i]) {
            printf("  -  |"); // CPU is idle
            current_time = at[i];
        }
        printf("  P%d  |", pid[i]);
        current_time += bt[i];
        ct[i] = current_time;
    }

    // Print timeline below Gantt
    printf("\n0");
    current_time = 0;
    for (i = 0; i < n; i++) {
        if (current_time < at[i]) {
            printf("     %d", at[i]);
            current_time = at[i];
        }
        current_time += bt[i];
        printf("     %d", current_time);
    }

    // Calculate turnaround time and waiting time
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}

