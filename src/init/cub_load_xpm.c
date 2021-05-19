/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_load_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:07:11 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 03:50:31 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_load_xpm(t_mlx *mlx, int *tex, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(mlx->win.mlx, path, &img->x, &img->y);
	img->add = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->len,
			&img->endian);
	y = 0;
	while (y < img->y)
	{
		x = 0;
		while (x < img->x)
		{
			tex[img->x * y + x] = img->add[img->x * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(mlx->win.mlx, img->img);
}

void	cub_load_textures(t_mlx *mlx, t_world *world)
{
	t_img	img;
	int		i;

	i = 0;
	while (i < TEXTURES)
	{
		cub_load_xpm(mlx, world->objs.tex[i], world->objs.tpath[i], &img);
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		cub_load_xpm(mlx, world->objs.spr[i], world->objs.spath[i], &img);
		i++;
	}
}
