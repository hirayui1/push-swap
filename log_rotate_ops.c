/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarabab <bkarabab@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:43:51 by bkarabab          #+#    #+#             */
/*   Updated: 2025/11/29 20:43:52 by bkarabab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_both(a, b);
	write(1, "rr\n", 3);
}
