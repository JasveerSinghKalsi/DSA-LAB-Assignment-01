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

// like constructor
void setNode(Node *Node, char *key, char *value)
{
      Node->key = key;
      Node->value = value;
      Node->next = NULL;
      return;
}

typedef struct HashMap
{
      // Current number of elements in HashMap and capacity of HashMap
      int numOfElements, capacity;
      // hold base address array of linked list
      Node **arr;
} HashMap;

// like constructor
void initializeHashMap(HashMap *mp)
{
      // Default capacity in this case
      mp->capacity = 100;
      mp->numOfElements = 0;
      // array of size = 1
      mp->arr = (Node **)malloc(sizeof(Node *) * mp->capacity);
      return;
}

int hashFunction(HashMap *mp, char *key)
{
      int bucketIndex;
      int sum = 0, factor = 31;
      for (int i = 0; i < strlen(key); i++)
      {
            // sum = sum + (ascii value of char * (primeNumber ^ x))...where x = 1, 2, 3....n
            sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
            // factor = factor * primeNumber....(primeNumber) ^ x
            factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
      }
      bucketIndex = sum;
      return bucketIndex;
}

void insert(HashMap *mp, char *key, char *value)
{
      // Getting bucket index for the given key - value pair
      int bucketIndex = hashFunction(mp, key);
      Node *newNode = (Node *)malloc(sizeof(Node)); // Creating a new Node
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
            // Adding newNode at the head of linked list which is present at bucket index....insertion at head in linked list
            newNode->next = mp->arr[bucketIndex];
            mp->arr[bucketIndex] = newNode;
      }
      return;
}

void delete(HashMap *mp, char *key)
{
      // Getting bucket index for the given key
      int bucketIndex = hashFunction(mp, key);
      Node *prevNode = NULL;
      // Points to the head of linked list present at bucket index
      Node *currentNode = mp->arr[bucketIndex];
      while (currentNode != NULL)
      {
            // Key is matched at delete this Node from linked list
            if (strcmp(key, currentNode->key) == 0)
            {
                  // Head Node deletion
                  if (currentNode == mp->arr[bucketIndex])
                  {
                        mp->arr[bucketIndex] = currentNode->next;
                  }
                  // Last Node or middle Node
                  else
                  {
                        prevNode->next = currentNode->next;
                  }
                  free(currentNode);
                  break;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
      }
      return;
}

char *search(HashMap *mp, char *key)
{
      // Getting the bucket index for the given key
      int bucketIndex = hashFunction(mp, key);

      // Head of the linked list present at bucket index
      Node *bucketHead = mp->arr[bucketIndex];
      while (bucketHead != NULL)
      {
            // Key is found in the HashMap
            if (bucketHead->key == key)
            {
                  return bucketHead->value;
            }
            bucketHead = bucketHead->next;
      }

      // If no key found in the HashMap equal to the given key
      char *errorMessage = (char *)malloc(sizeof(char) * 25);
      errorMessage = "Oops! No data found.\n";
      return errorMessage;
}

// Drivers code
int main()
{
      // Initialize the value of mp
      HashMap *mp = (HashMap *)malloc(sizeof(HashMap));
      initializeHashMap(mp);
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