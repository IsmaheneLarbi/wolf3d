/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:16:53 by ilarbi            #+#    #+#             */
/*   Updated: 2018/03/05 23:56:41 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_dy(t_canvas *c, t_ray r, t_double pos)
{
	int		mapy;

	c->ya = sqrt(1 + (r.dir.x * r.dir.x) / (r.dir.y * r.dir.y));
	pos.y = c->p.pos.y;
	mapy = (int)c->p.pos.y;
	if (r.dir.y < 0)
	{
		c->move.y = -1;
		c->dy = (pos.y - mapy) * c->ya;
	}
	else
	{
		c->move.y = 1;
		c->dy = (mapy + 1.0 - pos.y) * c->ya;
	}
}

void	set_dx(t_canvas *c, t_ray r, t_double pos)
{
	int		mapx;

	c->xa = sqrt(1 + (r.dir.y * r.dir.y) / (r.dir.x * r.dir.x));
	pos.x = c->p.pos.x;
	mapx = (int)c->p.pos.x;
	if (r.dir.x < 0)
	{
		c->move.x = -1;
		c->dx = (pos.x - mapx) * c->xa;
	}
	else
	{
		c->move.x = 1;
		c->dx = (mapx + 1.0 - pos.x) * c->xa;
	}
}

void	render(t_canvas *c, t_ray r, t_px map, t_double pos)
{
	double			wall_x;
	t_px			t;
	int				d;
	unsigned int	color;

	launch(c, &r, map, pos);
	wall_x = ((c->hit == 'x') ? (c->p.pos.y + r.dist * r.dir.y)
	: (c->p.pos.x + r.dist * r.dir.x));
	wall_x = wall_x - (int)wall_x;
	t.x = (int)(wall_x * 64.0);
	if (c->hit == 'x' && r.dir.x > 0)
		t.x = 64.0 - t.x - 1;
	if (c->hit == 'y' && r.dir.y < 0)
		t.x = 64.0 - t.x - 1;
	while (r.highpx.y < r.lowpx.y)
	{
		d = r.highpx.y * 256 - HEIGHT * 128 + r.wall_len * 128;
		t.y = ((d * 64.0) / r.wall_len) / 256;
		color = applytext(c, c->move, t, map);
		c->view_color_vector[r.highpx.y * WIDTH + r.highpx.x] = color;
		r.highpx.y++;
	}
}

void	dda(t_canvas *c, t_ray r, t_double pos)
{
	t_px		map;

	c->wall = 0;
	map.y = (int)c->p.pos.y;
	map.x = (int)c->p.pos.x;
	while (!c->wall)
	{
		if (c->dx < c->dy)
		{
			c->dx += c->xa;
			map.x += c->move.x;
			c->hit = 'x';
		}
		else
		{
			c->dy += c->ya;
			map.y += c->move.y;
			c->hit = 'y';
		}
		if (map.y >= 0 && map.x >= 0 && map.y < c->h && map.x < c->w
			&& (c->map[map.y][map.x] - 48) > 0 && (c->map[map.y][map.x] != '5'))
			c->wall = 1;
	}
	render(c, r, map, pos);
}

void	raycaster(t_canvas *c)
{
	t_ray	r;

	r.id = 0;
	c->pos.y = c->p.pos.y;
	c->pos.x = c->p.pos.x;
	while (r.id < WIDTH)
	{
		r.alpha = 2 * r.id / (double)WIDTH - 1;
		r.dir.y = c->p.dir.y + c->plane.y * r.alpha;
		r.dir.x = c->p.dir.x + c->plane.x * r.alpha;
		((r.dir.y) ? set_dy(c, r, c->pos) : 0);
		((r.dir.x) ? set_dx(c, r, c->pos) : 0);
		dda(c, r, c->pos);
		r.id++;
	}
}
