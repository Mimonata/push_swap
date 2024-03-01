/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:45:09 by spitul            #+#    #+#             */
/*   Updated: 2024/02/20 18:45:09 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	atol(char *argv)
{
	int i;
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
			n = n*10 + (argv[i ++] - 48);
		else
			return (0);
	}
	return (n*s);
}

t_node	*create_new_node(char *argv, long n)
{
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	//new_node->nbr = atol(*argv); //dies vielleicht auch anderswo
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->nbr = n;
	return (new_node);
}

void	append_new_node(t_node **stack, t_node *node)
{
	if (*stack == NULL)
		*stack = node;
	else
	{
		node->next = *stack;
		(*stack)->prev = node;
		*stack = node;
	}
}

int number_error(char *argv)
{
	while (*argv)
	{
		if (*argv == '-' || *argv == '+' || (*argv >= '0' && *argv <= '9'))
			argv ++;
		else
			return (1);
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

void  create_stack_a(t_node **stack, char **argv)
{
	long    i;
	long	n;
	t_node  *new_node;

	i = 0;
	if (!argv)
		return (1);
	while (argv[i])
	{
		if (!number_error(argv[i]))
			n = atol(argv[i]);
		if (!duplicate_number(n, stack))
		{
			new_node = create_new_node(argv[i], n);
			if (!new_node)
				return (free_stack());
			append_new_node(stack, new_node);
		}
}

int main(int argc, char **argv)
{
	t_node  *a;
	t_node  *b;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
		return (1);
	create_stack_a(&a, argv + 1);
	if (argc  4)

} 