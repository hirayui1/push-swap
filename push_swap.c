#include "push_swap.h"

void    ll_printer(t_stack *next, char c)
{
	int target_val;
        printf("%c\n-\n", c);
        while (next)
        {
		if (next->target)
			target_val = next->target->x;
		else
			target_val = -1;
                printf("%d -> target: %d\n", next->x, target_val);
                next = next->next;
        }
}

void	push_all_to_b(t_stack **a, t_stack **b, int len)
{
	//ll_printer(*a, 'a');
	//printf("len: %d\n", len);
	while (len-- > 3)
		pb(b, a);
}

void assign_target(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*tmp;

	tmp = a;
	while (b)
	{
		a = tmp;
		target = 0;
		while (a)
		{
			if ((target && (target->x > a->x && a->x > b->x)) || a->x > b->x)
				target = a;
			a = a->next;
		}
		b->target = target;
		b = b->next;
	}
}

t_stack	*find_cheapest(t_stack *b)
{
	t_stack	*cheapest;

	cheapest = b;
	while (b->next)
	{
		// in order to start implementing this
		// go to push_swap.h and add int pos
		//
		// then come here and find 
		// the smallest b->pos + b->target->pos possible
		// make sure to check if b->target->pos exists while doing this
		// and return it
	}
}

void	find_cheapest_and_moveto_top(t_stack *a, t_stack *b)
{
	t_stack	*b_node;

	b_node = find_cheapest(b);
}

void	greater_sort(t_stack *a)
{
	t_stack *b = 0;
	push_all_to_b(&a, &b, lstlen(a));
	while (lstlen(b) > 1)
	{
		assign_target(a, b);
		find_cheapest_and_moveto_top(a, b);
	}
	ll_printer(a, 'a');
	ll_printer(b, 'b');
}

int	push_swap(t_stack *a)
{
	if (lstlen(a) <= 3)
		tiny_sort(&a);
	else
		greater_sort(a);
	return (0);
}

/*
int	test_rules(t_stack *a)
{
	t_stack	*b;
	b = 0;
	ll_printer(a, 'a');
	swap(a);
	printf("swap:\n");
	ll_printer(a, 'a');
	printf("push:\n");
	push(&b, &a);
	ll_printer(a, 'a');
	ll_printer(b, 'b');
	printf("add to end:\n");
	lstadd_last(&a, 9);
	lstadd_last(&b, 8);
	ll_printer(a, 'a');
	ll_printer(b, 'b');
	printf("rotate:\n");
	rotate(a);
	ll_printer(a, 'a');
	printf("reverse rotate:\n");
	reverse_rotate(a);
	ll_printer(a, 'a');
	printf("rotate both:\n");
	rotate_both(a, b);
	ll_printer(a, 'a');
	ll_printer(b, 'b');
	printf("reverse rotate both:\n");
	reverse_rotate_both(a, b);
	ll_printer(a, 'a');
	ll_printer(b, 'b');
	lstdestroy(a);
	lstdestroy(b);
	return (1);
}
*/
