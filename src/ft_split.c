/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:47:34 by spitul            #+#    #+#             */
/*   Updated: 2024/03/16 14:49:04 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_length(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while ((s[i] != '\0') && (s[i] == c))
		i ++;
	while ((s[i] != c) && (s[i] != '\0'))
	{
		len ++;
		i ++;
	}
	return (len);
}

static int	get_number_segments(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s[i])
		return (0);
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i] != '\0'))
		{
			while ((s[i] != c) && (s[i] != '\0'))
				i ++;
			count ++;
		}
		if ((s[i] == c) && (s[i] != '\0'))
			i ++;
	}
	return (count);
}

static char	**free_array(char **res, int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
		free(res[i]);
		i ++;
	}
	free(res);
	return (NULL);
}

static char	**create_matrix(const char *s, char c, int nb_segments)
{
	char	**res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (nb_segments + 1));
	if (!res)
		return (NULL); 
	while (i < nb_segments)
	{
		len = get_length(s, c, j);
		res[i] = malloc (sizeof(char) * len + 1);
		if (!res[i])
			return (free_array(res, i));
		while (s[j] == c)
			j++;
		j += len;
		i ++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j; 
	int		k;
	int		n;

	i = 0;
	j = 0;
	n = get_number_segments(s, c);
	res = create_matrix(s, c, n); 
	if (!res)
		return (NULL);
	while (res[i] != NULL)
	{
		k = 0;
		while (s[j] == c)
			j ++;
		while ((s[j] != '\0') && (s[j] != c))
			res[i][k ++] = s[j ++];
		res[i][k] = '\0';
		i ++;
	}
	return (res);
}
