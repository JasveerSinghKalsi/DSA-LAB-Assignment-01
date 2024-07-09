#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define n 5

void main()
{
	int queue[n], ch, front = 0, rear = 0, count;
	// clrscr();
	printf("Queue using Array");
	printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit");
	while (1)
	{
		printf("\nEnter the Choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			if (count == n)
				printf("\n Queue is Full");
			else
			{
				printf("\n Enter no %d:", count + 1);
				scanf("%d", &queue[rear++]);
				count++;
			}
			break;
		case 2:
			if (count == 0)
			{
				printf("\n Queue is empty");
			}
			else
			{
				printf("\n Deleted Element is %d", queue[front++]);
				count--;
			}
			break;
		case 3:
			printf("\n Queue Elements are:\n");
			if (count == 0)
				printf("\n Queue is Empty");
			else
			{
				for (int i = front; i < rear; i++)
				{
					printf(" %d\n", queue[i]);
				}
				break;
			}
		case 4:
			exit(0);
		default:
			printf("Wrong Choice: please see the options");
		}
	}
	getch();
}
