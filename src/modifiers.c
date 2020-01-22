/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:52:41 by emaveric          #+#    #+#             */
/*   Updated: 2020/01/22 20:52:11 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	change_size(f_pr *par, va_list arg)
{
	if (ft_strcmp(par->modifier, "l") == 0
		|| ft_strcmp(par->modifier, "ll") == 0)
		ft_strcmp(par->modifier, "ll") ?
			par->num.li = (long int)va_arg(arg, int) :
					(long long int)va_arg(arg, int);
	else if (ft_strcmp(par->modifier, "h") == 0
			 || ft_strcmp(par->modifier, "hh") == 0)
		ft_strcmp(par->modifier, "hh") ?
			par->num.uli = (long int)(unsigned char)va_arg(arg, int) :
					(long long int)(unsigned char)va_arg(arg, int);
}

f_pr	*modifiers(char **p, f_pr *par)
{
	if (**p == 'h' && (*p + 1) != '\0')
	{
		if ((**p + 1) == 'h')
		{
			par->modifier = ft_strdup("hh");
			*p += 2;
		}
		else
		{
			par->modifier = ft_strdup("h");
			*p += 1;
		}
	}
	else if (**p == 'l' && (**p + 1) != '\0')
	{
		if ((**p + 1) == 'l')
		{
			par->modifier = ft_strdup("ll");
			*p += 2;
		}
		else
		{
			par->modifier = ft_strdup("l");
			*p += 1;
		}
	}
	else if (**p == 'L')
	{
		par->modifier = ft_strdup("L");
		*p += 1;
	}
	return (par);
}