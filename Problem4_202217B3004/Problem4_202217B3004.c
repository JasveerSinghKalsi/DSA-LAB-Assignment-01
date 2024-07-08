#include <stdio.h>

// C recursive function to solve tower of hanoi puzzle

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n == 1)
	{
		printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
		return;
	}
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
	int numDisks;
	printf("Enter the number of disks: ");
	scanf("%d", &numDisks);

	if (numDisks > 0)
	{
		towerOfHanoi(numDisks, 'A', 'C', 'B'); // A, B and C are names of rods
	}
	else
	{
		printf("Invalid number of disks. Please enter a positive number.\n");
	}
	return 0;
}