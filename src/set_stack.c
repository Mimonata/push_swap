/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:40:56 by spitul            #+#    #+#             */
/*   Updated: 2024/03/17 16:43:31 by spitul           ###   ########.fr       */
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

void	set_cost(t_node **src, t_node **dst)
{
	unsigned int	cost_node;
	unsigned int	cost_target;
	long			len_src;
	long			len_dst;
	t_node			*current;

	if (!*src || !*dst)
		return ;
	current = *src;
	len_src = stack_length(*src);
	len_dst = stack_length(*dst);
	if (len_dst > 1)
	{
		while (current)
		{
			cost_target = in_stack_cost(current->target_node, len_dst);		
			cost_node = in_stack_cost(current, len_src);		
			if ((current->up_rotation && current->target_node->up_rotation) 		
				|| (!current->up_rotation && !current->target_node->up_rotation))		
				current->cost = (cost_node > cost_target) ? cost_node : cost_target;		
			else		
				current->cost = cost_node + cost_target;
			current =  current->next;
		}	
	}
}

void min_on_top(t_node **stack)
{
    if (*stack == NULL || (*stack)->next == NULL) // If the stack is empty or has only one node, return
        return;

    t_node *minNode = get_min(*stack);

    if (minNode == *stack) // If the minimum value is already at the top, no rotation needed
        return;

    // If the minimum value is not at the top, rotate accordingly
    while ((*stack)->nbr != minNode->nbr)
    {
        if (minNode->up_rotation)
            ra(stack);
        else
            rra(stack);
    }
}

