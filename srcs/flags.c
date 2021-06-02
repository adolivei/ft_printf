/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:26:40 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:26:42 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	flag_exists(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0')
		return (1);
	return (0);
}

void	flag_parser(const char *format, t_printf *vars, int i)
{
	while (flag_exists(format[i]))
	{
		if (format[i] == '0')
		{
			if (!vars->minus_flag)
				vars->zero_flag = 1;
		}
		else if (format[i] == '-')
		{
			vars->zero_flag = 0;
			vars->minus_flag = 1;
		}
		else if (format[i] == ' ')
		{
			if (!vars->plus_flag)
				vars->space_flag = 1;
		}
		else if (format[i] == '+')
		{
			vars->space_flag = 0;
			vars->plus_flag = 1;
		}
		i++;
	}
}
