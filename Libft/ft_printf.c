/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:22:04 by kilchenk          #+#    #+#             */
/*   Updated: 2023/01/15 15:18:49 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	check_letter(const char *str, va_list ar)
{
	int	num;

	num = 0;
	if (*str == 'c')
		return (putchar_fd(va_arg(ar, int), 1));
	if (*str == 's')
		return (putstr_fd(va_arg(ar, char *), 1));
	if (*str == 'd' || *str == 'i')
		return (ft_digit(va_arg(ar, int), &num, "0123456789", 10));
	if (*str == '%')
		return (putchar_fd('%', 1));
	if (*str == 'u')
		return (ft_digit(va_arg(ar, unsigned int), &num, "0123456789", 10));
	if (*str == 'x')
		return (ft_digit(va_arg(ar, unsigned int), &num, \
		"0123456789abcdef", 16));
	if (*str == 'X')
		return (ft_digit(va_arg(ar, unsigned int), &num, \
		"0123456789ABCDEF", 16));
	if (*str == 'p')
	{
		putstr_fd("0x", 1);
		return (ft_pointer(va_arg(ar, size_t), "0123456789abcdef") + 2);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		letters;

	va_start (arg, format);
	i = 0;
	letters = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			letters += check_letter((char *)format + i + 1, arg);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			letters ++;
		}
	}
	va_end (arg);
	return (letters);
}

// int main()
// {
//     // int x = 5;
// 	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	// ft_printf("%i\n", i);
// 	printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	// printf("%i\n", x);
//     // ft_printf("%i\n", x);
// 	// printf("%d\n", x);
//     // printf("%i\n", x);
//     return 0;
// }
