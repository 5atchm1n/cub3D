/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:31:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 03:35:28 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_draw(t_mlx *mlx)
{
	int	x;
	int	y;

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
	if (mlx->on == 1)
	{
		mlx_put_image_to_window(mlx->win.mlx, mlx->win.win, mlx->img.img, 0, 0);
		if (BONUS)
		{
			mlx_string_put(mlx->win.mlx, mlx->win.win,
				mlx->res.x - 50, mlx->res.y - 20, 0x00FFFFFF, "HEALTH");
		}
	}
}

void	cub_set_buffer_pixel(t_mlx *mlx, t_world world, t_objs obj, t_pixel *px)
{
	int	d;
	int	colour;
	int	sorted;

	px->y = obj.starty;
	sorted = world.sprite[obj.order[obj.index]].id;
	while (px->y < obj.endy)
	{
		d = (px->y - obj.voffset) * 256 - mlx->res.y * 128 + obj.spriteh * 128;
		px->tex_y = ((d * SPRITE_H) / obj.spriteh) / 256;
		colour = world.objs.spr[sorted][SPRITE_W * px->tex_y + px->tex_x];
		if ((colour & 0x00FFFFFF) != 0)
			mlx->buffer[px->y][px->x] = cub_set_shadow(colour, obj.ty);
		px->y += 1;
	}
}

int	cub_set_shadow(int colour, double dw)
{
	t_rgb	rgb;
	double	shade;

	shade = (10 - dw) / 10.0;
	if (shade < 0)
		shade = 0.01;
	rgb.r = ((colour & 0x00FF0000) >> 16) * shade;
	rgb.g = ((colour & 0x0000FF00) >> 8) * shade;
	rgb.b = (colour & 0x000000FF) * shade;
	if (BONUS)
		colour = (rgb.r << 16) + (rgb.g << 8) + rgb.b;
	return (colour);
}

void	cub_render(t_cub *game)
{
	if (BONUS)
	{
		cub_floor_casting(&game->player, &game->world, &game->mlx);
		cub_sprite_move(&game->world, &game->player);
	}
	cub_raycasting(game);
	cub_cast_sprites(game);
	if (BONUS)
		cub_hud(game);
	cub_draw(&game->mlx);
	cub_speed(game);
}
