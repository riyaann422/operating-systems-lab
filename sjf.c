#include <stdio.h>
int main() {
int n, i, j;
int pid[10], bt[10], ct[10], tat[10], wt[10];
int total_wt = 0, total_tat = 0;

printf("Enter number of processes: ");
scanf("%d", &n);


for(i = 0; i < n; i++)
 {
pid[i] = i + 1;
printf("Burst time of P%d: ", pid[i]);
scanf("%d", &bt[i]);
}

for(i = 0; i < n - 1; i++)
 {
for(j = i + 1; j < n; j++)
 {
if(bt[i] > bt[j])
 {
int temp;
temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
}
}
}

ct[0] = bt[0];
tat[0] = ct[0];
wt[0] = 0;

total_tat += tat[0];
total_wt += wt[0];

for(i = 1; i < n; i++) 
{
ct[i] = ct[i - 1] + bt[i];
tat[i] = ct[i];
wt[i] = tat[i] - bt[i];

total_tat += tat[i];
total_wt += wt[i];
}


printf("\nPID\tBT\tCT\tTAT\tWT\n");

for(i = 0; i < n; i++) {
printf("P%d\t%d\t%d\t%d\t%d\n",
pid[i], bt[i], ct[i], tat[i], wt[i]);
}

printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);

return 0;
}
