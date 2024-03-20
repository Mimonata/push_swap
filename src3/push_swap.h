/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:44:34 by spitul            #+#    #+#             */
/*   Updated: 2024/03/14 11:28:24 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	long			nbr;
	unsigned int	position;
	unsigned int	cost;
	bool			up_rotation; 
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void	pa(t_node **stack_b, t_node **stack_a);
void	pb(t_node **stack_a, t_node **stack_b);
t_node	*go_to_last(t_node *stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

int	free_stack(t_node **stack);
int	create_stack_a(t_node **stack, char **argv);
void	write_error(void);
int	number_error(char *argv);
int	duplicate_number(long n, t_node *stack);
int	stack_sorted(t_node *stack);

int	main(int argc, char **argv);
void	sort_stack(t_node **stack_a, t_node **stack_b, long len_a);
void	set_pos(t_node	**stack);
void	set_rotation_direction(t_node *stack);
void	set_cost(t_node **src, t_node **dst);
void	min_on_top(t_node **stack);
t_node	*find_target_in_a(t_node **current, t_node *stack);
t_node	*find_target_in_b(t_node **current, t_node *stack);
t_node	*get_cheapest(t_node *stack);
void	move_to_top(t_node **node, t_node **src, t_node **dst);
void	push_to_a(t_node **node, t_node **src, t_node **dst);
void	push_to_b(t_node **node, t_node **src, t_node **dst);
void	sort_push_b(t_node **src, t_node **dst);
void	sort_push_a(t_node **src, t_node **dst);
t_node	*get_max(t_node *stack);
t_node	*get_min(t_node *stack);
void	sort_three(t_node **stack);
long	stack_length(t_node *stack);
long	ft_atol(char *argv);

#endif