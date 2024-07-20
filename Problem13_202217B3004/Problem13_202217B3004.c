#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
} Node;

Node *new_node(int data)
{
	Node *temp;
	temp = malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node *insert(Node *root, int data)
{
	if (root == NULL)
	{
		return new_node(data);
	}
	else if (data > root->data)
	{
		root->right = insert(root->right, data);
	}
	else
	{
		root->left = insert(root->left, data);
	}
	return root;
}

Node *search(Node *root, int data)
{
	if (root == NULL || root->data == data)
	{
		return root;
	}
	else if (data > root->data)
	{
		return search(root->right, data);
	}
	else
	{
		return search(root->left, data);
	}
}

Node *find_minimum(Node *root)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (root->left != NULL)
	{
		return find_minimum(root->left);
	}
	return root;
}

Node *delete(Node *root, int data)
{

	if (root == NULL)
	{
		return NULL;
	}
	if (data > root->data)
	{
		root->right = delete (root->right, data);
	}
	else if (data < root->data)
	{
		root->left = delete (root->left, data);
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		else if (root->left == NULL || root->right == NULL)
		{
			Node *temp;
			if (root->left == NULL)
				temp = root->right;
			else
				temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			Node *temp = find_minimum(root->right);
			root->data = temp->data;
			root->right = delete (root->right, temp->data);
		}
	}
	return root;
}
void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf(" %d ", root->data);
		inorder(root->right);
	}
}

int main()
{
	Node *root;
	root = new_node(20);
	insert(root, 5);
	insert(root, 1);
	insert(root, 15);
	insert(root, 9);
	insert(root, 7);
	insert(root, 12);
	insert(root, 30);
	insert(root, 25);
	insert(root, 40);
	insert(root, 45);
	insert(root, 42);

	printf("\nInorder traversal: ");
	inorder(root);

	root = delete (root, 1);
	root = delete (root, 40);
	root = delete (root, 45);
	root = delete (root, 9);
	printf("\nInorder traversal after deletion: ");
	inorder(root);

	return 0;
}