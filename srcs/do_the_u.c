/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:22:50 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:22:52 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*utoa_aux(char *s, int len)
{
	s[0] = '0';
	s[len] = '\0';
	return (s);
}

char	*ft_utoa(unsigned int nb, int len)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (nb == 0)
		s = utoa_aux(s, len);
	else
	{
		i = len - 1;
		while (i)
		{
			s[i] = (nb % 10) + 48;
			nb /= 10;
			i--;
		}
		s[0] = nb + 48;
		s[len] = '\0';
	}
	return (s);
}

int	update_nb_len(t_printf *vars, int len, unsigned int nb)
{
	if (vars->precision_ex && !vars->precision && nb == 0)
	{
		len = 0;
		vars->zerop_zerov = 1;
	}
	else if (nb > INT_MAX)
		len = 10;
	else
		len = ft_char_counter(nb);
	return (len);
}

void	do_the_u(t_printf *vars)
{
	unsigned int	nb;
	int				len;
	int				neg;
	char			*s;

	neg = 0;
	len = 0;
	nb = va_arg(vars->argptr, unsigned int);
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	len = update_nb_len(vars, len, nb);
	s = ft_utoa(nb, len);
	update_print_len(vars, len);
	printer(vars, s, len, neg);
	free (s);
}
