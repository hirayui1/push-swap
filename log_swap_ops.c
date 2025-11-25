#include "push_swap.h"

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sa\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_both(a, b);
	write(1, "ss\n", 3);
}
