/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:54:33 by yael-yas          #+#    #+#             */
/*   Updated: 2025/09/02 00:20:46 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = ft_malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, size * nmemb);
	return (array);
}
// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;

// 	s = ft_calloc(1000000000000000000, 1000000000000000000);
// 	printf("%s\n", s);
// }
