/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_keys.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:51:15 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/18 22:04:14 by sshakya          ###   ########.fr       */
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

# define M_UP 1
# define M_DOWN 2
# define M_RIGHT 4
# define M_LEFT 8
# define L_UP 16
# define L_DOWN 32
# define L_LEFT 64
# define L_RIGHT 128
# define M_JUMP 256
# define M_CROUCH 512
# define M_HIT 1024

# define S_ON 1
# define S_MOVE 2
# define S_BACK 4
# define S_KILL 8

# define E_TNO 1
# define E_TSO 2
# define E_TEA 4
# define E_TWE 8

#endif
