/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 16:57:33 by tmerlier          #+#    #+#             */
/*   Updated: 2015/02/07 14:56:49 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <libft.h>
#include "fdf.h"

int			open_file(char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr_fd("permission denied: ", 2);
		ft_putstr_fd(file, 2);
		ft_putchar_fd('\n', 2);
		exit (0);
	}
	return (fd);
}

void		close_file(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() fail.\n", 2);
		exit (0);
	}
}

void		get_coordinates(char *file, t_gps ****gps)
{
	int			fd;
	size_t		i;
	size_t		x;
	char		*matrix;
	size_t		lines;

	lines = 0;
	i = 0;
	fd = open_file(file);
	while (get_next_line(fd, &matrix) && ++lines)
		x = wordcount(matrix);
	close_file(fd);
	fd = open_file(file);
	if ((*gps = (t_gps ***)malloc((lines + 1) * sizeof(t_gps **))) == NULL
		|| lines == 0)
		exit (0);
	while (get_next_line(fd, &matrix))
	{
		(*gps)[i] = fdf_matrix(matrix, i, x, 0);
		i++;
		ft_strdel(&matrix);
	}
	(*gps)[i] = NULL;
}
