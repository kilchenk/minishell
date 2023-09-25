/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:45:53 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/21 16:29:36 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	if (nb == 0)
	{
		return (1);
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*if_zero(char *s)
{
	s[0] = '0';
	return (s);
}

char	*ft_itoa(int nb)
{
	char	*s;
	long	n;
	int		i;

	n = nb;
	i = len(n);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i--] = '\0';
	if (n == 0)
	{
		if_zero(s);
	}
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		s[i--] = '0' + (n % 10);
		n = n / 10;
	}
	return (s);
}
