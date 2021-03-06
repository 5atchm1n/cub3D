/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_load_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:08:55 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 03:48:48 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_nobject(t_world *world)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < world->info.msize.y)
	{
		j = 0;
		while (j < world->info.msize.x)
		{
			if (world->map[i][j] == '2' ||
				world->map[i][j] == '3' ||
				world->map[i][j] == '4')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	cub_init_object(t_world *world, t_error *error)
{
	int	i;
	int	j;

	i = 0;
	world->objs.spr = (int **)malloc(sizeof(int *) * SPRITES);
	if (world->objs.spr == NULL)
		return (cub_error_set(error, MEM_FAIL));
	while (i < SPRITES)
	{
		world->objs.spr[i] = (int *)malloc(sizeof(int) * (SPRITE_W * SPRITE_H));
		if (world->objs.spr[i] == NULL)
			return (cub_error_set(error, MEM_FAIL));
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		j = 0;
		while (j < SPRITE_W * SPRITE_H)
		{
			world->objs.spr[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	cub_set_object(t_sprite *sprite, char *map_char)
{
	if (sprite->id == 0)
	{
		sprite->udiv = 1;
		sprite->vdiv = 1;
		sprite->vmove = 0.0;
	}
	if (sprite->id == 1)
	{
		sprite->udiv = 4;
		sprite->vdiv = 4;
		sprite->vmove = 256.0;
		*map_char = '0';
	}
	if (sprite->id == 2)
	{
		sprite->udiv = 2;
		sprite->vdiv = 2;
		sprite->vmove = 256.0;
		*map_char = '0';
	}
}

static void	cub_set_object_init(t_world *world, int x, int i, int j)
{
	world->sprite[x].x = (double)j + 0.5;
	world->sprite[x].y = (double)i + 0.5;
	world->sprite[x].id = world->map[i][j] - 48 - 2;
	world->sprite[x].state = 0;
	world->sprite[x].dist = 0.0;
}

void	cub_load_objects(t_world *world)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	world->sprite = malloc(sizeof(t_sprite) * world->info.scount);
	ft_memset(world->sprite, 0, sizeof(t_sprite));
	while (i < world->info.msize.y)
	{
		j = 0;
		while (j < world->info.msize.x)
		{
			if (cub_issprite(world->map[i][j]))
			{
				cub_set_object_init(world, x, i, j);
				cub_set_object(&world->sprite[x], &world->map[i][j]);
				x++;
			}
			j++;
		}
		i++;
	}
}
