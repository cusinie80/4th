#include <stdio.h>

int main() {
    int n, i, t = 0, completed = 0, shortest = -1;
    int pid[20], at[20], bt[20], rt[20], ct[20], tat[20], wt[20];
    int is_completed[20] = {0};
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time and Burst Time for process %d: ", i + 1);
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int prev = -1;
    printf("\nGantt Chart:\n|");

    while (completed != n) {
        int min_rt = 1e9;
        shortest = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            t++;
            continue;
        }

        if (shortest != prev) {
            printf(" P[%d] |", pid[shortest]);
        }
        rt[shortest]--;
        t++;
        prev = shortest;

        if (rt[shortest] == 0) {
            completed++;
            ct[shortest] = t;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            avg_wt += wt[shortest];
            avg_tat += tat[shortest];
        }
    }

    printf("\n\nPID\tAT\tBT\tWT\tTAT\tCT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i], ct[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}

