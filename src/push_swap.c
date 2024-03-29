/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:32:48 by spitul            #+#    #+#             */
/*   Updated: 2024/03/23 14:34:01 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_on_top(t_node **stack)
{
	t_node	*min;

	min = get_min(*stack);
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if (min == *stack)
		return ;
	while ((*stack)->nbr != min->nbr)
	{
		if (min->up_rotation)
			ra(stack);
		else
			rra(stack);
	}
}

void	sort_push_b(t_node **src, t_node **dst)
{
	t_node	*cheapest;
	t_node	*current;

	current = *src;
	set_pos(src);
	set_pos(dst);
	set_rotation_direction(*src);
	set_rotation_direction(*dst);
	while (current)
	{
		current->target_node = find_target_in_b(&current, *dst);
		current = current->next;
	}
	set_cost(src, dst, stack_length(*src), stack_length(*dst));
	cheapest = get_cheapest(*src);
	push_to_b(&cheapest, src, dst);
}

void	sort_push_a(t_node **src, t_node **dst)
{
	t_node	*cheapest;
	t_node	*current;

	current = *src;
	set_pos(src);
	set_pos(dst);
	set_rotation_direction(*src);
	set_rotation_direction(*dst);
	while (current)
	{
		current->target_node = find_target_in_a(&current, *dst);
		current = current->next;
	}
	set_cost(src, dst, stack_length(*src), stack_length(*dst));
	cheapest = get_cheapest(*src);
	push_to_a(&cheapest, src, dst);
}

void	sort_stack(t_node **stack_a, t_node **stack_b, long len_a)
{
	if (len_a > 3)
		pb(stack_a, stack_b);
	if (-- len_a > 3)
		pb(stack_a, stack_b);
	len_a --;
	while (len_a > 3)
	{
		sort_push_b(stack_a, stack_b);
		len_a --;
	}
	if (stack_sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b != NULL)
		sort_push_a(stack_b, stack_a);
	set_pos(stack_a);
	set_rotation_direction(*stack_a);
	min_on_top(stack_a);
}
