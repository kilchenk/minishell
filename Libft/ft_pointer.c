/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:50:13 by kilchenk          #+#    #+#             */
/*   Updated: 2023/10/17 14:41:35 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int	ft_pointer(size_t nbr, char *base)
{
	size_t		size;
	size_t		i;
	char		output[65];

	i = 0;
	size = ft_strlen(base);
	while (nbr > 0 || i == 0)
	{
		output[i] = base[nbr % size];
		nbr = nbr / size;
		i++;
	}
	size = i;
	while (i-- > 0)
	{
		write(1, &output[i], 1);
	}
	return (size);
}
