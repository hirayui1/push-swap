/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarabab <bkarabab@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:45:01 by bkarabab          #+#    #+#             */
/*   Updated: 2025/11/29 20:45:02 by bkarabab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(char **argv, int j)
{
	t_stack	*lst;
	t_stack	*next;
	int		i;

	lst = lstnew((int)ft_atoi(argv[j]));
	if (!lst)
		return (0);
	next = lst;
	i = j + 1;
	while (argv[i])
	{
		next->next = lstnew(ft_atoi(argv[i++]));
		if (!next->next)
		{
			lstdestroy(lst);
			return (0);
		}
		next = next->next;
	}
	return (lst);
}

static void	ft_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result[i]);
	free(result);
}

int	run_validation_checks(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
		if (!validate_input(argv[i++]))
			return (0);
	if (!is_sorted(argv, 1))
		return (0);
	return (1);
}

int	run_validation_checks2(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (!validate_input(res[i++]))
		{
			ft_free(res);
			return (0);
		}
	}
	if (!is_sorted(res, 0))
	{
		ft_free(res);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**res;

	if (argc == 1)
		return (0);
	else if (argc > 2)
	{
		if (!run_validation_checks(argv))
			return (0);
		push_swap(fill_stack(argv, 1));
	}
	else
	{
		res = ft_split(argv[1], ' ');
		if (!run_validation_checks2(res))
			return (0);
		push_swap(fill_stack(res, 0));
		ft_free(res);
	}
	return (0);
}
