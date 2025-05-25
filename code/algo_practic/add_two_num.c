#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct				ListNode
{
	int				val;
	struct ListNode	*next;
};

struct ListNode	*new_node(struct ListNode *new)
{
	struct ListNode	*node;

	node = malloc(sizeof(new) * 8);
	return (node);
}

struct ListNode	*addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode	*arr;
	int				tmp;

	tmp = 0;
	arr = malloc(sizeof(struct ListNode) * 100);
	while (l1->next != NULL || l2->next != NULL)
	{
		arr->val = l1->val + l2->val;
		if (arr->val > 9)
		{
			tmp = arr->val % 10;
			arr->val = l1->next->val + l2->next->val + tmp;
		}
		l1 = l1->next;
		l2 = l2->next;
		arr = arr->next;
	}
	return (arr);
}

int	main(void)
{
	new_node(l1);
	new_node(l2);
	new_node(result);
	l1->val = 2;
	l1->next->val = 4;
	l1->next->next->val = 3;
	l2->val = 2;
	l2->next->val = 4;
	l2->next->next->val = 3;
	l2->val = 5;
	l2->val = 6;
	l2->val = 4;
	result = addTwoNumbers(l1, l2);
	while (result->next != NULL)
	{
		printf("%d", result->val);
		result = result->next;
	}
	return (0);
}
