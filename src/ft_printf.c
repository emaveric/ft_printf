/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:14:40 by emaveric          #+#    #+#             */
/*   Updated: 2020/01/16 20:27:31 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	to_int(int num)
{
	char 	*str;
	int 	len;


	str = ft_num_to_str(num);
	len = ft_numlen(num);
	write(1, str, len);
}

int 	ft_printf(const char *format, ...)
{
	int 	i;
	va_list	factor;

	i = 0;
	va_start(factor, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd')
			{
				to_int(va_arg(factor, int));
				i++;
			}
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(factor);
	return (0);
}

int 	main(void)
{
	ft_printf("hello alex, your age = %o and %d", 19, 200);
	printf("\n");
	printf("hello alex, your age = %o and %d", 19, 200);
	return (0);
}
