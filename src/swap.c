/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:36:22 by spitul            #+#    #+#             */
/*   Updated: 2024/03/29 17:17:10 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_top(t_node **stack)
{
	t_node	*temp;

	if (!stack || !(*stack) || ((*stack)->next == NULL))
		return ;
	temp = (*stack)->next;
	if (stack_length(*stack) > 2)
		temp->next->prev = temp->prev;
	(*stack)->next = temp->next;
	(*stack)->prev = temp;
	temp->prev = NULL;
	temp->next = *stack;
	*stack = temp;
}

void	sa(t_node **stack_a)
{
	swap_top(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	swap_top(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_top(stack_a);
	swap_top(stack_b);
	write(1, "ss\n", 3);
}
