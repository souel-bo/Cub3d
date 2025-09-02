/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:14:14 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/01 23:34:12 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		(*lst)->next = NULL;
		return ;
	}
	last = *lst;
	while (last->next)
	{
		last = last->next;
	}
	last->next = new;
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
	t_list	*new;
	t_list	**lists;
	t_list	*test;
	int		i;

	test = ((void *)0);
	// THE ORIGINAL LISTS
	s1 =ft_malloc(sizeof(t_list));
	s2 =ft_malloc(sizeof(t_list));
	s3 =ft_malloc(sizeof(t_list));
	s4 =ft_malloc(sizeof(t_list));
	s5 =ft_malloc(sizeof(t_list));
	lists =ft_malloc(sizeof(t_list *));
	new =ft_malloc(sizeof(t_list));
	s1->content = "hello";
	s1->next = s2;
	s2->content = "memory";
	s2->next = s3;
	s3->content = "data";
	s3->next = s4;
	s4->content = "struct";
	s4->next = s5;
	s5->content = "c programing";
	s5->next = NULL;
	new->content = ft_strdup("ok");
	new->next = NULL;
	// PRINTF
	lists = &s1;
	ft_lstadd_back(&test, new);
	//printf("%d\n", i);
	//printf("%s\n", (char *)s1->content);
	//printf("%s\n", (char *)s2->content);
	//printf("%s\n", (char *)s3->content);
	while (test != NULL)
	{
		printf("%s\n", test->content);
		test = test->next;
	}
}
*/
