/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:22:44 by spitul            #+#    #+#             */
/*   Updated: 2024/03/11 15:41:40 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_max(t_node *stack)
{
	long	max;
	t_node	*max_pos;
	t_node	*current;

	max = LONG_MIN;
	current = stack;
	max_pos = NULL;
	if (!stack)
		return (NULL);
	while (current != NULL)
	{
		if (current->nbr > max)
		{
			max = current->nbr;
			max_pos = current;
		}
		current = current->next;
	}
	return (max_pos);
}

t_node	*get_min(t_node *stack)
{
	long	min;
	t_node	*min_pos;
	t_node	*current;

	min = LONG_MAX;
	current = stack;
	min_pos = NULL;
	if (!stack)
		return (NULL);
	while (current != NULL)
	{
		if (current->nbr < min)
		{
			min = current->nbr;
			min_pos = current;
		}
		current = current->next;
	}
	return (min_pos);
}

void	sort_three(t_node **stack)
{
	t_node	*max_node;

	max_node = get_max(*stack);
	if ((*stack) == max_node)
		ra(stack);
	else if ((*stack)->next == max_node)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}
