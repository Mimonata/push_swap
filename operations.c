/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:10:16 by spitul            #+#    #+#             */
/*   Updated: 2024/03/02 14:31:26 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_node **stack)
{
	t_node	*temp;
	t_node	*last;
	
	if (!(*stack) || ((*stack)->next == NULL))
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	temp = last->prev;
	last->prev = temp->prev;
	temp->prev->next = last;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
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
	swap_top(stack_a);
	write(1, "ss\n", 3);
}

t_node	*got_to_last(t_node *stack)
{
	t_node	*last;

	last = stack;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	push_top(t_node **src, t_node **dst)
{
	t_node	*last_src;
	t_node	*last_dst;

	if (!*src)
		return ;
	last_src = got_to_last(*src);
	if (!*dst)
		
	last_dst = got_to_last(*dst);
	last_src->prev->next = NULL;
	last_dst->next = last_src;
	last_src->prev = last_dst;
}

void	pa(t_node *stack_b, t_node *stack_a)
{
	push_top(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_node *stack_a, t_node *stack_b)
{
	push_top(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	rotate(t_node **stack)
{
	
}
