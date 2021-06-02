/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:40:48 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:40:52 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf	vars;

	ft_memset(&vars, 0, sizeof(vars));
	va_start(vars.argptr, format);
	while (format[vars.index])
	{
		if (format[vars.index] == '%')
			analise_format(format, &vars);
		else
		{
			ft_putchar_fd(format[vars.index], 1);
			vars.format_lenght++;
		}
		vars.index++;
	}
	va_end(vars.argptr);
	return (vars.format_lenght);
}
