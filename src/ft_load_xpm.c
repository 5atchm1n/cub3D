/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:07:11 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/31 22:36:39 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_load_xpm(t_cub *game, int *tex, char *path, t_img *img)
{
	int		x;
	int		y;

	img->img = mlx_xpm_file_to_image(game->win, path, &img->x, &img->y);
	img->data = (char *)mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
	y = 0;
	while (y < img->y)
	{
		x = 0;
		while (x < img->x)
		{
			tex[img->y * y  + x] = img->data[img->y * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, img->img);
}

void		ft_load_textures(t_cub *game)
{
	t_img	img;

	ft_load_xpm(game, game->txt[0], "textures/brick.xpm", &img);
	ft_load_xpm(game, game->txt[1], "textures/purplestone.xpm", &img);
	ft_load_xpm(game, game->txt[2], "textures/colorstone.xpm", &img);
	ft_load_xpm(game, game->txt[3], "textures/blue_brick.xpm", &img);
}
