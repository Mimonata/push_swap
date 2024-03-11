/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:45:09 by spitul            #+#    #+#             */
/*   Updated: 2024/03/11 15:53:20 by spitul           ###   ########.fr       */
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

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
		return (1);
	else
		create_stack_a(&a, argv);
	//if (argc == 4)
	//	sort_three(&a);
	printstack(a);
	//ft_stack_dealloc(a);
	return (0);
}
