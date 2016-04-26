/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:45:50 by tmerlier          #+#    #+#             */
/*   Updated: 2015/02/07 15:48:07 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "fdf.h"

size_t			wordcount(const char *s)
{
	static size_t	word = 0;
	size_t			w;
	size_t			i;

	w = 0;
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-')
		{
			ft_putstr_fd("Bad File.\n", 2);
			exit (0);
		}
		while (s[i] == ' ' && s[i])
			i++;
		if (s[i])
			w++;
		while (s[i] != ' ' && s[i])
			i++;
	}
	if (w > word)
		word = w;
	return (word);
}

static t_gps	*struct_up(char *s, int x, int y)
{
	t_gps	*new_pos;
	char	*str;
	int		max;

	max = 0;
	if (s == NULL)
		return (NULL);
	while (s[max] != ' ' && s[max])
		max++;
	str = (char *)malloc((max + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strncpy(str, s, max);
	str[max] = '\0';
	if ((new_pos = (t_gps *)malloc(sizeof(t_gps))) == NULL)
		return (NULL);
	new_pos->x = x;
	new_pos->y = y;
	new_pos->z = ft_atoi(str);
	ft_memset(&new_pos->color, sizeof(t_color), 3);
	if (new_pos->z <= 9 && new_pos->z > 0)
		new_pos->z += 10;
	free (str);
	return (new_pos);
}

t_gps			**fdf_matrix(char *s, size_t y_pos, size_t word, size_t i)
{
	int		x_pos;
	t_gps	**pos;
	t_gps	*temp;

	x_pos = 0;
	pos = (t_gps **)malloc((word + 1) * sizeof(t_gps *));
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		temp = struct_up(s + i, x_pos, y_pos);
		if (s[i] == 0 && x_pos == 0 && temp == NULL)
			pos[0] = NULL;
		else if (temp != 0)
		{
			pos[x_pos] = temp;
			x_pos++;
		}
		while (s[i] != ' ' && s[i])
			i++;
	}
	pos[x_pos] = 0;
	return (pos);
}
