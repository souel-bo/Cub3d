/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:07:01 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/01 23:34:12 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*list;
	void	*p;

	list = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			p = f(lst->content);
			node = ft_lstnew(p);
			if (!node)
			{
				del(p);
				ft_lstclear(&list, del);
				return (NULL);
			}
			ft_lstadd_back(&list, node);
			lst = lst->next;
		}
		return (list);
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*s1;
	t_list	*s2;
	t_list	*s3;
	t_list	*s4;
	t_list	*s5;
	t_list	*lists;

	s1 =ft_malloc(sizeof(t_list));
	s2 =ft_malloc(sizeof(t_list));
	s3 =ft_malloc(sizeof(t_list));
	s4 =ft_malloc(sizeof(t_list));
	s5 =ft_malloc(sizeof(t_list));
	s1->content = ft_strdup("string1");
	s1->next = s2;
	s2->content = ft_strdup("string2");
	s2->next = s3;
	s3->content = ft_strdup("string3");
	s3->next = s4;
	s4->content = ft_strdup("string4");
	s4->next = s5;
	s5->content = ft_strdup("string5");
	s5->next = NULL;
	lists = ft_lstmap(s1, *itter, delete);
	while(lists)
	{
		printf("%s\n", (char *)lists->content);
		lists = lists->next;
	}
	return (0);
}
*/
