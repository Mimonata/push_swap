/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:01:30 by spitul            #+#    #+#             */
/*   Updated: 2024/03/13 16:49:50 by spitul           ###   ########.fr       */
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
		else
			target = get_min(stack);
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
		else
			target = get_max(stack);
		stack = stack->next;
	}
	if (target == NULL)
		target = get_max(stack);
	return (target);
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
		stack = stack->next;
	}
	return (cheapest);
}

// void	move_cheapest_to_b(t_node **node, t_node **src, t_node **dst)
// {
	// if ((*node)->up_rotation && (*node)->target_node->up_rotation)
	// {
		// while ((*node)->position != 1
		// || (*node)->target_node->position != 1)	
		// {	
			// rr(src, dst);	
			// set_pos(src);	
			// set_pos(dst);	
		// }
	// }
	// else if ((*node)->up_rotation && (*node)->target_node->up_rotation)
		// while ((*node)->position != 1 || (*node)->target_node->position != 1)
		// {
			// rrr(src, dst);
			// set_pos(src);
			// set_pos(dst);
		// }
	// if ((*node)->position != 1 && (*node)->up_rotation)
		// while ((*node)->position != 1)
		// {
			// ra(src);
			// set_pos(src);
		// }
	// else if ((*node)->target_node->position != 1)
		// while ((*node)->position != 1)
		// {
			// rb(dst);
			// set_pos(dst);
		// }
	// pb(src, dst);
// }

void	move_to_top(t_node **node, t_node **src, t_node **dst)
{
	if ((*node)->up_rotation && (*node)->target_node->up_rotation)
		while ((*node)->position != 1 || (*node)->target_node->position != 1)
		{
			rr(src, dst);
			set_pos(src);
			set_pos(dst);
		}
	else if ((*node)->up_rotation && (*node)->target_node->up_rotation)
		while ((*node)->position != 1 || (*node)->target_node->position != 1)
		{
			rrr(src, dst);
			set_pos(src);
			set_pos(dst);
		}
	if ((*node)->position != 1 && (*node)->up_rotation)
		while ((*node)->position != 1)
		{
			ra(src);
			set_pos(src);
		}
	else if ((*node)->position != 1 && !(*node)->up_rotation)
	{
		while ((*node)->position != 1)
		{
			rra(src);
			set_pos(src);
		}
	}
	else if ((*node)->target_node->position != 1 && (*node)->target_node->up_rotation)
		while ((*node)->position != 1)
		{
			rb(dst);
			set_pos(dst);
		}
	else if ((*node)->position != 1 && !(*node)->target_node->up_rotation)
	{		
		while ((*node)->target_node->position != 1)		
		{		
			rrb(dst);		
			set_pos(dst);		
		}		
	}			
}

void	push_to_a(t_node **node, t_node **src, t_node **dst)
{
	move_to_top(node, src, dst);
	pa(src, dst);
}

void	push_to_b(t_node **node, t_node **src, t_node **dst)
{
	move_to_top(node, src, dst);
	pb(src, dst);
}

void	sort_push_b(t_node **src, t_node **dst)
{
	t_node	*cheapest;
	t_node	*current;

	current = *src;
	while (current != NULL)
	{
		find_target_in_b(src, *dst);
		set_rotation_direction(src);
		set_rotation_direction(dst);
		set_cost(src, dst);
		current = current->next;
	}
	cheapest = get_cheapest(src);
	push_to_b(&cheapest, src, dst);
}

void	sort_push_a(t_node **src, t_node **dst)
{
	t_node	*cheapest;
	t_node	*current;

	current = *src;
	while (current != NULL)
	{
		find_target_in_a(src, *dst);
		set_rotation_direction(src);
		set_rotation_direction(dst);
		set_cost(src, dst);
		current = current->next;
	}
	cheapest = get_cheapest(src);
	push_to_a(&cheapest, src, dst);
}
