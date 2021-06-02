/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:56:31 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 17:59:05 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	specifier_found(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

// update flags, width and precision
int	update_vars(const char *format, t_printf *vars, int i)
{
	while (!specifier_found(format[i]))
	{
		if (flag_exists(format[i]) && !vars->width && !vars->precision_ex)
			flag_parser(format, vars, i);
		else if (width_exists(format[i], format[i - 1]) && !vars->precision_ex)
			get_width(format, vars, i);
		else if (precision_exists(vars, format[i]))
			get_precision(format, vars, i);
		i++;
	}
	return (i);
}

void	analise_format(const char *format, t_printf *vars)
{
	int	i;
	int	j;

	i = vars->index + 1;
	vars->index = update_vars(format, vars, i); // index is now at the specifier, ready to print what comes after
	j = vars->index;
	while (specifier_found(format[j]) && j == vars->index)
	{
		atribute_args(format, vars, j);
		j++;
	}
}
