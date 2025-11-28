#include "push_swap.h"

void	move_smallest_totop(t_stack *a)
{
	t_stack	*smallest;
	int	pos;

	smallest = find_smallest(a);
	assign_pos(a);
	pos = smallest->pos;
	if (smallest->median_flag)
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
			if (cheapest->target && b->pos + b->target->pos < cheapest->pos + cheapest->target->pos)
					cheapest = b;
			else if (b->pos + b->target->pos < cheapest->pos)
				cheapest = b;
		}
		else
		{
			if (cheapest->target && b->pos < cheapest->pos + cheapest->target->pos)
					cheapest = b;
			else if (b->pos < cheapest->pos)
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
	if (!b_node->target)
		move_smallest_totop(a);
	pos = b_node->pos;
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

// this should run when only 1 element is left in stack b
// the idea is to: move smallest to top->check if last node has target
// ->if it does, group the pair
// ->if not, push to a and rra() because last will be largest
void	last_iteration(t_stack **a, t_stack **b)
{
	assign_pos(*a);
	assign_pos(*b);
	assign_target(*a, *b);
	if ((*b)->target)
	{
		find_cheapest_and_moveto_top(*a, *b);
		pa(a, b);
	}
	else
	{
		move_smallest_totop(*a);
		pa(a, b);
		rra(*a);
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
		find_cheapest_and_moveto_top(a, b);
		pa(&a, &b);
	}
	last_iteration(&a, &b);
	move_smallest_totop(a);
	lstdestroy(b);
	b = 0;
}

int	push_swap(t_stack *a)
{
	if (!a)
		return (write(2, "Error\n", 6));
	if (lstlen(a) <= 1)
		return (0);
	if (lstlen(a) <= 3)
		tiny_sort(&a);
	else
		greater_sort(a);
	lstdestroy(a);
	return (0);
}
