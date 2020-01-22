/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:14:40 by emaveric          #+#    #+#             */
/*   Updated: 2020/01/22 21:26:03 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

f_pr	*init(void)
{
	f_pr	*new;
	if (!(new = (f_pr *)malloc(sizeof(f_pr))))
		return (NULL);
	new->modifier = NULL;
	new->num.li = 0;
	new->num.uli = 0;
	return (new);
}

void	to_int(va_list arg, f_pr *par)
{
	char 	*str;
	int 	len;

	//par->num = va_arg(arg, int);
	if (par->modifier)
		change_size(par, arg);
	str = ft_num_to_str(va_arg(arg, int));
	len = ft_numlen(va_arg(arg, int));
	write(1, str, len - 1);
}

int 	ft_printf(const char *format, ...)
{
	int 	i;
	f_pr	*par;
	char 	*p;
	va_list	factor;

	i = 0;
	p = (char *)format;
	if (!(par = init()))
		return (ERROR);
	va_start(factor, format);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p = p + 1;
			par = modifiers(&p, par);
			/*if (par->modifier)
				p = p + ft_strlen(par->modifier);*/
			//flags(i, factor);
			if (*p == 'd' || *p == 'i')
			{
				to_int(factor, par);
				p = p + 1;
			}
		}
		else
		{
			write(1, p, 1);
			//i++;
			p = p + 1;
		}
	}
	va_end(factor);
	return (0);
}

int 	main(void)
{
	ft_printf("hello alex, your age = %i and %ld", 19, 200);
	printf("\n");
	printf("hello alex, your age = %i and %d", 19, 200);
	return (0);
}
