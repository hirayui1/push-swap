#include "push_swap.h"

void	swap(t_stack *a)
{
	t_stack	*next;
	int	tmp;

	if (!a->next)
		return ;
	next = a->next;
	tmp = a->x;
	a->x = next->x;
	next->x = tmp;
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
