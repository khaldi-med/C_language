#include <stdio.h>
#include <stdlib.h>

struct				ListNode
{
	int				val;
	struct ListNode	*next;
};

struct ListNode	*new_node(int data)
{
	struct ListNode	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->val = data;
	new->next = NULL;
	return (new);
}

struct ListNode	*addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode	*arr;
	int				tmp;
	struct ListNode	*tmp_node;
	int				sum;
	struct ListNode	*result;

	arr = malloc(sizeof(struct ListNode));
	if (arr == NULL)
		return (NULL);
	arr->val = 0;
	arr->next = NULL;
	tmp_node = arr;
	tmp = 0;
	while (l1 != NULL || l2 != NULL || tmp != 0)
	{
		sum = tmp;
		if (l1)
			sum += l1->val;
		if (l2)
			sum += l2->val;
		tmp = sum / 10;
		tmp_node->next = malloc(sizeof(struct ListNode));
		if (tmp_node->next == NULL)
			return (NULL);
		if (l1)
			l1 = l1->next;
		if (l2)
			l2 = l2->next;
		tmp_node->next->val = sum % 10;
		tmp_node->next->next = NULL;
		tmp_node = tmp_node->next;
	}
	result = arr->next;
	free(arr);
	return (result);
}

int	main(void)
{
	struct ListNode	*l1;
	struct ListNode	*l2;
	struct ListNode	*result;
	struct ListNode	*curr;

	l1 = new_node(2);
	l1->next = new_node(4);
	l1->next->next = new_node(3);
	l2 = new_node(5);
	l2->next = new_node(6);
	l2->next->next = new_node(4);
	result = addTwoNumbers(l1, l2);
	printf("Result: ");
	curr = result;
	while (curr != NULL)
	{
		printf("%d", curr->val);
		if (curr->next != NULL)
			printf(" -> ");
		curr = curr->next;
	}
	printf("\n");
	while (result != NULL)
	{
		curr = result;
		result = result->next;
		free(curr);
	}
	while (l1 != NULL)
	{
		curr = l1;
		l1 = l1->next;
		free(curr);
	}
	while (l2 != NULL)
	{
		curr = l2;
		l2 = l2->next;
		free(curr);
	}
	return (0);
}
