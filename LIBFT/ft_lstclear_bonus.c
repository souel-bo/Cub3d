/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:42:53 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/01 23:34:12 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
void delete (void *s)
{
	free(s);
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next_node;

	if (!*lst || !lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		next_node = node->next;
		del(node->content);
		free(node);
		node = next_node;
	}
	*lst = NULL;
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
	ft_lstclear(&s1, delete);
	printf("%s\n", (char *)s1->content);
	printf("%s\n", (char *)s2->content);
	printf("%s\n", (char *)s3->content);
}
*/
