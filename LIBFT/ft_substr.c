/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:02:48 by yael-yas          #+#    #+#             */
/*   Updated: 2025/08/30 18:04:14 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) <= start + len)
		arr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		arr = malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	while (s[start] && i < len)
	{
		arr[i] = s[start];
		start++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s\n", ft_substr("hello", 3, 4));
// }

