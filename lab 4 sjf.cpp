#include <stdio.h>

int main() {
    int n, i, j, temp, completed = 0, current_time = 0;
    int pid[20], at[20], bt[20], ct[20], tat[20], wt[20], visited[20] = {0};
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time and Burst Time for process %d: ", i + 1);
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
    }

    printf("\nGantt Chart:\n|");

    while (completed != n) {
        int min_bt = 1e9, min_index = -1;
        for (i = 0; i < n; i++) {
            if (!visited[i] && at[i] <= current_time && bt[i] < min_bt) {
                min_bt = bt[i];
                min_index = i;
            }
        }

        if (min_index == -1) {
            current_time++;
            continue;
        }

        visited[min_index] = 1;
        ct[min_index] = current_time + bt[min_index];
        tat[min_index] = ct[min_index] - at[min_index];
        wt[min_index] = tat[min_index] - bt[min_index];
        avg_wt += wt[min_index];
        avg_tat += tat[min_index];

        printf("  P[%d]  |", pid[min_index]);

        current_time = ct[min_index];
        completed++;
    }

    printf("\n0");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (ct[j] != 0) {
                printf("     %d", ct[j]);
                ct[j] = 0;  // reset so we don't repeat
                break;
            }
        }
    }

    printf("\n\nPID\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}

