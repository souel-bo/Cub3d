/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:55:08 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/01 23:34:12 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*s1;
	t_list	*s2;
	t_list	*s3;
	t_list	*s4;
	t_list	**lists;

	// THE ORIGINAL LISTS
	s1 =ft_malloc(sizeof(t_list));
	s2 =ft_malloc(sizeof(t_list));
	s3 =ft_malloc(sizeof(t_list));
	s1->content = "hello";
	s1->next = s2;
	s2->content = "memory";
	s2->next = s3;
	s3->content = "data";
	s3->next = NULL;
	//NEW LIST;
	s4 =ft_malloc(sizeof(t_list));
	s4->content = "fuck";
	s4->next = NULL;
	// LETS CHANGE IT
	lists = &s1;
	ft_lstadd_front(lists, s4);
	// PRINTF
	//printf("%s\n", (char *)s1->content);
	//printf("%s\n", (char *)s2->content);
	//printf("%s\n", (char *)s3->content);
	while (*lists != NULL)
	{
		printf("%s\n", (char *)(*lists)->content);
		lists = &((*lists)->next);
	}
}
*/
