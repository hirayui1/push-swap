#include "push_swap.h"
#include <stdio.h>

int	validate_input(char *argv)
{
	int	j;

	j = 0;
	while(argv[j])
	{
		if (!ft_isdigit(argv[j]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		j++;
	}
	return (1);
}

t_stack	*fill_stack(char **argv)
{
	t_stack *lst;
	t_stack *next;
	int	i;

	lst = lstnew(atoi(argv[1]));
	next = lst;
	i = 2;
	while (argv[i])
	{
		next->next = lstnew(atoi(argv[i++]));
		next = next->next;
	}
	return (lst);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (write(2, "Error\n", 6), 0);
	else
	{
		i = 1;
		while (argv[i])
			if (!validate_input(argv[i++]))
			return (0);
		push_swap(fill_stack(argv));
	}
	return (0);
}
/*
		*a = fill_stack(argv);
		*b = 0;
		ll_printer(a, 'a');
		swap(a);
		printf("swap:\n");
		ll_printer(a, 'a');
		printf("push:\n");
		push(&b, &a);
		ll_printer(a, 'a');
		ll_printer(b, 'b');
		printf("add to end:\n");
		lstadd_last(&a, 9);
		lstadd_last(&b, 8);
		ll_printer(a, 'a');
		ll_printer(b, 'b');
		printf("rotate:\n");
		rotate(a);
		ll_printer(a, 'a');
		printf("reverse rotate:\n");
		reverse_rotate(a);
		ll_printer(a, 'a');
		printf("rotate both:\n");
		rotate_both(a, b);
		ll_printer(a, 'a');
		ll_printer(b, 'b');
		printf("reverse rotate both:\n");
		reverse_rotate_both(a, b);
		ll_printer(a, 'a');
		ll_printer(b, 'b');
		lstdestroy(a);
		lstdestroy(b);
		*/
