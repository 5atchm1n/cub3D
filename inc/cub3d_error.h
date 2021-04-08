/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 00:40:33 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 01:57:28 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERROR_H
# define CUB3D_ERROR_H

typedef enum		e_errn
{
	NO_ERR = 0,
	INV_CHAR = 1,
	O_MAP = 2,
	IS_PATH = 3,
	INV_FILE = 4,
	SPACE_EOL = 5,
	INV_EXT = 6,
	MAP_NOEND = 7
}					t_errn;

typedef struct		s_error
{
	t_errn			id;
	t_grid			coords;
	int				texture;
	int				res;
	int				floor;
	int				ceiling;
	int				map;

}					t_error;

#endif
