/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grabage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:48:36 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/02 01:18:36 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static t_garbage_collector	*get_collector(void)
{
	static t_garbage_collector	collector;

	collector = {NULL};
	return (&collector);
}

void	*ft_malloc(long long size)
{
	void				*ptr;
	t_list				*new_node;
	t_garbage_collector	*gc;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	new_node = ft_lstnew(ptr);
	if (!new_node)
	{
		free(ptr);
		return (NULL);
	}
	gc = get_collector();
	ft_lstadd_back(&gc->allocated_memory, new_node);
	return (ptr);
}

void	ft_delete(void *s)
{
	free(s);
}

void	ft_free(void)
{
	t_garbage_collector	*gc;

	gc = get_collector();
	ft_lstclear(&gc->allocated_memory, ft_delete);
	gc->allocated_memory = NULL;
}
