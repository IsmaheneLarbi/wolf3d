/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:05:56 by ilarbi            #+#    #+#             */
/*   Updated: 2018/03/05 23:54:44 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			getnbcols(char *line)
{
	int		i;
	int		nbcols;
	char	**row;

	i = 0;
	nbcols = 0;
	if (!(row = ft_strsplit(line, ' ')))
		return (-1);
	while (row[i])
	{
		if (ft_isdigit(ft_atoi(row[i]) + 48))
		{
			nbcols++;
			free(row[i]);
			row[i] = NULL;
			i++;
		}
		else
			return (0);
	}
	free(row);
	row = NULL;
	return (nbcols);
}

void		fillmap(t_canvas *c, char *rows)
{
	int		i;
	char	**maze;
	char	*freed;

	i = 0;
	maze = NULL;
	if (!(c->map = malloc(sizeof(char *) * (c->h + 1)))
			|| (!(maze = ft_strsplit(rows, '\n'))))
		ft_getout(c, "");
	c->map[c->h] = 0;
	while (maze[i])
	{
		if (!(c->map[i] = malloc(sizeof(char *) * (c->w + 1))))
			ft_getout(c, "");
		freed = spaceoff(maze[i]);
		ft_strcpy(c->map[i], freed);
		ft_strdel(&freed);
		ft_strdel(&maze[i]);
		i++;
	}
	free(maze);
	maze = NULL;
}

void		getmap(t_canvas *c)
{
	int		i;
	char	*row;
	char	*tofree;

	i = 0;
	if (!(c->maze = ft_strnew(0)))
		exit(1);
	while (get_next_line(c->fd, &row) > 0)
	{
		if (!i)
			c->w = getnbcols(row);
		else if (c->w != getnbcols(row))
			ft_getout(c, "invalid file :/ \n");
		c->maze = ft_strjoin_free(c->maze, 1, row, 1);
		tofree = ft_strdup("\n");
		c->maze = ft_strjoin_free(c->maze, 1, tofree, 1);
		i++;
	}
	c->h = i;
	if (!c->h || !c->w)
		exit(1);
	fillmap(c, c->maze);
	close(c->fd);
}

void		locateplayer(t_canvas *c)
{
	int		y;
	int		x;

	y = 0;
	while (y < c->h)
	{
		x = 0;
		while (x < c->w)
		{
			if (((y == 0 || y == c->h - 1) && c->map[y][x] <= 48)
			|| ((x == 0 || x == c->w - 1) && c->map[y][x] <= 48))
				ft_getout(c, "not surrounded by walls \n");
			if (c->map[y][x] == '5')
			{
				if (!c->p.pos.y && !c->p.pos.x && (c->p.pos.y = y + 0.5))
					c->p.pos.x = x + 0.5;
				else
					ft_getout(c, "too many players\n");
			}
			x++;
		}
		y++;
	}
	if (!c->p.pos.y)
		ft_getout(c, "Player location unspecified\n");
}

t_canvas	*init(t_canvas *c, char *path)
{
	if ((c->fd = open(path, O_RDONLY)) < 0)
		exit(1);
	getmap(c);
	c->p.pos.y = 0.;
	c->p.pos.x = 0.;
	c->p.dir.y = 0.;
	c->p.dir.x = -1.;
	c->plane.y = 0.66;
	c->plane.x = 0.;
	c->ens_name = path;
	if ((!(c->mlx_ptr = mlx_init()))
	|| (!(c->win = mlx_new_window(c->mlx_ptr, WIDTH, HEIGHT, c->ens_name)))
	|| (!(c->view = mlx_new_image(c->mlx_ptr, WIDTH, HEIGHT)))
	|| (!(c->view_color_vector =
		(unsigned int *)mlx_get_data_addr(c->view, &c->a, &c->b, &c->c))))
		ft_getout(c, "failed to initialize the canvas\n");
	locateplayer(c);
	gettextures(c);
	return (c);
}
