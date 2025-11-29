/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_rrotate_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarabab <bkarabab@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:44:57 by bkarabab          #+#    #+#             */
/*   Updated: 2025/11/29 20:44:57 by bkarabab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_both(a, b);
	write(1, "rrr\n", 4);
}
