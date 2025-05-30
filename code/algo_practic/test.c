#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// ...existing code...
struct ListNode	*addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode	dummy;
	struct ListNode	*tail;
	int				carry;
	int				sum;

	tail = &dummy;
	carry = 0;
	dummy.next = NULL;
	while (l1 != NULL || l2 != NULL || carry)
	{
		sum = carry;
		if (l1)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		tail->next = new_node(sum % 10);
		tail = tail->next;
		carry = sum / 10;
	}
	return (dummy.next);
}
// ...existing code...

int	main(void)
{
	struct ListNode	*l1;
	struct ListNode	*l2;
	struct ListNode	*result;

	l1 = new_node(2);
	l1->next = new_node(4);
	l1->next->next = new_node(3);
	l2 = new_node(5);
	l2->next = new_node(6);
	l2->next->next = new_node(4);
	result = addTwoNumbers(l1, l2);
	while (result != NULL)
	{
		printf("%d -> ", result->val);
		result = result->next;
	}
	// 	printf("NULL\n");
	return (0);
}
// ...existing code...
