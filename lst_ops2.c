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
