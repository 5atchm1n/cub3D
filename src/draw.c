/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:31:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/13 01:49:42 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_img *img, int x, int y ,int color)
{
	char	*dst;

	dst = img->add + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	background(t_cub *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->settings.res.y)
	{
		i = 0;
		while (i < game->settings.res.x)
		{
			my_pixel_put(&game->img, i, j, 0x00000000);
			i++;
		}
		j++;
	}
}

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

void			player_fov(t_cub *game)
{
	double		fov;
	int			l;
	double		x;
	double		y;

	l = 25;
	fov = 0.6;

	while(l > 0)
	{
		x = sin(game->settings.dir) * l;
		y = cos(game->settings.dir) * l;
		my_pixel_put(&game->img, game->settings.pos_x + x + 2,
				game->settings.pos_y + y + 2, 0x00FFFFFF);
		l--;
	}
	printf("x = %f\n", x);
	printf("y = %f\n", y);
	printf("dir = %.8f\n", game->settings.dir);

}

int		ft_move(int keycode, t_cub *game)
{
	int	i;
	i = 0;
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(game->win.mlx, game->win.win);
	//	mlx_destroy_image(game->win.mlx, game->win.win);
		while(i < game->settings.size_y)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		exit(0);
	}
	if (keycode == 119)
	{
		if (game->settings.pos_y > 2)
			game->settings.pos_y -= 2;
	}
	if (keycode == 115)
		game->settings.pos_y += 2;
	if (keycode == 97)
		game->settings.pos_x -= 2;
	if (keycode == 100)
		game->settings.pos_x += 2;
	if (keycode == 65361)
		game->settings.dir += 0.1;
	if (keycode == 65363)
		game->settings.dir -= 0.1;

	background(game);
	draw_map(game);
	my_player(&game->img, game->settings.pos_x, game->settings.pos_y);
	player_fov(game);
	mlx_put_image_to_window(game->win.mlx , game->win.win, game->img.img, 0 , 0);

	return (0);
}
/*
int		mouse_hook(int button, int x, int y, t_win *win)
{
	if (win)
		write(1, "#", 1);
	printf("%d\t", button);
	printf("%d\t", x);
	printf("%d\t", y);
	return (0);
}
*/
/*
int		key_hook(int keycode, t_win *win)
{
	if (win && keycode)
		write(1 , "#", 1);
	printf("%d\n", keycode);
	
	return (0);
}
*/
