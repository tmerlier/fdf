/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 16:50:03 by tmerlier          #+#    #+#             */
/*   Updated: 2015/02/11 18:55:09 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define CTE_X   2
# define CTE_Y   2
# define WIN_H   1600
# define WIN_W   1800

# include <stdlib.h>

typedef struct	s_color
{
	char		r;
	char		g;
	char		b;
}				t_color;

typedef struct	s_gps
{
	int			x;
	int			y;
	int			z;
	t_color		color;
}				t_gps;

typedef struct	s_img
{
	int			bp;
	int			endian;
	int			size;
	char		*data;
	void		*ptr;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_gps		***gps;
	t_img		img;
}				t_mlx;

typedef struct	s_proj
{
	int			x;
	int			y;
	int			spc;
	char		*file;
}				t_proj;

void			get_coordinates(char *file, t_gps ****tab);
int				read_matrix(char *argv);
void			fdf(t_gps ****data);
size_t			wordcount(const char *s);
t_gps			**fdf_matrix(char *s, size_t y_pos, size_t word, size_t i);
void			draw(t_mlx *mlx, int i);
void			init_mlx(t_mlx *mlx, char *file_name);
t_proj			*get_proj(void);
void			mlx_put_point(t_img *img, t_gps *p);
void			mlx_set_color(t_color *c, unsigned int color);
void			mlx_clear(t_mlx *mlx);

#endif
