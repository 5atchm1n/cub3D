/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:11:19 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/12 19:55:17 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

#define BUFF_SIZE 256

typedef struct		s_win
{
	void			*mlx;
	void			*win;
}					t_win;

typedef struct		s_img
{
	void			*img;
	char			*add;
	int				bpp;
	int				len;
	int				endian;
}					t_img;

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_settings
{
	t_res			res;
	int				floor;
	int				ceiling;
	int				size_x;
	int				size_y;
	int				pos_x;
	int				pos_y;
}					t_settings;

typedef struct		s_cub
{
	t_win			win;
	t_img			img;
	t_settings		settings;
	char			**map;
}					t_cub;

int					ft_setparams(char *line, t_settings *settings);
int					ft_settings(char *map, t_settings *settings);
int					ft_get_line(char **line, int fd);
char				**ft_parse_map(char *map, t_cub *game);
int					ft_isspace(char c);

void				my_pixel_put(t_img *img, int x, int y, int color);
void				background(t_cub *game);
void				my_player(t_img *img, int x, int y);
int					ft_move(int keycode, t_cub *game);
void				draw_map(t_cub *game);
void				put_wall(t_cub *game, int x, int y, int colour);
#endif
