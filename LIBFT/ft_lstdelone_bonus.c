/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:56:14 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/01 23:34:12 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
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
	t_list	*s5;
	t_list	**lists;
	int		i;

	// THE ORIGINAL LISTS
	s1 =ft_malloc(sizeof(t_list));
	s2 =ft_malloc(sizeof(t_list));
	s3 =ft_malloc(sizeof(t_list));
	s4 =ft_malloc(sizeof(t_list));
	s5 =ft_malloc(sizeof(t_list));
	s1->content = ft_strdup("hello");
	s1->next = s2;
	s2->content = ft_strdup("memory");
	s2->next = s3;
	s3->content = ft_strdup("data");
	s3->next = s4;
	s4->content = ft_strdup("struct");
	s4->next = s5;
	s5->content = ft_strdup("c programing");
	s5->next = NULL;
	// PRINTF
	ft_lstdelone(s5, delete);
	//printf("%d\n", i);
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
