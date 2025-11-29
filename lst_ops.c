/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarabab <bkarabab@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:44:04 by bkarabab          #+#    #+#             */
/*   Updated: 2025/11/29 20:44:05 by bkarabab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int content)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (0);
	(*a).x = content;
	a->next = 0;
	return (a);
}

// have to change t_stack *a to **a (double pointer)
// because if a is null, I cannot add a new memory address
// to an unexisting address, but if double pointer
// the first pointer holds null a in a certain address
// that can be replaced with an actual malloc
void	lstadd_last(t_stack **a, int content)
{
	if (!*a)
	{
		*a = lstnew(content);
		return ;
	}
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = lstnew(content);
}

int	lstlen(t_stack *a)
{
	size_t	len;

	if (!a)
		return (0);
	len = 1;
	while (a->next)
	{
		len++;
		a = a->next;
	}
	return (len);
}

t_stack	*find_highest(t_stack *a)
{
	t_stack	*highest;

	highest = a;
	while (a->next)
	{
		if (a->next->x > highest->x)
			highest = a->next;
		a = a->next;
	}
	return (highest);
}

void	lstdestroy(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}
