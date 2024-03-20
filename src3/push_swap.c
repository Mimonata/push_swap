/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:32:48 by spitul            #+#    #+#             */
/*   Updated: 2024/03/15 18:07:00 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **stack_a, t_node **stack_b, long len_a)
{
	if (len_a > 3)
		pb(stack_a, stack_b);
	if (-- len_a > 3)
		pb(stack_a, stack_b);
	len_a --;
	while (len_a > 3)
	{
		sort_push_b(stack_a, stack_b);
		len_a --;
	}
	if (stack_sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b != NULL)
	{
		sort_push_a(stack_b, stack_a);
		if (*stack_b)
			(*stack_b) = (*stack_b)->next;
	}
	min_on_top(stack_a);
}
