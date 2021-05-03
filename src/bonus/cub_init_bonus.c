/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:50:33 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/04 00:28:12 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_init_sky_ground(t_world *world, t_error *error)
{
	int			i;

	world->objs.ground = (int *)malloc(sizeof(int) * (TEX_X * TEX_Y));
	if (world->objs.ground == NULL)
		return (cub_error_set(error, MEM_FAIL));
	world->objs.sky = (int *)malloc(sizeof(int) * (TEX_X * TEX_Y));
	if (world->objs.sky == NULL)
		return (cub_error_set(error, MEM_FAIL));
	world->objs.skybox = (int *)malloc(sizeof(int) * (SKY_X * SKY_Y));
	if (world->objs.skybox == NULL)
		return (cub_error_set(error, MEM_FAIL));
	i = 0;
	while (i < TEX_X * TEX_Y)
	{
		world->objs.ground[i] = 0;
		world->objs.sky[i] = 0;
		i++;
	}
	i = 0;
	while (i < SKY_X * SKY_Y)
	{
		world->objs.skybox[i] = 0;
		i++;
	}
}

static void		cub_init_weapon(t_world *world, t_error *error)
{
	int			i;

	world->objs.weapons = (int **)malloc(sizeof(int *) * WEAPONS * 2);
	if (world->objs.weapons == NULL)
		return (cub_error_set(error, MEM_FAIL));
	i = 0;
	while (i < WEAPONS * 2)
	{
		world->objs.weapons[i] = (int *)malloc(sizeof(int) * (TEX_X * TEX_Y));
		if (world->objs.weapons[i] == NULL)
			return (cub_error_set(error, MEM_FAIL));
		i++;
	}
	i = 0;
	while (i < TEX_X * TEX_Y)
	{
		world->objs.weapons[0][i] = 0;
		world->objs.weapons[1][i] = 0;
		i++;
	}
}

void			cub_init_bonus(t_world *world, t_mlx *mlx, t_error *error)
{
	t_img		img;

	cub_init_weapon(world, error);
	cub_init_sky_ground(world, error);
	cub_load_xpm(mlx, world->objs.sky, "textures/wall42-5-64x64.xpm", &img);
	cub_load_xpm(mlx, world->objs.ground, "textures/wall6-64x64.xpm", &img);
	cub_load_xpm(mlx, world->objs.skybox, "textures/skybox.xpm", &img);
	cub_load_xpm(mlx, world->objs.weapons[0], "textures/knife.xpm", &img);
	cub_load_xpm(mlx, world->objs.weapons[1], "textures/knife-2.xpm", &img);
}
