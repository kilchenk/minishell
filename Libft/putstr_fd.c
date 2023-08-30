/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:03:33 by kilchenk          #+#    #+#             */
/*   Updated: 2023/01/15 15:51:41 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (ft_strlen(s));
}
