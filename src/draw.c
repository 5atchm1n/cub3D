/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:31:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/15 15:29:03 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_img *img, int x, int y ,int color)
{
	char	*dst;

	dst = img->add + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
/*
void	background(t_cub *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->settings.res.x)
	{
		j = 0;
		while (j < game->settings.res.y)
		{
			my_pixel_put(&game->img, i, j, 0x00000000);
			j++;
		}
		i++;
	}
}
*/
void		put_wall(t_cub *game, int x, int y, int colour)
{
	int		k;
	int		l;
	int		offset;

	offset = game->settings.res.x / game->settings.size_x;
	k = 0;
	while (k < offset - 1)
	{
		l = 0;
		while (l < offset - 1)
		{
			my_pixel_put(&game->img, x * offset + k, y * offset + l, colour);
			l++;
		}
		k++;
	}
}

void	draw_map(t_cub *game)
{

	int i;
	int j;

	i = 0;
	while (i < game->settings.size_y)
	{
		j = 0;
		while (j < game->settings.size_x)
		{
			if (game->map[i][j] == '0')
				put_wall(game, j, i, 0x00000000);
			if (game->map[i][j] == ' ')
				put_wall(game, j, i, 0x000000FF);
			if (game->map[i][j] == '1')
				put_wall(game, j, i, 0x00FF0000);
			if (game->map[i][j] == '2')
				put_wall(game, j, i, 0x0000FF00);
			j++;
		}
		i++;
	}
}

void	my_player(t_img *img, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			my_pixel_put(img, x + i, y + j, 0x00FFFFFF);
			i++;
		}
		j++;
	}
}

void			fov_line(t_cub *game, double theta)
{
	int			l;
	double		x;
	double		y;

	l = 150;
	while(l > 0)
	{
		y = sin(theta) * l;
		x = cos(theta) * l;
		if (game->player.pos_y - y + 2 > 2)
			my_pixel_put(&game->img, game->player.pos_x + x + 2,
				game->player.pos_y - y + 2, 0x00FFFFFF);
		l--;
	}
//	printf("x = %f\n", x);
//	printf("y = %f\n", y);
//	printf("dir = %.8f\n", game->settings.dir);
}

void			player_fov(t_cub *game)
{
	double		fov;

	fov = game->player.dir + 0.3;
	while(fov > game->player.dir - 0.3)
	{
		fov_line(game, fov);
		fov -= 0.0005;
	}
	game->show = 1;
//	printf("x = %f\n", x);
//	printf("y = %f\n", y);
//	printf("dir = %.8f\n", game->settings.dir);
}

int		ft_update_fov(t_cub *game)
{
	if (game->player.move.turn_r)
		game->player.dir += 0.05;
	if (game->player.move.turn_l)
		game->player.dir -= 0.05;
		return (0);
}

int		ft_isempty(t_cub *game, int x, int y)
{
	int	grid_x;
	int	grid_y;
	int	offset;

	offset = game->settings.res.x / game->settings.size_x;
	grid_y = (game->player.pos_y + y) / offset;
	grid_x = (game->player.pos_x + x) / offset;

	printf("y = %d\n", grid_y);
	printf("x = %d\n", grid_x);
	printf("map = %d\n", game->map[grid_y][grid_x]);
	if (game->map[grid_y][grid_x] != '0')
	{	
		printf("map = %d\n", game->map[grid_y][grid_x]);
		return (0);
	}
	return (1);
}

int		ft_update_pos(t_cub *game)
{
	if (game->player.move.up && ft_isempty(game, 0, -2))
	{
		if (game->player.pos_y > 2)
			game->player.pos_y -= 2;
	}
	if (game->player.move.down && ft_isempty(game, 0, 2))
		game->player.pos_y += 2;
	if (game->player.move.left && ft_isempty(game, -2, 0))
		game->player.pos_x -= 2;
	if (game->player.move.right && ft_isempty(game, 2, 0))
		game->player.pos_x += 2;

	ft_update_fov(game);
//	background(game);
	draw_map(game);
	my_player(&game->img, game->player.pos_x, game->player.pos_y);
	player_fov(game);
	if (game->show == 1)
		mlx_put_image_to_window(game->win.mlx , game->win.win, game->img.img, 0 , 0);

	return (0);
}
