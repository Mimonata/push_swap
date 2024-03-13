/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_cr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:51:25 by spitul            #+#    #+#             */
/*   Updated: 2024/03/11 15:52:15 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	//if(n*s > INT_MAX || n*s < INT_MIN)
		//ft_error();
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

int	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*last;

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
