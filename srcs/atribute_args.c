/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atribute_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:06:51 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:06:53 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	reset_flags(t_printf *vars)
{
	vars->minus_flag = 0;
	vars->plus_flag = 0;
	vars->space_flag = 0;
	vars->zero_flag = 0;
	vars->zerop_zerov = 0;
	vars->width = 0;
	vars->precision = 0;
	vars->precision_ex = 0;
	vars->print_len = 0;
}

void	atribute_args(const char *format, t_printf *vars, int i)
{
	if (format[i] == 'd' || format[i] == 'i')
		do_the_int(vars);
	else if (format[i] == 'c')
		do_the_char(vars);
	else if (format[i] == 'u')
		do_the_u(vars);
	else if (format[i] == 's')
		do_the_s(vars);
	else if (format[i] == 'p')
		do_the_p(vars);
	else if (format[i] == 'x' || format[i] == 'X')
		do_the_x(vars, format[i]);
	else if (format[i] == '%')
		do_the_perc(vars);
	reset_flags(vars);
}
