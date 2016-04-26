/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:56:06 by tmerlier          #+#    #+#             */
/*   Updated: 2015/02/10 14:52:42 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include "fdf.h"

int			calculate(int tmp_z, int tmp_x, int tmp_y)
{
	int		spc;

	spc = get_proj()->spc;
	return ((-tmp_z + (CTE_X / 2) * tmp_x + (CTE_Y / 2) * tmp_y) * spc);
}

int			key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		exit (0);
	if (keycode == 65361)
		get_proj()->x -= 5;
	if (keycode == 65362)
		get_proj()->y -= 5;
	if (keycode == 65363)
		get_proj()->x += 5;
	if (keycode == 65364)
		get_proj()->y += 5;
	if (keycode == 65451)
		get_proj()->spc += 1;
	if (keycode == 65453)
		get_proj()->spc -= 1;
	get_proj()->spc = get_proj()->spc == 0 ? 1 : get_proj()->spc;
	mlx_clear(mlx);
	get_coordinates(get_proj()->file, &mlx->gps);
	fdf(&mlx->gps);
	draw(mlx, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.ptr, 0, 0);
	return (0);
}

int			expose_hook(t_mlx *mlx)
{
	draw(mlx, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.ptr, 0, 0);
	return (0);
}

void		init_mlx(t_mlx *mlx, char *file_name)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_H, WIN_H, file_name);
	mlx->img.ptr = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	if (mlx->img.ptr == NULL)
		return ;
	if ((mlx->img.data = mlx_get_data_addr(mlx->img.ptr,
											&(mlx->img.bp),
											&(mlx->img.size),
											&(mlx->img.endian))) == NULL)
		return ;
	mlx_expose_hook(mlx->win, expose_hook, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->mlx);
}

void		fdf(t_gps ****gps)
{
	int		tmp_x;
	int		tmp_y;
	int		tmp_z;
	int		j;
	t_gps	***tab;

	tab = *gps;
	while (tab && (*tab))
	{
		j = 0;
		while ((*tab)[j])
		{
			tmp_x = get_proj()->x + (*tab)[j]->x;
			tmp_y = get_proj()->y + (*tab)[j]->y;
			tmp_z = (*tab)[j]->z / 9;
			(*tab)[j]->x = ((CTE_X * tmp_x - CTE_Y * tmp_y) * get_proj()->spc);
			(*tab)[j]->y = calculate(tmp_z, tmp_x, tmp_y);
			j++;
		}
		tab++;
	}
}
