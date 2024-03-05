/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:44:34 by spitul            #+#    #+#             */
/*   Updated: 2024/03/05 17:49:05 by spitul           ###   ########.fr       */
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
	bool			rotate_up; 
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

#endif