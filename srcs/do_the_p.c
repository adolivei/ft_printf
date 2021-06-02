/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:18:10 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:18:13 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// stores the 0x prefix and returns it
char	*store_ox(char *s)
{
	s[0] = '0';
	s[1] = 'x';
	return (s);
}

// for the special case of adress = 0
// without this, the output would be 0x instead of the 0x0 we want
// also applies for the x/X convertions (that's why the 'else')
char	*add_zero(char *s, int p)
{
	if (p)
		s[2] = '0';
	else
		s[0] = '0';
	return (s);
}

// aux for hex convertion
char	dtoh(unsigned long long int nb, char c)
{
	if (nb >= 0 && nb <= 9)
		c = nb + 48;
	else if (nb == 10)
		c = 'a';
	else if (nb == 11)
		c = 'b';
	else if (nb == 12)
		c = 'c';
	else if (nb == 13)
		c = 'd';
	else if (nb == 14)
		c = 'e';
	else if (nb == 15)
		c = 'f';
	return (c);
}

// converts unsigned long long decimal into hexadecimal and returns it
// len is the char counter of nb
// if p = 1 is for p specifier, p = 0 is for x/X
char	*ft_ulltohex(unsigned long long int nb, int len, int p)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * (len + 1));
	i = len - 1;
	if (p)
		temp = store_ox(temp);
	if (nb == 0)
		temp = add_zero(temp, p);
	else
	{
		while (nb)
		{
			temp[i] = dtoh(nb % 16, temp[i]);
			nb = nb / 16;
			i--;
		}
	}
	temp[len] = '\0';
	return (temp);
}

void	do_the_p(t_printf *vars)
{
	unsigned long long int	p;
	int						len;
	char					*s;
	int						neg;

	neg = 0;
	len = 0;
	p = va_arg(vars->argptr, unsigned long long int);
	len = get_hexa_len(vars, p) + 2;
	vars->print_len = len;
	s = ft_ulltohex(p, len, 1);
	printer(vars, s, len, neg);
	free(s);
}
