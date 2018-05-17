/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:07:56 by ilarbi            #+#    #+#             */
/*   Updated: 2018/03/05 23:27:55 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "minilibx_macos/mlx.h"
# include "printf/ft_printf.h"
# include <math.h>
# define WIDTH 1280
# define HEIGHT 720
# define TS 8
# define WH 64

typedef	struct s_px		t_px;
typedef	struct s_double	t_double;
typedef struct s_player	t_player;
typedef	struct s_ray	t_ray;
typedef	struct s_canvas	t_canvas;
typedef	struct s_text	t_text;

struct					s_px
{
	int					y;
	int					x;
};

struct					s_double
{
	double				y;
	double				x;
};

struct					s_player
{
	t_double			pos;
	t_double			dir;
};

struct					s_ray
{
	int					id;
	t_px				pos;
	t_double			dir;
	double				alpha;
	double				dist;
	int					wall_len;
	t_px				highpx;
	t_px				lowpx;
};

struct					s_text
{
	unsigned int		*t1;
	unsigned int		*t2;
	unsigned int		*t3;
	unsigned int		*t4;
};

struct					s_canvas
{
	int					fd;
	char				*ens_name;
	int					h;
	int					w;
	char				*maze;
	char				**map;
	int					a;
	int					b;
	int					c;
	void				*mlx_ptr;
	void				*win;
	void				*img;
	void				*view;
	unsigned int		*img_color_vector;
	unsigned int		*view_color_vector;
	t_text				text;
	t_player			p;
	t_double			plane;
	double				dx;
	double				dy;
	double				xa;
	double				ya;
	t_px				move;
	int					wall;
	int					hit;
	t_double			pos;
};

t_canvas				*init(t_canvas *c, char *path);
void					gettextures(t_canvas *c);
int						ft_put_px(t_canvas c, t_px p, unsigned int color);
void					ft_draw_line(t_canvas c,
						t_px px1, t_px px2, unsigned int color);
unsigned int			applytext(t_canvas *c, t_px move, t_px t, t_px map);
void					raycaster(t_canvas *c);
void					display(t_canvas *c);
int						ft_delete(t_canvas *c);
int						ft_getout(t_canvas *c, char *msg);
void					draw_wall(t_canvas *c, t_px highpx, t_px lowpx,
						unsigned int color);
void					launch(t_canvas *c, t_ray *r, t_px map, t_double pos);

#endif
