/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:17:48 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/05 20:57:38 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_sprite_order(t_sort *sort, int count)
{
	t_sort		tmp;
	int			i;
	int			j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count - 1)
		{
			if (sort[j].dist < sort[j + 1].dist)
			{
				tmp.dist = sort[j].dist;
				sort[j].dist = sort[j + 1].dist;
				sort[j + 1].dist = tmp.dist;
				tmp.order = sort[j].order;
				sort[j].order = sort[j + 1].order;
				sort[j + 1].order = tmp.order;
			}
			j++;
		}
		i++;
	}
}

void			ft_sort_sprites(t_objs *s, int count)
{
	t_sort		*tmp;
	int			i;

	tmp = malloc(sizeof(t_sort) * count);
	i = 0;
	while (i < count)
	{
		tmp[i].dist = s->dist[i];
		tmp[i].order = s->order[i];
		i++;
	}
	ft_sprite_order(tmp, count);
	i = 0;
	while (i < count)
	{
		s->dist[i] = tmp[i].dist;
		s->order[i] = tmp[i].order;
		i++;
	}
	free(tmp);
}
