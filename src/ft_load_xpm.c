/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:07:11 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/07 00:07:50 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_load_xpm(t_mlx *mlx, int *tex, char *path, t_img *img)
{
	int			x;
	int			y;

	img->img = mlx_xpm_file_to_image(mlx->win.mlx, path, &img->x, &img->y);
	if (img->img == NULL)
		printf("FAIL\n");
	img->add = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
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

void			ft_load_textures(t_mlx *mlx, t_world *world)
{
	t_img		img;
	int			i;

	i = 0;
	while (i < TEXTURES)
	{
		ft_load_xpm(mlx, world->tex[i], world->tpath[i], &img);
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		ft_load_xpm(mlx, world->obj[i], world->objpath[i], &img);
		i++;
	}
}
