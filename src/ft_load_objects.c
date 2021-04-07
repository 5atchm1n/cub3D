/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:08:55 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/07 17:31:37 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_nobject(t_world *world)
{
	int			i;
	int			j;
	int			count;

	i = 0;
	count = 0;
	while (i < world->msize.y)
	{
		j = 0;
		while (j < world->msize.x)
		{
			if (world->map[i][j] == '2' || world->map[i][j] == '3')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void			ft_init_object(t_world *world)
{
	int			i;
	int			j;

	i = 0;
	world->obj = (int **)malloc(sizeof(int *) * SPRITES);
	while (i < SPRITES)
	{
		world->obj[i] = (int *)malloc(sizeof(int) * (SPRITE_W * SPRITE_H));
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		j = 0;
		while (j < SPRITE_W * SPRITE_H)
		{
			world->obj[i][j] = 0;
			j++;
		}
		i++;
	}
}

void			ft_load_objects(t_world *world)
{
	int			i;
	int			j;
	int			x;

	i = 0;
	x = 0;
	world->sprite = malloc(sizeof(t_sprite) * world->scount);
	while (i < world->msize.y)
	{
		j = 0;
		while (j < world->msize.x)
		{
			if (world->map[i][j] == '2' || world->map[i][j] == '3')
			{
				world->sprite[x].x = (double)j + 0.5;
				world->sprite[x].y = (double)i + 0.5;
				world->sprite[x].id = world->map[i][j] - 48 - 2;
				world->sprite[x].udiv = 1;
				world->sprite[x].vdiv = 1;
				world->sprite[x].vmove = 0.0;
				x++;
			}
			j++;
		}
		i++;
	}
}
