/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:31:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/06 23:26:30 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_draw(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < mlx->res.y)
	{
		x = 0;
		while (x < mlx->res.x)
		{
			mlx->img.add[y * mlx->res.x + x] = mlx->buffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->win.mlx, mlx->win.win, mlx->img.img, 0, 0);
}
