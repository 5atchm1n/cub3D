/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:35:53 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/17 19:47:49 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		cub_check_color(t_color color)
{
	if (color.rgb.r > 255 || color.rgb.r < 0)
		return (0);
	if (color.rgb.g > 255 || color.rgb.g < 0)
		return (0);
	if (color.rgb.b > 255 || color.rgb.b < 0)
		return (0);
	return (1);
}

void			cub_init_world(t_world *world, t_mlx mlx, char *map_path,
		t_error *error)
{
	world->info.offset = (float)mlx.res.x / (float)world->info.msize.x;
	world->map = cub_copy_map(map_path, world);
	if (world->map == NULL)
		return (cub_error_set(error, INV_MAP));
	world->info.scount = cub_nobject(world);
	if (!(cub_check_color(world->info.floor))
			|| !(cub_check_color(world->info.ceiling)))
		return (cub_error_set(error, INV_RGB));
	world->info.floor.color = cub_rgb_to_int(world->info.floor);
	world->info.ceiling.color = cub_rgb_to_int(world->info.ceiling);
}

void			cub_test_xpm(t_cub *game, t_error *error)
{
	t_img		img;
	int			i;

	i = 0;
	while (i < TEXTURES)
	{
		img.img = mlx_xpm_file_to_image(game->mlx.win.mlx,
				game->world.objs.tpath[i], &img.x, &img.endian);
		if (img.img == NULL)
			return (cub_error_set(error, MLX_ERR2));
		mlx_destroy_image(game->mlx.win.mlx, img.img);
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		img.img = mlx_xpm_file_to_image(game->mlx.win.mlx,
				game->world.objs.spath[i], &img.x, &img.endian);
		if (img.img == NULL)
			return (cub_error_set(error, MLX_ERR2));
		mlx_destroy_image(game->mlx.win.mlx, img.img);
		i++;
	}
}

void			cub_start_mlx(t_mlx *mlx)
{
	mlx->win.win = mlx_new_window(mlx->win.mlx, mlx->res.x,
			mlx->res.y, "cub3D");
	mlx->on = 1;
}

void			cub_init_structs(t_cub *game)
{
	game->mlx.buffer = NULL;
	game->mlx.win.mlx = NULL;
	game->mlx.img.img = NULL;
	game->mlx.img.add = NULL;
	game->world.sprite = NULL;
	game->world.map = NULL;
	game->world.objs.tex = NULL;
	game->world.objs.spr = NULL;
	game->world.objs.sky = NULL;
	game->world.objs.weapons = NULL;
	game->world.objs.skybox = NULL;
	game->world.objs.ground = NULL;
	game->world.objs.tpath = NULL;
	game->world.objs.spath = NULL;
	game->world.objs.bpath = NULL;
	game->world.objs.skypath = NULL;
	game->world.info.zbuffer = NULL;
}
