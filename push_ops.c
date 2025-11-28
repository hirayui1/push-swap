#include "push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = lstnew((*src)->x);
		tmp->next = *dst;
		*dst = tmp;
		if ((*src)->next)
		{
			tmp = (*src)->next;
			free(*src);
			*src = tmp;
		}
		else
		{
			free(*src);
			*src = 0;
		}
	}
}
