/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:56:59 by ilarbi            #+#    #+#             */
/*   Updated: 2018/03/06 00:08:49 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	redraw(t_canvas *c)
{
	ft_bzero(c->view_color_vector, sizeof(unsigned int) * HEIGHT * WIDTH);
	raycaster(c);
}

void	motion(int keycode, t_canvas *c)
{
	double		mot;
	t_double	pos;
	t_double	newpos;

	mot = 0.2;
	newpos.y = c->p.pos.y;
	newpos.x = c->p.pos.x;
	pos = newpos;
	newpos.y = ((keycode == 126) ? (pos.y + c->p.dir.y * mot)
	: (pos.y - c->p.dir.y * mot));
	newpos.x = ((keycode == 126) ? (pos.x + c->p.dir.x * mot)
	: (pos.x - c->p.dir.x * mot));
	if (newpos.y >= 0 && (newpos.y < c->h) &&
	((c->map[(int)newpos.y][(int)c->p.pos.x] == '0')
	|| (c->map[(int)newpos.y][(int)c->p.pos.x] == '5')))
		c->p.pos.y = newpos.y;
	if (newpos.x >= 0 && (newpos.x < c->w)
	&& ((c->map[(int)c->p.pos.y][(int)newpos.x] == '0')
	|| (c->map[(int)c->p.pos.y][(int)newpos.x] == '5')))
		c->p.pos.x = newpos.x;
}

void	rotation(int keycode, t_canvas *c)
{
	t_px	pos;
	double	rot;
	double	prevdirx;
	double	prevplanex;

	pos.y = (int)c->p.pos.y;
	pos.x = (int)c->p.pos.x;
	prevdirx = c->p.dir.x;
	prevplanex = c->plane.x;
	rot = 0.15;
	c->p.dir.x = ((keycode == 124) ?
	(c->p.dir.x * cos(-rot) - c->p.dir.y * sin(-rot))
	: (c->p.dir.x * cos(rot) - c->p.dir.y * sin(rot)));
	c->p.dir.y = ((keycode == 124) ?
	(prevdirx * sin(-rot) + c->p.dir.y * cos(-rot))
	: (prevdirx * sin(rot) + c->p.dir.y * cos(rot)));
	c->plane.x = ((keycode == 124) ?
	(c->plane.x * cos(-rot) - c->plane.y * sin(-rot))
	: (c->plane.x * cos(rot) - c->plane.y * sin(rot)));
	c->plane.y = ((keycode == 124) ?
	(prevplanex * sin(-rot) + c->plane.y * cos(-rot))
	: (prevplanex * sin(rot) + c->plane.y * cos(rot)));
}

int		keypressed(int keycode, t_canvas *c)
{
	if (keycode == 53)
		ft_getout(c, "");
	else if (keycode == 126 || keycode == 125)
		motion(keycode, c);
	else if (keycode == 123 || keycode == 124)
		rotation(keycode, c);
	redraw(c);
	display(c);
	return (1);
}

void	display(t_canvas *c)
{
	mlx_put_image_to_window(c->mlx_ptr, c->win, c->view, 0, 0);
	mlx_hook(c->win, 2, 0, keypressed, (void *)c);
	mlx_hook(c->win, 17, 0, ft_getout, (void *)c);
	mlx_loop(c->mlx_ptr);
}
