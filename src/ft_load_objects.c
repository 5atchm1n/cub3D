/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:08:55 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/04 06:32:35 by sshakya          ###   ########.fr       */
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
	while (i < world->size_y)
	{
		j = 0;
		while (j < world->size_x)
		{
			if (world->map[i][j] > '1')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void			ft_init_object_pos(t_world *world)
{
	int			i;
	int			num;

	num = ft_nobject(world);
	world->sprite = malloc(sizeof(t_sprite) * num);
	i = 0;
	while (i < num)
	{
		world->sprite[i].x = 0;
		world->sprite[i].y = 0;
		world->sprite[i].id = 0;
				i++;
	}
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
	while (i < world->size_y)
	{
		j = 0;
		while (j < world->size_x)
		{
			if (world->map[i][j] == '2')
			{
				world->sprite[x].x = j + 0.5;
				world->sprite[x].y = i + 0.5;
				world->sprite[x].id = world->map[i][j] - 48 - 2;
				world->sprite[x].udiv = 1;
				world->sprite[x].vdiv = 1;
				world->sprite[x].vmove = 0.0;

				printf("obj[%d] : x = %.5f\n", x, world->sprite[x].x);
				printf("obj[%d] : y = %.5f\n", x, world->sprite[x].y);
				printf("obj[%d] : id = %d\n", x, world->sprite[x].id);
				printf("obj[%d] : udiv = %d\n", x, world->sprite[x].udiv);
				printf("obj[%d] : vdiv = %d\n", x, world->sprite[x].vdiv);
				printf("obj[%d] : vmove = %.5f\n", x, world->sprite[x].vmove);
				x++;
			}
			j++;
		}
		i++;
	}
}
