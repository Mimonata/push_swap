/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:45:09 by spitul            #+#    #+#             */
/*   Updated: 2024/03/17 18:51:32 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	printstack(t_node *a)
{
	while (a != NULL)
	{
		printf("%ld\n", a->nbr);
		a = a->next;
	}
}

static void	check_stack(t_node **a, t_node **b)
{
	long	len;

	len = stack_length(*a);
	if (stack_sorted(*a))
	{
		if (len == 2)
			sa(a);
		else if (len == 3)
			sort_three(a);
		else
			sort_stack(a, b, len);
	}	
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		t;

	a = NULL;
	b = NULL;
	t = 0;
	if (argc < 2 || !argv[1][0])
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		t = create_stack_a(&a, argv);
	}
	else
		t = create_stack_a(&a, argv + 1);
	if (t == 1)
		return(free_stack(&a));
	check_stack(&a, &b);
	printstack(a);
	free_stack(&a);
	return (0);
}
