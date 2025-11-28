#include "push_swap.h"

void	tiny_sort(t_stack **a)
{
	t_stack	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(*a);
	else if ((*a)->next == highest)
		rra(*a);
	if ((*a)->x > (*a)->next->x)
		sa(*a);
}
