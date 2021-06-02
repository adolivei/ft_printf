/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aphex_twin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:59:25 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:03:49 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_width(t_printf *vars, int neg)
{
	if (neg || vars->space_flag || vars->plus_flag)
		vars->width--;
	while (vars->width > vars->print_len)
	{
		if (vars->zero_flag)
		{
			ft_putchar_fd('0', 1);
			vars->format_lenght++;
			vars->width--;
		}
		else
		{
			ft_putchar_fd(' ', 1);
			vars->format_lenght++;
			vars->width--;
		}
	}
}

void	print_sign(t_printf *vars, int neg)
{
	if (neg)
	{
		ft_putchar_fd('-', 1);
		vars->format_lenght++;
	}
	else if (vars->plus_flag)
	{
		ft_putchar_fd('+', 1);
		vars->format_lenght++;
	}
	else if (vars->space_flag)
	{
		ft_putchar_fd(' ', 1);
		vars->format_lenght++;
	}
}

void	print_precision(t_printf *vars, int len)
{
	while (vars->precision > len)
	{
		ft_putchar_fd('0', 1);
		vars->format_lenght++;
		vars->precision--;
	}
}

void	print_spec(t_printf *vars, char *s, int len)
{
	if (!vars->zerop_zerov)
	{
		ft_putstr_fd(s, 1);
		vars->format_lenght += len;
	}
}


// all the variables we're supposed to print should be converted to a string beforehand
// neg = 1 means that the variable is negative, so we should print the '-'
// len is the character lenght of the variable to print (*s)
// vars->print_len will be the len + the zero padding, if applicable. 
void	printer(t_printf *vars, char *s, int len, int neg)
{
	if (vars->minus_flag)
	{
		print_sign(vars, neg);
		print_precision(vars, len);
		print_spec(vars, s, len);
		print_width(vars, neg);
	}
	else
	{
		if (vars->zero_flag)
			print_sign(vars, neg);
		print_width(vars, neg);
		if (!vars->zero_flag)
			print_sign(vars, neg);
		print_precision(vars, len);
		print_spec(vars, s, len);
	}
}
