#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List Node
typedef struct Node
{

	// key is string
	char *key;
	// value is also string
	char *value;
	struct Node *next;
} Node;

// like conor
void setNode(Node *Node, char *key, char *value)
{
	Node->key = key;
	Node->value = value;
	Node->next = NULL;
	return;
};

typedef struct Hashmap
{

	// Current number of elements in Hashmap
	// and capacity of Hashmap
	int numOfElements, capacity;
	// hold base address array of linked list
	Node **arr;
}Hashmap;

// like conor
void initializeHashmap(Hashmap *mp)
{
	// Default capacity in this case
	mp->capacity = 100;
	mp->numOfElements = 0;
	// array of size = 1
	mp->arr = (Node **)malloc(sizeof(Node *) * mp->capacity);
	return;
}

int hashFunction(Hashmap *mp, char *key)
{
	int bucketIndex;
	int sum = 0, factor = 31;
	for (int i = 0; i < strlen(key); i++)
	{
		// sum = sum + (ascii value of
		// char * (primeNumber ^ x))...
		// where x = 1, 2, 3....n
		sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;

		// factor = factor * prime
		// number....(prime
		// number) ^ x
		factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
	}
	bucketIndex = sum;
	return bucketIndex;
}

void insert(Hashmap *mp, char *key, char *value)
{
	// Getting bucket index for the given
	// key - value pair
	int bucketIndex = hashFunction(mp, key);
	Node *newNode = (Node *)malloc(

		// Creating a new Node
		sizeof(Node));
	// Setting value of Node
	setNode(newNode, key, value);
	// Bucket index is empty....no collision
	if (mp->arr[bucketIndex] == NULL)
	{
		mp->arr[bucketIndex] = newNode;
	}
	// Collision
	else
	{

		// Adding newNode at the head of
		// linked list which is present
		// at bucket index....insertion at
		// head in linked list
		newNode->next = mp->arr[bucketIndex];
		mp->arr[bucketIndex] = newNode;
	}
	return;
}

void delete(Hashmap *mp, char *key)
{
	// Getting bucket index for the
	// given key
	int bucketIndex = hashFunction(mp, key);
	Node *prevNode = NULL;
	// Points to the head of
	// linked list present at
	// bucket index
	Node *currNode = mp->arr[bucketIndex];
	while (currNode != NULL)
	{
		// Key is matched at delete this
		// Node from linked list
		if (strcmp(key, currNode->key) == 0)
		{
			// Head Node
			// deletion
			if (currNode == mp->arr[bucketIndex])
			{
				mp->arr[bucketIndex] = currNode->next;
			}
			// Last Node or middle Node
			else
			{
				prevNode->next = currNode->next;
			}
			free(currNode);
			break;
		}
		prevNode = currNode;
		currNode = currNode->next;
	}
	return;
}

char *search(Hashmap *mp, char *key)
{
	// Getting the bucket index
	// for the given key
	int bucketIndex = hashFunction(mp, key);

	// Head of the linked list
	// present at bucket index
	Node *bucketHead = mp->arr[bucketIndex];
	while (bucketHead != NULL)
	{
		// Key is found in the Hashmap
		if (bucketHead->key == key)
		{
			return bucketHead->value;
		}
		bucketHead = bucketHead->next;
	}

	// If no key found in the Hashmap
	// equal to the given key
	char *errorMssg = (char *)malloc(sizeof(char) * 25);
	errorMssg = "Oops! No data found.\n";
	return errorMssg;
}

// Drivers code
int main()
{
	// Initialize the value of mp
	Hashmap *mp = (Hashmap *)malloc(sizeof(Hashmap));
	initializeHashmap(mp);
	insert(mp, "Yogaholic", "Anjali");
	insert(mp, "pluto14", "Vartika");
	insert(mp, "elite_Programmer", "Manish");
	insert(mp, "GFG", "BITS");
	insert(mp, "decentBoy", "Mayank");

	printf("%s\n", search(mp, "elite_Programmer"));
	printf("%s\n", search(mp, "Yogaholic"));
	printf("%s\n", search(mp, "pluto14"));
	printf("%s\n", search(mp, "decentBoy"));
	printf("%s\n", search(mp, "GFG"));
	// Key is not inserted
	printf("%s\n", search(mp, "randomKey"));
	printf("\nAfter deletion : \n");
	// Deletion of key
	delete (mp, "decentBoy");
	printf("%s\n", search(mp, "decentBoy"));
	return 0;
}