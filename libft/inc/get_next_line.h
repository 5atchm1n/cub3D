/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:18 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/04 08:21:09 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# include <unistd.h>
# include <stdlib.h>

int					get_next_line(int fd, char **line);
char				*gnl_join(char *s1, char *s2);
int					gnl_find(char *str);
char				*gnl_sub(const char *s, unsigned int start, size_t len,
							int n);
size_t				gnl_len(const char *s);
char				*gnl_dup(const char *src, const char *srcfree);

#endif
