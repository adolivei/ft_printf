/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:42:45 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:42:47 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_char_counter(int n)
{
	int	i;

	i = 1;
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

void	update_print_len(t_printf *vars, int len)
{
	vars->print_len = len;
	if (vars->precision > len)
	{
		vars->print_len = vars->precision;
	}
}
