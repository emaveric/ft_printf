/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:14:58 by emaveric          #+#    #+#             */
/*   Updated: 2020/01/22 20:43:36 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H
# define ERROR -1

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

union			u_number
{
	long long int			li;
	unsigned long long int	uli;
}				;

typedef struct	s_pr
{
	int				minus;
	int 			plus;
	int				space;
	int 			sharp;
	int 			width;
	union u_number	num;
	char 			*modifier;
}				f_pr;

void	flags(char *p, va_list factor);
f_pr	*modifiers(char **p, f_pr *par);
void	change_size(f_pr *par, va_list arg);

#endif
