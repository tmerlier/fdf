/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 16:52:10 by tmerlier          #+#    #+#             */
/*   Updated: 2015/02/10 14:41:33 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include "fdf.h"

t_proj	*get_proj(void)
{
	static t_proj		*proj;

	if (proj == NULL)
	{
		if ((proj = (t_proj *)malloc(sizeof(t_proj))) == NULL)
			exit(1);
		proj->x = 25;
		proj->y = -15;
		proj->spc = 10;
	}
	return (proj);
}

t_mlx	*init_t_mlx(void)
{
	t_mlx	*data;

	if ((data = (t_mlx *)malloc(sizeof(t_mlx))) == NULL)
		exit (0);
	data->mlx = NULL;
	data->win = NULL;
	data->gps = NULL;
	return (data);
}

int		main(int argc, char **argv)
{
	t_mlx	*data;

	data = init_t_mlx();
	if (argc == 2)
	{
		get_proj()->file = argv[1];
		get_coordinates(argv[1], &data->gps);
		fdf(&data->gps);
		init_mlx(data, argv[1]);
	}
	else
	{
		write(2, "usage : ", 8);
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, " file1.\n", 8);
		return (0);
	}
	return (0);
}
