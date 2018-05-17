/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaceoff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:07:56 by ilarbi            #+#    #+#             */
/*   Updated: 2018/01/10 20:46:19 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*spaceoff(char *line)
{
	int		i;
	int		j;
	char	*spacefree;

	i = 0;
	j = i;
	if (!line)
		return (NULL);
	while (line[i + j])
		((line[i + j] != ' ') ? (j += 1) : (i += 1));
	if (!(spacefree = malloc(sizeof(char) * (j + 1))))
		exit(1);
	spacefree[j] = 0;
	j--;
	while (j >= 0)
	{
		if (line[i + j] != ' ')
		{
			spacefree[j] = line[i + j];
			j--;
		}
		else
			i--;
	}
	return (spacefree);
}
