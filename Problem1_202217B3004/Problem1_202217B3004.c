#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/* Define the required functions to create a list, insert into the list,
delete an element from the list, search and display the list */

void create();
void deletion();
void search();
void insert();
void display();

int a, b[MAX], n, p, e, f, i, pos;

void main()
{
	// clrscr();
	int ch;
	char g = 'y';
	do
	{
		printf("\nMain Menu\n");
		printf("\n1.Create \n2.Delete\n3.Search\n4.Insert\n5.Display\n6.Exit\n");
		printf("\nEnter your Choice: ");
		scanf("%d", &ch);
		// The following switch will call the appropriate choice provided by the user
		switch (ch)
		{
		case 1:
			create();
			break;
		case 2:
			deletion();
			break;
		case 3:
			search();
			break;
		case 4:
			insert();
			break;
		case 5:
			display();
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("\nEnter the correct choice:::");
			continue;
		}
		getchar();
		printf("\nDo u want to continue: (y/n)");
		scanf("%c", &g);
	}
	// The program is intended to run till we provide inputs other ‘y’ or ‘Y’
	while (g == 'y' || g == 'Y');
	getchar();
}

void create()
{
	printf("\n Enter the number of nodes: ");
	scanf("%d", &n);
	// The loop runs till we get ‘n’ inputs
	for (i = 0; i < n; i++)
	{
		{
			printf("\n Enter Element %d: ", (i + 1));
			scanf("%d", &b[i]);
		}
	}
}

void deletion()
{
	if (n == 0)
	{
		printf("\n The list is empty:::");
	}
	else
	{
		printf("\n Enter the position u want to delete::");
		scanf("%d", &pos);
		if (pos >= n)
		{
			printf("\n Invalid Location:::");
		}
		else
		{
			for (i = pos + 1; i < n; i++)
			{
				b[i - 1] = b[i]; // Shift the elements to the left
			}
			n--; // Decrement the number of elements
		}
		printf("\n The Elements after deletion: ");
		display();
	}
}

void search()
{
	printf("\n Enter the Element to be searched: ");
	scanf("%d", &e);
	f = 0; // Initialize to not found

	for (i = 0; i < n; i++)
	{
		if (b[i] == e)
		{
			f = 1; // Set to true if found
			p = i; // Store the position of the element
			break;
		}
	}

	if (f)
	{
		printf("\n Value is at Position %d\n", p);
	}
	else
	{
		printf("\n Value %d is not found in the list:::\n", e);
	}
}

void insert()
{
	printf("\n Enter the position u need to insert: ");
	scanf("%d", &pos);
	if (n >= MAX)
	{
		printf("\n List is Full:::");
		return;
	}
	else if (pos > n || pos < 0)
	{
		printf("\n Invalid Location:::");
		return;
	}
	else
	{
		for (i = n; i >= pos; i--)
		{
			b[i + 1] = b[i]; // Shift the elements to the right
		}
		printf("\n Enter the element to insert: ");
		scanf("%d", &p);
		b[pos] = p; // Insert the element at the specified position
		n++;
	}
	printf("\n The list after insertion: ");
	display();
}

void display()
{
	printf("\n The Elements of The list ADT are: ");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", b[i]);
	}
}