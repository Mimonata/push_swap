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
#include <stdio.h>

long	ft_atol(char *argv)
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
	//if(n*s > INT_MAX || n*s < INT_MIN)
		//ft_error();
	return (n*s);
}

t_node	*create_new_node(long n)
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

void	append_new_node(t_node **stack, t_node *node)
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

int  create_stack_a(t_node **stack, char **argv)
{
	long	i;
	long	n;
	t_node	*new_node;

	i = 1;
	n = 0;
	if (!argv)
		return (1);
	while (argv[i])
	{
		if (!number_error(argv[i]))
			n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
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
		i ++;
	}
}

void	printstack(t_node *a)
{
	while (a != NULL)
	{
		printf("%ld\n", a->nbr);
		a = a->next;
	}
}

int main(int argc, char **argv)
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