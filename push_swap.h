#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
typedef struct	s_stack {
	struct s_stack	*next;
	struct s_stack	*target;
	int	median_flag;
	int	pos;
	int	x;
}		t_stack;

// Push Operations
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
// Swap Operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
// Rotate Operations
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
// Reverse Rotate Operations
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

int	push_swap(t_stack *a);
int	lstlen(t_stack *a);
t_stack *lstnew(int content);
t_stack	*find_highest(t_stack *a);
void	swap(t_stack *a);
void	swap_both(t_stack *a, t_stack *b);
void	push(t_stack **dst, t_stack **src);
void	lstadd_last(t_stack **a, int content);
void	lstdestroy(t_stack *a);
void	rotate(t_stack *a);
void	reverse_rotate(t_stack *a);
void	rotate_both(t_stack *a, t_stack *b);
void	reverse_rotate_both(t_stack *a, t_stack *b);
void	tiny_sort(t_stack **a);
#endif
