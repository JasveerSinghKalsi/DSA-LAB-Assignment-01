#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10

int main()
{
	int n, a[MAX], b[MAX], t[MAX], w[MAX], g[MAX], i, m;
	float att = 0, awt = 0;

	for (i = 0; i < MAX; i++)
	{
		a[i] = 0;
		b[i] = 0;
		w[i] = 0;
		g[i] = 0;
	}

	printf("Enter the number of process: ");
	scanf("%d", &n);
	if (n > MAX || n <= 0)
	{
		printf("Invalid number of processes. Please enter a value between 1 and %d.\n", MAX);
		return 1;
	}

	printf("Enter the burst times:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}

	printf("\nEnter the arrival times:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	g[0] = a[0] + b[0];
	for (i = 1; i < n; i++)
	{
		g[i] = g[i - 1] + b[i];
	}

	for (i = 0; i < n; i++)
	{
		w[i] = g[i] - a[i] - b[i];
		t[i] = g[i] - a[i];
		awt += w[i];
		att += t[i];
	}

	awt /= n;
	att /= n;

	printf("\n\tProcess\t\tWaiting time\tTurn around time\n");
	for (i = 0; i < n; i++)
	{
		printf("\t p%d \t\t %d \t\t %d\n", i, w[i], t[i]);
	}

	printf("The average waiting time is %f\n", awt);
	printf("The average turn around time is %f\n", att);

	return 0;
}