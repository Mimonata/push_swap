/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:01:30 by spitul            #+#    #+#             */
/*   Updated: 2024/03/04 21:01:30 by spitul           ###   ########.fr       */
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

t_node	*set_cost(t_node **stack)
{
	
}

t_node	*get_cheapest(t_node *stack)
{

}