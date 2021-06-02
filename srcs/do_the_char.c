/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:07:36 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:07:39 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	putandraise(t_printf *vars, char c)
{
	ft_putchar_fd(c, 1);
	vars->format_lenght += 1;
}

void	c_minus(t_printf *vars, char c)
{
	putandraise(vars, c);
	vars->print_len--;
	while (vars->print_len > 0)
	{
		ft_putchar_fd(' ', 1);
		vars->format_lenght++;
		vars->print_len--;
	}
}

void	c_zero(t_printf *vars, char c)
{
	while (vars->print_len > 1)
	{
		ft_putchar_fd('0', 1);
		vars->format_lenght++;
		vars->print_len--;
	}
	putandraise(vars, c);
}

void	c_width(t_printf *vars, char c)
{
	while (vars->print_len > 1)
	{
		ft_putchar_fd(' ', 1);
		vars->format_lenght++;
		vars->print_len--;
	}
	putandraise(vars, c);
}

void	do_the_char(t_printf *vars)
{
	char	c;

	c = va_arg(vars->argptr, int);
	if (vars->precision)
		vars->precision = 0;
	if (vars->width)
		vars->print_len = vars->width;
	if (vars->print_len > 1)
	{
		if (vars->minus_flag)
			c_minus(vars, c);
		else if (vars->zero_flag)
			c_zero(vars, c);
		else
			c_width(vars, c);
	}
	else
		putandraise(vars, c);
}

// disclaimer: the char convertion to string was giving memory leaks so i did this horrible piece of code
// instead of sending it to the printer function in aphex_twin file
// it's not much it's honest work