/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:35:53 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/16 10:58:04 by sshakya          ###   ########.fr       */
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
	world->offset = (float)mlx.res.x / (float)world->msize.x;
	world->map = cub_copy_map(map_path, world);
	world->scount = cub_nobject(world);
	if (!(cub_check_color(world->floor)) || !(cub_check_color(world->ceiling)))
		return (cub_error_set(error, INV_RGB));
	world->floor.color = cub_rgb_to_int(world->floor);
	world->ceiling.color = cub_rgb_to_int(world->ceiling);
}

void			cub_test_xpm(t_cub *game, t_error *error)
{
	t_img		img;
	int			i;

		i = 0;
	while (i < TEXTURES)
	{
		img.img = mlx_xpm_file_to_image(game->mlx.win.mlx, game->world.tpath[i],
				&img.x, &img.endian);
		if (img.img == NULL)
			return (cub_error_set(error, MLX_ERR2));
		mlx_destroy_image(game->mlx.win.mlx, img.img);
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		img.img = mlx_xpm_file_to_image(game->mlx.win.mlx,
				game->world.objpath[i], &img.x, &img.endian);
		if (img.img == NULL)
			return (cub_error_set(error, MLX_ERR2));
		mlx_destroy_image(game->mlx.win.mlx, img.img);
		i++;
	}
}

void			cub_init_mlx(t_mlx *mlx, t_error *error)
{
	int			screenx;
	int			screeny;

	mlx->win.mlx = mlx_init();
	if (mlx->win.mlx == NULL)
		return (cub_error_set(error, 14)); 
	mlx_get_screen_size(mlx->win.mlx, &screenx, &screeny);
	if (screenx < mlx->res.x)
		mlx->res.x = screenx;
	if (screeny < mlx->res.y)
		mlx->res.y = screeny;
	mlx->win.win = mlx_new_window(mlx->win.mlx, mlx->res.x,
			mlx->res.y, "cub3D");
	mlx->img.img = mlx_new_image(mlx->win.mlx, mlx->res.x,
			mlx->res.y);
	mlx->img.add = (int *)mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.len, &mlx->img.endian);
	mlx->on = 1;
}


