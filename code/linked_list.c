
```c void insertAtBeginning(LinkedList *list, int data)
{
	Node	*newNode;

	newNode = createNode(data);
	if (list->head == NULL)
	{
		list->head = newNode;
		list->tail = newNode;
	}
	else
	{
		newNode->next = list->head;
		list->head = newNode;
		list->tail->next = newNode;
		list->tail = newNode;
	}
}
```

	2. *
	*Deletion ** : To delete a node from the list,
	we need to update both the head and tail pointers.

    ```c void deleteNode(LinkedList *list, int data)
{
	Node	*temp;
	Node	*prevNode;
	Node	*temp;

	if (list->head == NULL)
		return ;
	// Check if the node to be deleted is head node
	if (list->head->data == data)
	{
		temp = list->head;
		list->head = list->head->next;
		free(temp);
		if (list->head == NULL)
			list->tail = NULL;
		return ;
	}
	prevNode = list->head;
	while (prevNode->next != NULL)
	{
		if (prevNode->next->data == data)
		{
			temp = prevNode->next;
			prevNode->next = prevNode->next->next;
			free(temp);
			if (prevNode->next == NULL)
				list->tail = prevNode;
			return ;
		}
		prevNode = prevNode->next;
	}
	// If no such node found
	printf("Element not found in Linked List\n");
}

void	traverse(LinkedList *list)
{
	Node	*temp;

	temp = list->head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

/*Example Usage*/

int	main(void)
{
	LinkedList	list;

	// Creating a new linked list
	list.head = NULL;
	list.tail = NULL;
	// Appending elements to the list
	append(&list, 10);
	append(&list, 20);
	append(&list, 30);
	// Printing the linked list
	printf("Linked List: ");
	traverse(&list);
	// Inserting a new element at the beginning of the list
	insertAtBeginning(&list, 5);
	// Printing the updated linked list
	printf("\nUpdated Linked List: ");
	traverse(&list);
	// Deleting an element from the list
	deleteNode(&list, 20);
	// Printing the updated linked list
	printf("\nAfter deletion\n");
	traverse(&list);
	return (0);
}
