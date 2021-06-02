/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_perc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:20:18 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:20:21 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	do_the_perc(t_printf *vars)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * 2);
	s[0] = '%';
	s[1] = '\0';
	vars->print_len = 1;
	printer(vars, s, 1, 0);
	free(s);
}
