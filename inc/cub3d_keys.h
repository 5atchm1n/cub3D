/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_keys.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:51:15 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/26 15:44:49 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_KEYS_H
# define CUB3D_KEYS_H

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

#endif
