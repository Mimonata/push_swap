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

t_node	*find_target_node(t_node **current, t_node *stack)
{
	t_node	*target;

	target = NULL;
	if (!*current)
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
		if (stack->position >= (len / 2 + 1))
			stack->rotate_up = true;
		else
			stack->rotate_up = false;
	}
}

t_node	*set_cost(t_node **src, t_node **dst)
{
	long	cost_node;
	long	cost_target;
	long	len_src;
	long	len_dst;

	if (!src || !dst)
		return (NULL);
	cost_target = 0;
	cost_node = 0;
	len_src = stack_length(*src);
	len_dst = stack_length(*dst);
	if ((*src)->rotate_up == true)
		cost_node = len_src - (*src)->position;
	else 
	while (*stack)
	{
		if ((*stack)->rotate_up == true) 
			(*stack)->cost = 
	}
}

t_node	*get_cheapest(t_node *stack)
{

}