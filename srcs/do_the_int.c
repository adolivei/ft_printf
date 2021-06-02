/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:09:44 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:09:49 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// special case for the INT_MIN
char	*special_mint(int len)
{
	char	*temp;
	char	*s;
	int		i;
	int		j;

	temp = ft_itoa(INT_MIN);
	s = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 1;
	while (temp[j])
	{
		s[i] = temp[j];
		i++;
		j++;
	}
	s[i] = '\0';
	free(temp);
	return (s);
}

void	int_aux(t_printf *vars, int len, char *s, int neg)
{
	update_print_len(vars, len);
	printer(vars, s, len, neg);
	free (s);
}

void	do_the_int(t_printf *vars)
{
	int		nb;
	int		len;
	int		neg;
	char	*s;

	neg = 0;
	nb = va_arg(vars->argptr, int);
	if (nb == INT_MIN)
	{
		len = 10;
		neg = 1;
		s = special_mint(len);
	}
	else
	{
		if (nb < 0)
		{
			neg = 1;
			nb *= -1;
		}
		len = update_nb_len(vars, 0, nb);
		s = ft_itoa(nb);
	}
	int_aux(vars, len, s, neg);
}
