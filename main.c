/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:04:31 by ilarbi            #+#    #+#             */
/*   Updated: 2018/03/05 23:29:04 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_canvas	c;

	if (argc != 2)
		return (1);
	init(&c, argv[1]);
	raycaster(&c);
	display(&c);
	return (0);
}
