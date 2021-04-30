/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 04:22:05 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/30 04:06:01 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				**ft_split(char const *str, char c);
char				*ft_itoa(int n);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strrchr(const char *str, int c);
char				*ft_strtrim(char const *str, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s);
void				*ft_calloc(size_t num, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

/*
** BONUS
*/

t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)
		(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));

/*
** GNL
*/

int					get_next_line(int fd, char **line);
char				*gnl_join(char *s1, char *s2);
int					gnl_find(char *str);
char				*gnl_sub(const char *s, unsigned int start, size_t len,
							int n);
size_t				gnl_len(const char *s);
char				*gnl_dup(const char *src, const char *srcfree);

/*
** MY FUNCTIONS
*/

int					ft_isspace(char c);
int					ft_strcmp(char *s1, char *s2);
double				ft_fmax(double a, double b);
double				ft_fmin(double a, double b);

#endif
