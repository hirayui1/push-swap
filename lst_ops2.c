#include "push_swap.h"

t_stack	*find_smallest(t_stack *a)
{
	t_stack	*smallest;

	smallest = a;
	while (a->next)
	{
		if (a->next->x < smallest->x)
			smallest = a->next;
		a = a->next;
	}
	return (smallest);
}

t_stack	*find_cheapest(t_stack *b)
{
	t_stack	*cheapest;

	cheapest = b;
	while (b->next)
	{
		if (b->target)
		{
			if (cheapest->target && b->pos + b->target->pos
				< cheapest->pos + cheapest->target->pos)
				cheapest = b;
			else if (b->pos + b->target->pos < cheapest->pos)
				cheapest = b;
		}
		else
		{
			if (cheapest->target && b->pos
				< cheapest->pos + cheapest->target->pos)
				cheapest = b;
			else if (b->pos < cheapest->pos)
				cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}
