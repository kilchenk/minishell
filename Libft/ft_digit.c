/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:10:46 by kilchenk          #+#    #+#             */
/*   Updated: 2023/10/17 14:40:18 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_digit(long long int n, int *length, char *hexadecimal, int base)
{
	if (n < 0)
	{
		n *= -1;
		*length += write(1, "-", 1);
	}
	if (n >= base)
		ft_digit((n / base), length, hexadecimal, base);
	*length += write(1, &hexadecimal[n % base], 1);
	return (*length);
}
