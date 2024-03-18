/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:35:07 by spitul            #+#    #+#             */
/*   Updated: 2024/03/17 16:49:10 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_top(t_node **src, t_node **dst)
{
	t_node	*temp;

	if (!*src || !src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dst == NULL)
	{
		*dst = temp;
		(*dst)->next = NULL;
		(*dst)->prev = NULL;
	}
	else
	{
		temp->next = *dst;
		(*dst)->prev = temp;
		(*dst) = temp;
	}
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	push_top(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push_top(stack_a, stack_b);
	write(1, "pb\n", 3);
}
