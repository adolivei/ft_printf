/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:20:52 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:20:54 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	update_str_len(t_printf *vars, int len, char *s)
{
	if (vars->precision == 0 && vars->precision_ex)
	{
		vars->zerop_zerov = 1;
		len = 0;
	}
	if (vars->precision_ex && vars->precision < (int)ft_strlen(s))
		len = vars->precision;
	else
		len = ft_strlen(s);
	vars->precision = 0;
	vars->print_len = len;
	return (len);
}

char	*cut_str(char *s, int len)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	temp[len] = '\0';
	len--;
	while (len > -1)
	{
		temp[len] = s[len];
		len--;
	}
	return (temp);
}

void	do_the_s(t_printf *vars)
{
	char	*s;
	int		len;
	int		neg;

	neg = 0;
	len = 0;
	s = va_arg(vars->argptr, char *);
	if (!s)
		s = "(null)";
	len = update_str_len(vars, len, s);
	s = cut_str(s, len);
	printer(vars, s, len, neg);
	free(s);
}
