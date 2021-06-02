/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:24:48 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:24:49 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_hexa_len(t_printf *vars, unsigned long long int nb)
{
	int						len;
	unsigned long long int	n;

	if (vars->precision == 0 && vars->precision_ex && nb == 0)
	{
		vars->zerop_zerov = 1;
		return (0);
	}
	len = 0;
	if (nb == 0)
		len = 1;
	n = nb;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

// transforms all small letters from a string into capital letters
char	*small_to_capital(char *s)
{
	char	*temp;
	int		i;
	int		len;

	len = ft_strlen(s);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			temp[i] = s[i] - 32;
		else
			temp[i] = s[i];
		i++;
	}
	temp[len] = '\0';
	return (temp);
}

void	do_the_x(t_printf *vars, char x)
{
	unsigned int	nb;
	char			*s;
	char			*upper_s;
	int				len;

	len = 0;
	nb = va_arg(vars->argptr, unsigned int);
	len = get_hexa_len(vars, nb);
	update_print_len(vars, len);
	s = ft_ulltohex(nb, len, 0);
	if (x == 'X')
	{
		upper_s = small_to_capital(s);
		printer(vars, upper_s, len, 0);
		free(upper_s);
	}
	else
		printer(vars, s, len, 0);
	free(s);
}
