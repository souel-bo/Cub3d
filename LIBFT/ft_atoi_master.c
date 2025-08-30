/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_master.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-yas <yael-yas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:02:36 by yael-yas          #+#    #+#             */
/*   Updated: 2025/08/30 18:02:37 by yael-yas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_atoi_mstr(const char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		r = r * 10 + str[i] - '0';
		if (r > 255)
			return (-1);
		i++;
	}
	while (str[i])
	{
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
			return (-1);
		i++;
	}
	return (r);
}


//int main()
//{
//    char *str = "hello";
//    int num = 0;
//    if ((num = ft_atoi_mstr(str)) != -1)
//    {
//        printf("%d\n", num);
//    }
//    else
//        printf("errpr\n");
//}