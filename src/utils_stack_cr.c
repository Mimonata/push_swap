/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_cr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:51:25 by spitul            #+#    #+#             */
/*   Updated: 2024/03/23 11:53:44 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(char *argv)
{
	int		i;
	long	n;
	long	s;

	i = 0;
	n = 0;
	s = 1;
	if (!argv)
		return (0);
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			s = -1;
		i ++;
	}
	while (argv[i] != '\0')
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			n = n * 10 + (argv[i ++] - 48);
		else
			return (0);
	}
	return (n * s);
}

long	stack_length(t_node *stack)
{
	t_node	*current;
	long	len;

	if (!stack)
		return (0);
	len = 0;
	current = stack;
	while (current != NULL)
	{
		len ++;
		current = current->next;
	}
	return (len);
}

t_node	*find_target_in_a(t_node **current, t_node *stack)
{
	t_node	*target;
	t_node	*a;

	target = NULL;
	if (!stack)
		return (NULL);
	a = stack;
	while (stack != NULL)
	{
		if (((*current)->nbr < stack->nbr) && (target == NULL))
			target = stack;
		else if (((*current)->nbr < stack->nbr) && 
			((stack->nbr - (*current)->nbr) < (target->nbr - (*current)->nbr)))
			target = stack;
		stack = stack->next;
	}
	if (target == NULL)
		target = get_min(a);
	return (target);
}

t_node	*find_target_in_b(t_node **current, t_node *stack)
{
	t_node	*target;
	t_node	*b;

	target = NULL;
	if (!stack)
		return (NULL);
	b = stack;
	while (stack != NULL)
	{
		if (((*current)->nbr > stack->nbr) && (target == NULL))
			target = stack;
		else if (((*current)->nbr > stack->nbr) && 
			(((*current)->nbr - stack->nbr) < ((*current)->nbr - target->nbr)))
			target = stack;
		stack = stack->next;
	}
	if (target == NULL)
		target = get_max(b);
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
		if (cheapest->cost > stack->cost)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}
