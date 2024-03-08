/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:01:30 by spitul            #+#    #+#             */
/*   Updated: 2024/03/05 18:18:48 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_target_in_a(t_node **current, t_node *stack)
{
	t_node	*target;

	target = NULL;
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		if (((*current)->nbr < stack->nbr) && (target == NULL))
			target = *current;
		else if (((*current)->nbr < stack->nbr) && 
		((stack->nbr - (*current)->nbr) < (target->nbr - (*current)->nbr)))
			target = *current;
		stack = stack->next;
	}
	if (target == NULL)
		target = get_max(stack);
	return (target);
}


t_node	*find_target_in_b(t_node **current, t_node *stack)
{
	t_node	*target;

	target = NULL;
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		if (((*current)->nbr > stack->nbr) && (target == NULL))
			target = *current;
		else if (((*current)->nbr > stack->nbr) && 
		(((*current)->nbr - stack->nbr) < ((*current)->nbr - target->nbr)))
			target = *current;
		stack = stack->next;
	}
	if (target == NULL)
		target = get_max(stack);
	return (target);
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

unsigned int	cost_movement_in_stack(t_node *node, t_node *stack, unsigned int len_stack)
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
	long	len_src;
	long	len_dst;
	t_node	*current;

	current = *src;
	if (!src || !dst)
		return (NULL);
	len_src = stack_length(*src);
	len_dst = stack_length(*dst);
	if (len_dst > 2)
	{
		while (*src)
		{
			cost_target = cost_movement_in_stack(current->target_node, *dst, len_dst);
			cost_node = cost_movement_in_stack(current, *src, len_src);
			if (((*src)->up_rotation == true && (*src)->target_node->up_rotation == true) ||
				((*src)->up_rotation == false && (*src)->target_node->up_rotation == false))
				current->cost = (cost_node > cost_target) ? cost_node : cost_target;
			else
				current->cost = cost_node + cost_target;
			current = current->next;
		}
	}
}

t_node	*get_cheapest(t_node *stack)
{
	t_node	*cheapest;

	if (!stack)
		return (NULL);
	cheapest = stack;
	while (stack)
	{
		if (cheapest->cost < stack->cost)
			cheapest = stack;
		stack =  stack->next;
	}
	return (cheapest);
}

void	init_a(t_node **src, t_node **dst)
{
	set_rotation_direction(*src);
	find_target_in_b(*dst, );

}

void	do_the_sort(t_node **src, t_node **dst)
{

}