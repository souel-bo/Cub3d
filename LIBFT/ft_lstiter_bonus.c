/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:18:43 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/01 23:34:12 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
/*
int	main(void)
{
	t_list	*s1;
	t_list	*s2;
	t_list	*s3;
	t_list	**s;
	t_list	*d;

	s1 =ft_malloc(sizeof(t_list));
	s2 =ft_malloc(sizeof(t_list));
	s3 =ft_malloc(sizeof(t_list));
	s1->content = ft_strdup("string 1");
	s1->next = s2;
	s2->content = ft_strdup("string 2");
	s2->next = s3;
	s3->content = ft_strdup("string 3");
	s3->next = NULL;
	s = &s1;
	ft_lstiter(*s, itter);
	while ((*s))
	{
		printf("%s\n", (*s)->content);
		(*s) = (*s)->next;
	}
	return (0);
}
*/
