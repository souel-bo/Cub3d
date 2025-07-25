/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:27:42 by souel-bo          #+#    #+#             */
/*   Updated: 2025/07/24 12:10:18 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include "cub.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
int	ft_count_argc(char **argv);
int	ft_atoi_mstr(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif