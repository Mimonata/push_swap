/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:10:16 by spitul            #+#    #+#             */
/*   Updated: 2024/03/14 11:36:33 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*go_to_last(t_node *stack)
{
	t_node	*last;

	last = stack;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if ((!*stack) || ((*stack)->next == NULL))
		return ;
	last = go_to_last(*stack);
	last->next = *stack;
	(*stack)->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
