/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:28:32 by ilarbi            #+#    #+#             */
/*   Updated: 2018/03/05 23:29:17 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cast_floor_ceil(t_canvas *c, t_px highpx, t_px lowpx)
{
	t_px	p0;
	t_px	p1;

	if (!c)
		return ;
	p0.y = 0;
	p0.x = highpx.x;
	p1.y = HEIGHT - 1;
	p1.x = lowpx.x;
	ft_draw_line(*c, p0, highpx, 0xB0E0E6);
	ft_draw_line(*c, lowpx, p1, 0x6E470B);
}

void	launch(t_canvas *c, t_ray *r, t_px map, t_double pos)
{
	r->dist = ((c->hit == 'x') ?
	((map.x - pos.x + (1 - c->move.x) / 2) / r->dir.x)
	: ((map.y - pos.y + (1 - c->move.y) / 2) / r->dir.y));
	r->wall_len = (int)ft_abs(HEIGHT / r->dist);
	r->highpx.y = (((-r->wall_len / 2 + HEIGHT / 2) < 0) ? 0
		: (-r->wall_len / 2 + HEIGHT / 2));
	r->lowpx.x = r->id;
	r->highpx.x = r->id;
	r->lowpx.y = (((r->wall_len / 2 + HEIGHT / 2) >= HEIGHT) ? (HEIGHT - 1)
		: (r->wall_len / 2 + HEIGHT / 2));
	cast_floor_ceil(c, r->highpx, r->lowpx);
}
