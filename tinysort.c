#include "push_swap.h"

void	tiny_sort(t_stack **a)
{
	t_stack	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		rotate(*a);
	else if ((*a)->next == highest)
		reverse_rotate(*a);
	if ((*a)->x > (*a)->next->x)
		swap(*a);
}
