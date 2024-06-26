/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:47:40 by spitul            #+#    #+#             */
/*   Updated: 2024/03/23 18:26:49 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*create_new_node(long n)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->nbr = n;
	return (new_node);
}

static void	append_new_node(t_node **stack, t_node *node)
{
	t_node	*current;

	current = *stack;
	if (*stack == NULL)
		*stack = node;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = node;
		node->prev = current;
	}
}

int	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*last;

	if (!stack || !*stack)
		return (1);
	current = *stack;
	while (current != NULL)
	{
		last = current;
		current = current->next;
		free (last);
	}
	*stack = NULL;
	return (1);
}

int	create_stack_a(t_node **stack, char **argv)
{
	long	i;
	long	n;
	t_node	*new_node;

	i = -1;
	n = 0;
	if (!argv)
		return (1);
	while (argv[++ i])
	{
		if (!number_error(argv[i]))
			n = ft_atol(argv[i]);
		if (int_check(n))
			return (free_stack(stack));
		if (!duplicate_number(n, *stack))
		{
			new_node = create_new_node(n);
			if (!new_node)
				return (free_stack(stack));
			append_new_node(stack, new_node);
		}
		else 
			return (free_stack(stack));
	}
	return (0);
}
