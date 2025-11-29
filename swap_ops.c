/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarabab <bkarabab@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:44:22 by bkarabab          #+#    #+#             */
/*   Updated: 2025/11/29 20:44:23 by bkarabab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a)
{
	t_stack	*next;
	int		tmp;

	if (!a->next)
		return ;
	next = a->next;
	tmp = a->x;
	a->x = next->x;
	next->x = tmp;
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
