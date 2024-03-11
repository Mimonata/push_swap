/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:48:52 by spitul            #+#    #+#             */
/*   Updated: 2024/03/11 15:59:57 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_error(char *argv)
{
	while (*argv)
	{
		if (*argv == '-' || *argv == '+')
		{
			if (*(argv +1) >= '0' && *(argv +1) <= '9')
				argv ++;
			else
				return (1);
		}
		while (*argv)
		{
			if (*argv < '0' && *argv > '9')
				return (1);
			argv ++;
		}
		return (0);
	}
}

int	duplicate_number(long n, t_node *stack)
{
	t_node	*current;

	if (!stack)
		return (0);
	current = stack;
	while (current)
	{
		if (current->nbr == n)
			return (1);
		current = current->next;
	}
	return (0);
}

int	stackt_sorted(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
			return (1);
		current = current->next;
	}
	return (0);
}
