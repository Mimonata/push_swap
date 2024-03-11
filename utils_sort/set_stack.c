/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:40:56 by spitul            #+#    #+#             */
/*   Updated: 2024/03/11 16:06:33 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_node	**stack)
{
	int		i;
	t_node	*current;

	i = 0;
	current = *stack;
	while (current != NULL)
	{
		current->position = i;
		i ++;
		current = current->next;
	}
}

void	set_rotation_direction(t_node *stack)
{
	long	len;

	if (!stack)
		return ;
	len = stack_length(&stack);
	while (stack)
	{
		if (stack->position <= (len / 2))
			stack->up_rotation = true;
		else
			stack->up_rotation = false;
	}
}

unsigned int	in_stack_cost(t_node *node, t_node *stack, 
	unsigned int len_stack)
{
	unsigned int	cost;

	if (!stack)
		return (0);
	len_stack = stack_length(stack);
	if (stack->up_rotation == true)
		cost = stack->position;
	else 
		cost = len_stack - stack->position;
	return (cost);
}

void	set_cost(t_node **src, t_node **dst)
{
	unsigned int	cost_node;
	unsigned int	cost_target;
	long			len_src;
	long			len_dst;
	t_node			*current;

	current = *src;
	if (!src || !dst)
		return (NULL);
	len_src = stack_length(*src);
	len_dst = stack_length(*dst);
	if (len_dst > 2)
	{
		while (*src)
		{
			cost_target = in_stack_cost(current->target_node, *dst, len_dst);
			cost_node = in_stack_cost(current, *src, len_src);
			if (((*src)->up_rotation == true && 
					(*src)->target_node->up_rotation == true) 
				|| ((*src)->up_rotation == false && 
					(*src)->target_node->up_rotation == false))
				current->cost = (cost_node > cost_target) ? cost_node : cost_target;
			else
				current->cost = cost_node + cost_target;
			current = current->next;
		}
	}
}
