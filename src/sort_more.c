/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:01:30 by spitul            #+#    #+#             */
/*   Updated: 2024/03/20 18:27:17 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_one(t_node **node, t_node **stack, char a_b)
{
	while ((*node)->position != 0)
	{
		if (a_b == 'a' && (*node)->up_rotation)
		{
			ra(stack);
			set_pos(stack);
		}
		else if (a_b == 'a' && !(*node)->up_rotation)
		{
			rra(stack);
			set_pos(stack);
		}
		else if (a_b == 'b' && (*node)->up_rotation)
		{
			rb(stack);
			set_pos(stack);
		}
		else if (a_b == 'b' && !(*node)->up_rotation)
		{
			rrb(stack);		
			set_pos(stack);
		}
	}
}

static void	move_two(t_node **node, t_node **src, t_node **dst)
{
	while (((*node)->position != 0 && (*node)->target_node->position != 0))
	{
		if ((*node)->up_rotation && (*node)->target_node->up_rotation)
		{
			rr(src, dst);
			set_pos(src);
			set_pos(dst);
		}
		else if (!(*node)->up_rotation && !(*node)->target_node->up_rotation)
		{
			rrr(src, dst);
			set_pos(src);
			set_pos(dst);
		}
	}
}

void	push_to_a(t_node **node, t_node **src, t_node **dst)
{
	if (((*node)->up_rotation && (*node)->target_node->up_rotation)
		|| (!(*node)->up_rotation && !(*node)->target_node->up_rotation))
		move_two(node, src, dst);
	if ((*node)->position != 0)
		move_one(node, src, 'b');
	if ((*node)->target_node->position != 0)
		move_one(&((*node)->target_node), dst, 'a');	
	pa(src, dst);
}

void	push_to_b(t_node **node, t_node **src, t_node **dst)
{
	if (((*node)->up_rotation && (*node)->target_node->up_rotation)
	|| (!(*node)->up_rotation && !(*node)->target_node->up_rotation))
		move_two(node, src, dst);
	if ((*node)->position != 0)
		move_one(node, src, 'a');
	if ((*node)->target_node->position != 0)
		move_one(&((*node)->target_node), dst, 'b');	
	pb(src, dst);
}
