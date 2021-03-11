/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:11:19 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/11 20:45:04 by sshakya          ###   ########.fr       */
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
	int				pos_x;
	int				pos_y;
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
	int				res_x;
	int				res_y;
}					t_res;

typedef struct		s_settings
{
	t_res			res;
	int				floor;
	int				ceiling;
	int				size_x;
	int				size_y;
}					t_settings;

int			ft_setparams(char *line, t_settings *settings);

#endif
