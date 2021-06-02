/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:41:18 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:41:19 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	precision_exists(t_printf *vars, char c)
{
	if (c == '.')
	{
		vars->precision_ex = 1;
		vars->zero_flag = 0;
		return (1);
	}
	return (0);
}

void	precision_conversion(const char *format, t_printf *vars, int i)
{
	char	*temp;
	int		j;

	j = i;
	while (ft_isnum(format[i]))
		i++;
	i = i - j;
	temp = ft_substr(format, j, i);
	vars->precision = ft_atoi(temp);
	free(temp);
}

void	get_precision(const char *format, t_printf *vars, int i)
{
	i++;
	if (format[i] == '*')
		vars->precision = va_arg(vars->argptr, int);
	else
		precision_conversion(format, vars, i);
	if (vars->precision < 0)
	{
		vars->precision = 0;
		vars->precision_ex = 0;
	}
}
