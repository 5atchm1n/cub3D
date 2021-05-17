/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_keys.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:51:15 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/17 18:28:22 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_KEYS_H
# define CUB3D_KEYS_H

# define BUFF_SIZE 256
# define TEXTURES 4
# define SPRITE_H 64
# define SPRITE_W 64
# define TEX_X 64
# define TEX_Y 64
# define WEAPONS 1
# define SKY_X 1200
# define SKY_Y 511
# define ERRORS 22
# define BONUS_MAP " NSEW01234"
# define PLAYER_SIZE 0.1
# define MAP_SIZE 0.15

# ifndef SPRITES
#  define SPRITES 1
# endif

# ifndef BONUS_OBJECTS
#  define BONUS_OBJECTS 0
# endif

# define KEY_MOVE_UP 119
# define KEY_MOVE_DOWN 115
# define KEY_MOVE_LEFT 97
# define KEY_MOVE_RIGHT 100
# define KEY_LOOK_UP 65362
# define KEY_LOOK_DOWN 65364
# define KEY_LOOK_RIGHT 65363
# define KEY_LOOK_LEFT 65361
# define KEY_ESC_QUIT 0xff1b
# define KEY_JUMP 32
# define KEY_CROUCH 65507
# define KEY_SPRINT 65505
# define KEY_HIT 102

# define M_UP (1 << 0)
# define M_DOWN (1 << 1)
# define M_RIGHT (1 << 2)
# define M_LEFT (1 << 3)
# define L_UP (1 << 4)
# define L_DOWN (1 << 5)
# define L_LEFT (1 << 6)
# define L_RIGHT (1 << 7)
# define M_JUMP (1 << 8)
# define M_CROUCH (1 << 9)
# define M_HIT (1 << 10)

# define S_ON (1 << 0)
# define S_MOVE (1 << 1)
# define S_BACK (1 << 2)
# define S_KILL (1 << 3)

# define E_TNO (1 << 0)
# define E_TSO (1 << 1)
# define E_TEA (1 << 2)
# define E_TWE (1 << 3)

#endif
