/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:01:30 by spitul            #+#    #+#             */
/*   Updated: 2024/03/11 16:15:49 by spitul           ###   ########.fr       */
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

void	move_cheapest_a_to_b(t_node **node, t_node **src, t_node **dst)
{
	if ((*node)->up_rotation == true && 
		(*node)->target_node->up_rotation == true)
		while ((*node)->position != 1 \
		|| (*node)->target_node->position != 1)
		{
			rr(src, dst);
			set_pos(src);
			set_pos(dst);
		}
	else if ((*node)->up_rotation == false && 
		(*node)->target_node->up_rotation == false)
		while ((*node)->position != 1 || (*node)->target_node->position != 1)
		{
			rrr(src, dst);
			set_pos(src);
			set_pos(dst);
		}
	if ((*node)->position != 1)
		while ((*node)->position != 1)
		{
			ra(src);
			set_pos(src);
		}
	else if ((*node)->target_node->position != 1)
		while ((*node)->position != 1)
		{
			rb(dst);
			set_pos(dst);
		}
	pb(src, dst);
}

void	move_cheapest_b_to_a(t_node **node, t_node **src, t_node **dst)
{
	if ((*node)->up_rotation == true 
		&& (*node)->target_node->up_rotation == true)
		while ((*node)->position != 1 || (*node)->target_node->position != 1)
		{
			rr(src, dst);
			set_pos(src);
			set_pos(dst);
		}
	else if ((*node)->up_rotation == false 
		&& (*node)->target_node->up_rotation == false)
		while ((*node)->position != 1 || (*node)->target_node->position != 1)
		{
			rrr(src, dst);
			set_pos(src);
			set_pos(dst);
		}
	if ((*node)->position != 1)
		while ((*node)->position != 1)
		{
			ra(src);
			set_pos(src);
		}
	else if ((*node)->target_node->position != 1)
		while ((*node)->position != 1)
		{
			rb(dst);
			set_pos(dst);
		}
	pa(src, dst);
}

void	sort_push_b(t_node **src, t_node **dst)
{
	int		len;
	t_node	*cheapest;
	t_node	*current;

	len = stack_length(*src);
	if (*dst == NULL)
	{
		pb(src, dst); 
		pb(src, dst);
	}
	else
	{
		while (len > 3)
		{
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
			move_cheapest_a_to_b(&cheapest, src, dst);
			len --;
		}
	}
}

void	sort_push_a(t_node **src, t_node **dst)
{
	int		len;
	t_node	*cheapest;
	t_node	*current;

	while (*dst != NULL)
	{
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
		move_cheapest_a_to_b(&cheapest, src, dst);
	}
}
