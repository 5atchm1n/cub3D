/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:18:44 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/24 02:31:48 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_verLine(int x, double drawStart, double drawEnd, int color, t_cub *game)
{
	double	start;
	start = drawStart;
	while (start < drawEnd)
	{
		my_pixel_put(&game->img, x, start, color);
		start = start + 1.0;
	}
}

void		ft_drawrays3D(t_cub *game)
{
	double	x;
	double	camerax;

/*	
	if (game->player.dir >= 0 && game->player.dir < M_PI)
	{
		dirx = cos(game->player.dir);
//		planex = 1 - sin(game->player.dir);
	}
	if (game->player.dir >= 0 && game->player.dir < M_PI_2)
	{
		diry = sin(game->player.dir);
//		planey = 0.66 - cos(game->player.dir);
	}
	if (game->player.dir >= M_PI && game->player.dir <= M_PI * 2)
	{
		dirx = 1 - cos(game->player.dir);
//		planex = 1 + sin(game->player.dir);
	}
	if (game->player.dir >=M_PI_2 && game->player.dir <= M_PI + M_PI_2)
	{	
		diry = 1 - sin(game->player.dir);
//		planey = 0.66 + cos(game->player.dir);
	}

	planex = 0;
	planey = 0.66;
*/
	x = 0;
	while (x < game->settings.res.x)
	{
		camerax = (2.0 * x )/ ((double)game->settings.res.x - 1.0);

		double raydirx = game->camera.dirx + game->camera.planex * camerax;
		double raydiry = game->camera.diry + game->camera.planey * camerax;
		
		int mapx = (int)(game->player.pos_x);
		int	mapy = (int)(game->player.pos_y);

		double sidedistx;
		double sidedisty;
		double deltadistx = sqrt(1 + (raydiry * raydiry) / (raydirx * raydirx));
		double deltadisty = sqrt(1 + (raydirx * raydirx) / (raydiry * raydiry));
/*		if ((int)x % 1200 == 0)
		{
		printf("dx = %.10f\n", dirx);
		printf("dy = %.10f\n", diry);
		printf("rx = %.10f\n", raydirx);
		printf("ry = %.10f\n", raydiry);
		printf("px = %.10f\n", planex);
		printf("px = %.10f\n", planey);
		printf("dlx%.10f\n", deltadistx);
		printf("dly%.10f\n", deltadisty);
		printf("cmrx = %.10f\n", camerax);
		printf("mapx= %d\n", mapx);
		printf("mapy= %d\n", mapy);
		}  */
		double distwall;

		int stepx;
		int	stepy;
		int	hit = 0;
		int side;

		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (game->player.pos_x - mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - game->player.pos_x) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedistx = (game->player.pos_y - mapy) * deltadisty;
		}
		else
		{
			stepy =1;
			sidedisty = (mapy + 1.0 - game->player.pos_y) * deltadisty;
		}
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}

			if (game->map[mapy][mapx] == '1')
				hit = 1;
		}
		if (side == 0)
			distwall = (mapx - game->player.pos_x + (1 - stepx) / 2) / raydirx;
		else	
			distwall = (mapy - game->player.pos_y + (1 - stepy) / 2) / raydiry;

		int	lineheight = (int)((double)game->settings.res.y / distwall);
		int drawStart = -lineheight / 2 + game->settings.res.y / 2;
		if(drawStart < 0)drawStart = 0;
			int drawEnd = lineheight / 2 + game->settings.res.y / 2;
		if(drawEnd >= game->settings.res.y)
			drawEnd = game->settings.res.y - 1;

/*
		int color;
		if (raydirx > 0)
			color = 0x00FFFFFF;
		if (raydirx <= 0)
			color = 0x00FFFF00;
		if (raydiry >= 0)
			color = 0x00FF0000;
		if (raydiry < 0)
			color = 0x00F00F00;
*/

		//give x and y sides different brightness
		int color;
		color = 0x00FF0000;
		if (side == 1)
		{
			color = color / 2;
		}

		//draw the pixels of the stripe as a vertical line
		ft_verLine(x, drawStart, drawEnd, color, game);
		x++;
	}		
}
