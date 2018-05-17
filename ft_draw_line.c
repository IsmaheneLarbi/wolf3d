/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:45:36 by ilarbi            #+#    #+#             */
/*   Updated: 2018/03/05 23:27:09 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define DY (ft_abs(p1.y - p2.y))
#define DX (ft_abs(p1.x - p2.x))
#define D ((DY > DX) ? DY : DX)

void		ft_draw_line(t_canvas c, t_px p1, t_px p2, unsigned int color)
{
	t_px	p;
	int		incr_x;
	int		incr_y;
	int		err;
	int		i;

	i = 0;
	incr_y = ((p1.y < p2.y) ? 1 : -1);
	incr_x = ((p1.x < p2.x) ? 1 : -1);
	p = p1;
	err = D / 2;
	ft_put_px(c, p1, color);
	while (i < D)
	{
		((D == DY) ? (p.y += incr_y) : (p.x += incr_x));
		err += ((D == DY) ? DX : DY);
		if (err > D)
		{
			err -= D;
			((D == DY) ? (p.x += incr_x) : (p.y += incr_y));
		}
		ft_put_px(c, p, color);
		i++;
	}
	ft_put_px(c, p2, color);
}
