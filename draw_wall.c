/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 23:19:53 by ilarbi            #+#    #+#             */
/*   Updated: 2018/03/05 23:26:55 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_wall(t_canvas *c, t_px highpx, t_px lowpx, unsigned int color)
{
	while (highpx.y <= lowpx.y)
	{
		ft_put_px(*c, highpx, color);
		(highpx.y)++;
	}
}
