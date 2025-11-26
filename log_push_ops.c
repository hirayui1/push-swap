#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	push_all_to_b(t_stack **a, t_stack **b, int len)
{
	while (len-- > 3)
		pb(b, a);
}
