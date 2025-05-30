#include <stdio.h>
#include <stdlib.h>

// Node structure
struct			Node
{
	int			data;
	struct Node	*next;
};

// Function to create a new node
struct Node	*createNode(int data)
{
	struct Node	*newNode;

	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return (newNode);
}

// Function to insert at beginning of a linked list
void	insertAtBeginning(struct Node **head, int data)
{
	struct Node	*newNode;

	newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}

// Function to display a linked list
void	displayList(struct Node *head)
{
	while (head != NULL)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	int			arraySize;
		arraySize = 5;

	struct Node	*listArray[arraySize];

	// Method 1: Array of pointers to linked list heads
	// Initialize all lists to NULL
	for (int i = 0; i < arraySize; i++)
	{
		listArray[i] = NULL;
	}
	// Add elements to different lists
	insertAtBeginning(&listArray[0], 10);
	insertAtBeginning(&listArray[0], 20);
	insertAtBeginning(&listArray[0], 30);
	insertAtBeginning(&listArray[1], 40);
	insertAtBeginning(&listArray[1], 50);
	insertAtBeginning(&listArray[2], 60);
	// Display all lists
	printf("Array of Linked Lists:\n");
	for (int i = 0; i < arraySize; i++)
	{
		printf("List %d: ", i);
		if (listArray[i] != NULL)
		{
			displayList(listArray[i]);
		}
		else
		{
			printf("Empty\n");
		}
	}
	// Method 2: Dynamic allocation
	printf("\nDynamic Array of Linked Lists:\n");
	struct Node **dynamicArray =
		(struct Node **)malloc(arraySize * sizeof(struct Node *));
	// Initialize
	for (int i = 0; i < arraySize; i++)
	{
		dynamicArray[i] = NULL;
	}
	// Add some data
	insertAtBeginning(&dynamicArray[0], 100);
	insertAtBeginning(&dynamicArray[0], 200);
	// Display
	for (int i = 0; i < arraySize; i++)
	{
		printf("Dynamic List %d: ", i);
		if (dynamicArray[i] != NULL)
		{
			displayList(dynamicArray[i]);
		}
		else
		{
			printf("Empty\n");
		}
	}
	// Free memory (simplified - should free all nodes in each list)
	free(dynamicArray);
	return (0);
}
