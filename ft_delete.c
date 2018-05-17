/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:29:09 by ilarbi            #+#    #+#             */
/*   Updated: 2018/03/05 23:56:21 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_delete(t_canvas *c)
{
	if (!c || !(c->mlx_ptr))
		return (0);
	((c->win) ? mlx_destroy_window(c->mlx_ptr, c->win) : 0);
	c->win = NULL;
	((c->map) ? free_matrix((void **)c->map) : 0);
	c->map = NULL;
	ft_strdel(&(c->maze));
	c->maze = NULL;
	return (1);
}
