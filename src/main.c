/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:45:09 by spitul            #+#    #+#             */
/*   Updated: 2024/03/13 15:47:34 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	printstack(t_node *a)
{
	while (a != NULL)
	{
		printf("%ld\n", a->nbr);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	long	len;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
		return (1);
	else
	{
		create_stack_a(&a, argv);
		len = stack_length(a);
		if (!stack_sorted(a))
		{
			if (len == 2)
				sa(&a);
			else if (len == 3)
				sort_three(&a);
			else
				sort_stack(&a, &b, len);
		}
		free_stack(&a);
	}
	return (0);
}
