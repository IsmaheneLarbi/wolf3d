/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applytext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 03:14:04 by ilarbi            #+#    #+#             */
/*   Updated: 2018/03/05 23:55:51 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

unsigned int	t1(t_canvas *c, t_px move, t_px t)
{
	if (c->hit == 'x')
		return ((move.x > 0) ? (c->text.t2[64 * t.y + t.x])
				: c->text.t4[64 * t.y + t.x]);
	else if (c->hit == 'y')
		return ((move.y > 0) ? c->text.t1[64 * t.y + t.x]
				: c->text.t3[64 * t.y + t.x]);
	else
		return (0);
}

unsigned int	t2(t_canvas *c, t_px move, t_px t)
{
	if (c->hit == 'x')
		return ((move.x > 0) ? (c->text.t1[64 * t.y + t.x])
				: c->text.t2[64 * t.y + t.x]);
	else if (c->hit == 'y')
		return ((move.y > 0) ? c->text.t3[64 * t.y + t.x]
				: c->text.t4[64 * t.y + t.x]);
	else
		return (0);
}

unsigned int	t3(t_canvas *c, t_px move, t_px t)
{
	if (c->hit == 'x')
		return ((move.x > 0) ? (c->text.t4[64 * t.y + t.x])
		: c->text.t3[64 * t.y + t.x]);
	else if (c->hit == 'y')
		return ((move.y > 0) ? c->text.t2[64 * t.y + t.x]
		: c->text.t1[64 * t.y + t.x]);
	else
		return (0);
}

unsigned int	t4(t_canvas *c, t_px move, t_px t)
{
	if (c->hit == 'x')
		return ((move.x > 0) ? (c->text.t2[64 * t.y + t.x])
		: c->text.t1[64 * t.y + t.x]);
	else if (c->hit == 'y')
		return ((move.y > 0) ? c->text.t4[64 * t.y + t.x]
		: c->text.t3[64 * t.y + t.x]);
	else
		return (0);
}

unsigned int	applytext(t_canvas *c, t_px move, t_px t, t_px map)
{
	unsigned int color;

	color = 0;
	if (c->map[map.y][map.x] == '1')
		color = t1(c, move, t);
	else if (c->map[map.y][map.x] == '2')
		color = t2(c, move, t);
	else if (c->map[map.y][map.x] == '3')
		color = t3(c, move, t);
	else if (c->map[map.y][map.x] == '4' || c->map[map.y][map.x] - 48 > 5)
		color = t4(c, move, t);
	return (color);
}
