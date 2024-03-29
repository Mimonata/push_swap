/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:40:56 by spitul            #+#    #+#             */
/*   Updated: 2024/03/23 12:50:07 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	len = stack_length(stack);
	while (stack)
	{
		if (stack->position <= (len / 2))
			stack->up_rotation = true;
		else
			stack->up_rotation = false;
		stack = stack->next;
	}
}

static unsigned int	in_stack_cost(t_node *node,	long len_stack)
{
	long	cost;

	if (node->up_rotation == true)
		cost = node->position;
	else 
		cost = len_stack - node->position;
	return (cost);
}

static void	set_cost_node(t_node **node, unsigned int cost_node, 
unsigned int cost_target)
{
	t_node	*current;

	current = (*node);
	if ((current->up_rotation && current->target_node->up_rotation)
		|| (!current->up_rotation && !current->target_node->up_rotation))
	{
		if (cost_node >= cost_target)
			current->cost = cost_node;
		else if (cost_node < cost_target)
			current->cost = cost_target;
	}
	else
		current->cost = cost_node + cost_target;
}

void	set_cost(t_node **src, t_node **dst, long len_src, long len_dst)
{
	unsigned int	cost_node;
	unsigned int	cost_target;
	t_node			*current;

	if (!*src || !*dst)
		return ;
	current = *src;
	if (len_dst > 1)
	{
		while (current)
		{
			cost_target = in_stack_cost(current->target_node, len_dst);
			cost_node = in_stack_cost(current, len_src);
			set_cost_node(&current, cost_node, cost_target);
			current = current->next;
		}
	}
}
