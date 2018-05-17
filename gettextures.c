/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettextures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:54:31 by ilarbi            #+#    #+#             */
/*   Updated: 2018/03/05 23:56:08 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	gettextures(t_canvas *c)
{
	int	rows;
	int	cols;

	c->text.t1 = (unsigned int*)mlx_get_data_addr(
	mlx_xpm_file_to_image(c->mlx_ptr, "xpm/eridu01dark.xpm", &cols, &rows)
	, &c->a, &c->b, &c->c);
	c->text.t2 = (unsigned int*)mlx_get_data_addr(
	mlx_xpm_file_to_image(c->mlx_ptr, "xpm/eridu657.xpm", &cols, &rows),
	&c->a, &c->b, &c->c);
	c->text.t3 = (unsigned int*)mlx_get_data_addr(
	mlx_xpm_file_to_image(c->mlx_ptr, "xpm/eridu6935.xpm", &cols, &rows),
	&c->a, &c->b, &c->c);
	c->text.t4 = (unsigned int*)mlx_get_data_addr(
	mlx_xpm_file_to_image(c->mlx_ptr, "xpm/eridu835.xpm", &cols, &rows),
	&c->a, &c->b, &c->c);
}
