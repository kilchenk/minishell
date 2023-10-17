/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:21:37 by kilchenk          #+#    #+#             */
/*   Updated: 2023/10/17 14:40:17 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (nmemb * size > SIZE_MAX)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
