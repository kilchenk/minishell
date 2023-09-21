/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:28:07 by kilchenk          #+#    #+#             */
/*   Updated: 2023/09/20 16:42:04 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		a;

	a = ft_strlen(s1);
	s2 = (char *) malloc(a + 1);
	if (s1 == NULL)
	{
		return (NULL);
	}
	else
	{
		ft_strcpy(s2, s1);
		return (s2);
	}
}

// int main()
// {
//     char source[] = "Geeks389";
//     // A copy of source is created dynamically
//     // and pointer to copy is returned.
//     char* target = ft_strdup(source);
//     printf("%s", target);
//     return 0;
// }
