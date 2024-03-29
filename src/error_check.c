/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:48:52 by spitul            #+#    #+#             */
/*   Updated: 2024/03/29 16:24:48 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	write_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	number_error(char *argv)
{
	if (!*argv)
		return (write_error());
	while (*argv)
	{
		if (*argv == '-' || *argv == '+')
		{
			if (*(argv + 1) >= '0' && *(argv + 1) <= '9')
				argv ++;
			else
				return (write_error());
		}
		while (*argv)
		{
			if (*argv < '0' || *argv > '9')
				return (write_error());
			argv ++;
		}
	}
	return (0);
}

int	int_check(long n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (write_error());
	else 
		return (0);
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
			return (write_error());
		current = current->next;
	}
	return (0);
}

int	stack_sorted(t_node *stack)
{
	t_node	*current;

	if (!stack)
		return (0);
	current = stack;
	while (current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
			return (1);
		current = current->next;
	}
	return (0);
}
