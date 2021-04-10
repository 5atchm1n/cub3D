/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:28:37 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/10 12:32:01 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			cub_print_info(t_cub *game)
{
	int			j;
	int			i;
	int			x;

	i = 0;
	while (i < game->world.msize.y)
	{
		j = 0;
		while (j < game->world.msize.x)
		{
			printf("%c", game->world.map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	// PRINT SETTINGS AND INITLA POSITION
	printf("map size = map[%d][%d]\n", game->world.msize.y, game->world.msize.x);
	printf("res_x = %d\n", game->mlx.res.x);
	printf("res_y = %d\n", game->mlx.res.y);
	printf("floor = %d | %#.8x \n", game->world.floor.color, game->world.floor.color);
	printf("ceiling = %d | %#.8x\n", game->world.ceiling.color, game->world.ceiling.color);
	// PRINT PLAYER VECVTOR
	printf("x = %.5f\n", game->player.vector.x);
	printf("y = %.5f\n", game->player.vector.y);
	printf("dx = %.5f\n", game->player.vector.dx);
	printf("dy = %.5f\n", game->player.vector.dy);
	printf("px = %.5f\n", game->player.camera.px);
	printf("py = %.5f\n", game->player.camera.py);
	printf("offset = %.5f\n", game->world.offset);
	// PRINT SPRITES INFO
	x = 0;
	while (x < cub_nobject(&game->world))
	{
	printf("obj[%2d] : x = %4.1f |", x, game->world.sprite[x].x);
	printf("y = %4.1f |", game->world.sprite[x].y);
	printf("id = %d |", game->world.sprite[x].id);
	printf("udiv = %d |", game->world.sprite[x].udiv);
	printf("vdiv = %d |", game->world.sprite[x].vdiv);
	printf("vmove = %4.2f\n", game->world.sprite[x].vmove);
	x++;
	}
	// PRINT PATHS
	x = 0;
	while (x < TEXTURES)
	{
		printf("tpath[%d] = %s\n", x ,game->world.tpath[x]);
		x++;
	}
	x = 0;
	while (x < SPRITES)
	{
		printf("objpath[%d] = %s\n", x ,game->world.objpath[x]);
		x++;
	}
}

int				key_hook(int keycode, t_win *win)
{
	if (win && keycode)
		write(1 , "#", 1);
	printf("%d\n", keycode);
	return (0);
}
