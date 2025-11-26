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

void	move_smallest_totop(t_stack *a)
{
	t_stack	*smallest;
	int	pos;

	smallest = find_smallest(a);
	pos = smallest->pos;
	if (a->median_flag)
		while (pos--)
			rra(a);
	else
		while (pos--)
			ra(a);
}

t_stack	*find_cheapest(t_stack *b)
{
	t_stack	*cheapest;

	cheapest = b;
	while (b->next)
	{
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
	}
	return (cheapest);
}
void	find_cheapest_and_moveto_top(t_stack *a, t_stack *b)
{
	t_stack	*b_node;
	int	pos;
	b_node = find_cheapest(b);	
	pos = b_node->pos;
	printf("cheapest: %d, pos: %d\n", b_node->x, pos);
	if (!b_node->target)
		move_smallest_totop(a);
	if (b_node->median_flag)
		while (pos--)
			rrb(b);
	else
		while (pos--)
			rb(b);
	if (b_node->target)
	{
		pos = b_node->target->pos;
		if (b_node->target->median_flag)
			while (pos--)
				rra(a);
		else
			while (pos--)
				ra(a);
	}
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
	if (a->x > a->next->x)
		sa(a);
	assign_pos(a);
	assign_pos(b);
	assign_target(a, b);
	find_cheapest_and_moveto_top(a, b);
	pa(&a, &b);
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
