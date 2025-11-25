#include "push_swap.h"

void	rotate(t_stack *a)
{
	int	tmp;

	tmp = a->x;
	while (a->next)
	{
		a->x = a->next->x;
		a = a->next;
	}
	a->x = tmp;
}

static void	recursive_rotate(t_stack *last, t_stack *a, int *tmp)
{
	if (a->next)
		recursive_rotate(a, a->next, tmp);
	if (last)
	{
		if (!a->next)
			*tmp = a->x;
		a->x = last->x;
	}
}

void	reverse_rotate(t_stack *a)
{
	int	tmp;

	if (!a->next) // handles list having only 1 element
		return ;
	recursive_rotate(0, a, &tmp);
	a->x = tmp;
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
