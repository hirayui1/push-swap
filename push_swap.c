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
                printf("%d -> target: %d, pos: %d, med_flag: %d\n", next->x, target_val, next->pos, next->median_flag);
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

// median flag 0 means first half, 1 means later half
void assign_pos(t_stack *b)
{
	int	i;
	int	median;
	int	flag;
// if even number, might get last 2 pos being number 2
	i = 0;
	median = lstlen(b) / 2;
	flag = 1;
	while (b)
	{
		if (i > median)
			flag = 0;
		if (flag)
		{
			b->median_flag = 0;
			b->pos = i;
			i++;
		}
		else
		{
			b->median_flag = 1;
			i--;
			b->pos = i;
		}
		b = b->next;
	}
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
			if (target && (a->x < target->x && a->x > b->x))
				target = a;
			else if (!target && a->x > b->x)
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
		if (b->target)
		{
			if (cheapest->target)
			{
				if (b->pos + b->target->pos < cheapest->pos + cheapest->target->pos)
					cheapest = b;
			}
			else
				if (b->pos + b->target->pos < cheapest->pos)
					cheapest = b;
		}
		else
		{
			if (cheapest->target)
			{
				if (b->pos < cheapest->pos + cheapest->target->pos)
					cheapest = b;
			}
			else
				if (b->pos < cheapest->pos)
					cheapest = b;
		}
		b = b->next;
		// then come here and find assign_target(a, b
		// the smallest b->pos + b->target->pos possible
		// make sure to check if b->target->pos exists while doing this
		// and return it
	}
	return (cheapest);
}

void	find_cheapest_and_moveto_top(t_stack *a, t_stack *b)
{
	t_stack	*b_node;
	int	pos;
	b_node = find_cheapest(b);
	printf("ugh, %d, cheapest is %d and its target %d\n", a->x, b_node->x, b_node->target->x);
	pos = b_node->pos;
	printf("cheapest's pos is: %d\n", pos);
	if (b_node->median_flag)
		while (pos--)
			rrb(b);
	else
		while (pos--)
			rb(b);
	pos = b_node->target->pos;
	if (b_node->target->median_flag)
		while (pos--)
			rra(a);
	else
		while (pos--)
			ra(a);
}

void	greater_sort(t_stack *a)
{
	t_stack *b = 0;
	push_all_to_b(&a, &b, lstlen(a));
	tiny_sort(&a);
	while (lstlen(b) > 1)
	{
		assign_pos(a);
		assign_pos(b);
		assign_target(a, b);
		ll_printer(a, 'a');
		ll_printer(b, 'b');
		find_cheapest_and_moveto_top(a, b);
		pa(&a, &b);
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
