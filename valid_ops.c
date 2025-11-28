#include "push_swap.h"
#include <stdio.h>

int	validate_input(char *argv)
{
	int	len;
	int	j;

	j = 0;
	len = ft_strlen(argv);
	while (argv[j])
	{
		if (argv[j] != '-' && !ft_isdigit(argv[j]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		else if (argv[j] == '-' && (j >= len 
					|| !ft_isdigit(argv[j + 1])))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		j++;
	}
	return (1);
}

int	is_dup(char **argv, int i)
{
	long	curr;
	int		j;

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
