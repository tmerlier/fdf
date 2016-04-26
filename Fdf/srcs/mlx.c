/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 10:32:06 by rbernand          #+#    #+#             */
/*   Updated: 2015/02/11 14:51:33 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void		mlx_set_color(t_color *c, unsigned int color)
{
	c->r = (0x00FF0000 & color) >> 16;
	c->g = (0x0000FF00 & color) >> 8;
	c->b = 0x000000FF & color;
}

void		mlx_put_point(t_img *img, t_gps *p)
{
	if (p->x < 0
		|| p->y < 0
		|| p->y >= WIN_H
		|| p->x >= WIN_W)
		return ;
	if (img->endian == 0)
	{
		img->data[(p->y * img->size) + p->x * (img->bp / 8)] = p->color.b;
		img->data[(p->y * img->size) + p->x * (img->bp / 8) + 1] = p->color.g;
		img->data[(p->y * img->size) + p->x * (img->bp / 8) + 2] = p->color.r;
	}
	else
	{
		img->data[(p->y * img->size) + p->x * (img->bp / 8)] = p->color.r;
		img->data[(p->y * img->size) + p->x * (img->bp / 8) + 1] = p->color.g;
		img->data[(p->y * img->size) + p->x * (img->bp / 8) + 2] = p->color.b;
	}
}
