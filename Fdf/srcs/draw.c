/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 19:04:46 by tmerlier          #+#    #+#             */
/*   Updated: 2015/02/11 10:43:01 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static void	color_line(t_mlx *mlx, t_gps *p, int i, int j)
{
	if (mlx->gps[i][j]->z >= 10 && mlx->gps[i][j + 1]->z >= 10)
		mlx_set_color(&p->color, 0xFF0000);
	else if (mlx->gps[i][j]->z <= -1 && mlx->gps[i][j + 1]->z <= -1)
		mlx_set_color(&p->color, 0x0000FF);
	else if (mlx->gps[i][j]->z != mlx->gps[i][j + 1]->z)
		mlx_set_color(&p->color, 0xAA5555);
	else
		mlx_set_color(&p->color, 0xAAAAFF);
}

static void	color_line2(t_mlx *mlx, t_gps *p, int i, int j)
{
	if (mlx->gps[i][j]->z >= 10 && mlx->gps[i + 1][j]->z >= 10)
		mlx_set_color(&p->color, 0xFF0000);
	else if (mlx->gps[i][j]->z <= -1 && mlx->gps[i][i + 1]->z <= -1)
		mlx_set_color(&p->color, 0x0000FF);
	else if (mlx->gps[i][j]->z != mlx->gps[i + 1][j]->z)
		mlx_set_color(&p->color, 0xAA5555);
	else
		mlx_set_color(&p->color, 0xAAAAFF);
}

void		draw_straight(int i, int j, t_mlx *mlx)
{
	int		x;
	int		x1;
	int		y1;
	int		x2;
	t_gps	p;

	x1 = mlx->gps[i][j]->x;
	y1 = mlx->gps[i][j]->y;
	x2 = mlx->gps[i][j + 1]->x;
	x = x1;
	p.x = x;
	while (p.x <= x2)
	{
		p.y = (y1 + (((mlx->gps[i][j + 1]->y) - y1) * (p.x - x1) / (x2 - x1)));
		color_line(mlx, &p, i, j);
		mlx_put_point(&mlx->img, &p);
		p.x++;
	}
}

void		draw_straight2(int i, int j, t_mlx *mlx, int y2)
{
	int		x;
	int		x1;
	int		y1;
	int		x2;
	t_gps	p;

	x2 = mlx->gps[i][j]->x;
	y2 = mlx->gps[i][j]->y;
	y1 = mlx->gps[i + 1][j]->y;
	x1 = mlx->gps[i + 1][j]->x;
	x = x1;
	p.x = x;
	while (p.x <= x2)
	{
		p.y = (y1 + ((y2 - y1) * (p.x - x1) / (x2 - x1)));
		color_line2(mlx, &p, i, j);
		mlx_put_point(&mlx->img, &p);
		p.x++;
	}
}

void		draw(t_mlx *mlx, int i)
{
	int		j;
	t_gps	***tab;

	tab = mlx->gps;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j + 1])
		{
			draw_straight(i, j, mlx);
			j++;
		}
		i++;
	}
	i = 0;
	j = -1;
	while (tab[i][++j])
	{
		while (tab[i + 1])
		{
			draw_straight2(i, j, mlx, 0);
			i++;
		}
		i = 0;
	}
}
