/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_swap_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarabab <bkarabab@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:44:30 by bkarabab          #+#    #+#             */
/*   Updated: 2025/11/29 20:44:31 by bkarabab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_both(a, b);
	write(1, "ss\n", 3);
}
