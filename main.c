#include "push_swap.h"
int	validate_input(char *argv)
{
	int	j;

	j = 0;
	while(argv[j])
	{
		if (argv[j] != '-' && !ft_isdigit(argv[j]))
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

	lst = lstnew((int)ft_atoi(argv[1]));
	if (!lst)
		return (0);
	next = lst;
	i = 2;
	while (argv[i])
	{
		next->next = lstnew(atoi(argv[i++]));
		if (!next->next)
		{
			lstdestroy(lst);
			return (0);
		}
		next = next->next;
	}
	return (lst);
}

int	is_dup(char **argv, int i)
{
	long	curr;
	int	j;

	while (argv[i])
	{
		curr = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[j]) == curr)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_minmax(char **argv, int i)
{
	long	curr;

	while (argv[i])
	{
		curr = ft_atoi(argv[i]);
		if (curr > INT_MAX || curr < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_sorted(char **argv, int i)
{
	int	last;
	int	curr;


	if (is_minmax(argv, i) || is_dup(argv, i))
		return (0);
	last = ft_atoi(argv[i]);
	while (argv[++i])
	{
		curr = ft_atoi(argv[i]);
		if (curr < last)
			return (1);
		else
			last = curr;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	char	**res;

	if (argc == 1)
		return (0);
	else if (argc > 2)
	{
		i = 1;
		while (argv[i])
			if (!validate_input(argv[i++]))
				return (0);
		if (!is_sorted(argv, 1))
			return (0);
	}
	else
	{
		i = 0;
		res = ft_split(argv[1], ' ');
		if (!validate_input(res[i]))
		{
			free(res);
			return (0);
		}
		if (!is_sorted(res, 0))
		{
			free(res);
			return (0);
		}
		free(res);
	}
	push_swap(fill_stack(argv));
	return (0);
}
