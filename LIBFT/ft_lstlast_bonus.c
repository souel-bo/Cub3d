/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:46:20 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/01 23:34:12 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
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
	t_list	*i;

	// THE ORIGINAL LISTS
	s1 =ft_malloc(sizeof(t_list));
	s2 =ft_malloc(sizeof(t_list));
	s3 =ft_malloc(sizeof(t_list));
	s4 =ft_malloc(sizeof(t_list));
	s5 =ft_malloc(sizeof(t_list));
	i =ft_malloc(sizeof(t_list));
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
	// PRINTF
	i = ft_lstlast(s1);
	printf("%s\n", i->content);
	//printf("%s\n", (char *)s1->content);
	//printf("%s\n", (char *)s2->content);
	//printf("%s\n", (char *)s3->content);
}
*/
