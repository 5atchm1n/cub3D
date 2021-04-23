/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 02:23:26 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/09 17:41:15 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	void	*temp;

	head = NULL;
	while (lst != NULL && f != NULL)
	{
		temp = f(lst->content);
		if (temp == NULL)
		{
			if (del != NULL)
				ft_lstclear(&head, del);
			return (NULL);
		}
		new = ft_lstnew(temp);
		if (new == NULL && del != NULL)
		{
			ft_lstclear(&head, del);
			del(temp);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
