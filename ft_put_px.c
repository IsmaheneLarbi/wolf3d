/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_px.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:50:13 by ilarbi            #+#    #+#             */
/*   Updated: 2018/03/05 23:27:21 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	int	ft_is_valid(int index)
{
	return ((index >= 0 && index < WIDTH * HEIGHT) ? 1 : 0);
}

int			ft_put_px(t_canvas c, t_px p, unsigned int color)
{
	int	index;

	if (p.y < 0 || p.x < 0)
		return (0);
	index = p.y * WIDTH + p.x;
	if (ft_is_valid(index) && color <= 16777215)
		c.view_color_vector[index] = color;
	else
		return (0);
	return (1);
}
