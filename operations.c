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

	temp = (*stack)->next;	
	if (!(*stack) || ((*stack)->next == NULL))
		return ;
	(*stack)->next = temp->next;
	temp->next->prev = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	temp->next = *stack;
	*stack  = temp;
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

t_node	*go_to_last(t_node *stack)
{
	t_node	*last;

	last = stack;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	push_top(t_node **src, t_node **dst)
{
	t_node	*temp;

	if (!*src)
		return ;
	temp = *src;
	if (*dst == NULL)
	{
		*dst = *src;
		(*dst)->next = NULL;
		(*dst)->prev = NULL;
	}
	else
	{
		(*src)->next = *dst;
		(*dst)->prev = *src;
	}
	*src = temp->next;
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
	t_node	*last;

	if ((!*stack) || ((*stack)->next == NULL))
		return ;
	last = go_to_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->prev = last;
	last->next->next = NULL;
	(*stack)->prev = NULL;	
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_node **stack)
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