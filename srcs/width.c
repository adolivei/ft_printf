/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:43:22 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:43:23 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	width_exists(char c, char b)
{
	if ((ft_isnum(c) || c == '*') && (flag_exists(b) || b == '%'))
		return (1);
	return (0);
}

void	width_conversion(const char *format, t_printf *vars, int i)
{
	char	*temp;
	int		j;

	j = i;
	while (ft_isnum(format[i]))
		i++;
	i = i - j;
	temp = ft_substr(format, j, i);
	vars->width = ft_atoi(temp);
	free(temp);
}

void	get_width(const char *format, t_printf *vars, int i)
{
	if (format[i] == '*')
	{
		vars->width = va_arg(vars->argptr, int);
		if (vars->width < 0)
		{
			vars->width = -vars->width;
			vars->minus_flag = 1;
			vars->zero_flag = 0;
		}
	}
	else
		width_conversion(format, vars, i);
}
