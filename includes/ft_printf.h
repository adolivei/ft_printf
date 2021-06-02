/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:44:58 by adolivei          #+#    #+#             */
/*   Updated: 2021/05/07 18:45:01 by adolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_printf
{
	va_list			argptr;
	int				index;
	unsigned int	format_lenght; // ft_printf return
	int				zero_flag;
	int				minus_flag;
	int				plus_flag;
	int				space_flag;
	int				width;
	int				precision; // precision value
	int				precision_ex; // = 1 the precision exists, = 0 the precision does not exist for the special case when precision exists but is equal to 0
	int				zerop_zerov; // special case when value of variable = 0 and precision = 0 (print nothing)
	int				print_len; // len + zero padding

}					t_printf;

int		ft_printf(const char *format, ...);

void	analise_format(const char *format, t_printf *vars);

int		flag_exists(char c);

void	flag_parser(const char *format, t_printf *vars, int i);

int		ft_isnum(char c);

int		width_exists(char c, char b);

void	get_width(const char *format, t_printf *vars, int i);

int		precision_exists(t_printf *vars, char c);

void	get_precision(const char *format, t_printf *vars, int i);

void	atribute_args(const char *format, t_printf *vars, int i);

int		ft_char_counter(int n);

void	print_int(const char *format, t_printf *vars);

void	update_print_len(t_printf *vars, int len);

void	do_the_int(t_printf *vars);
void	do_the_char(t_printf *vars);
void	do_the_u(t_printf *vars);
void	do_the_s(t_printf *vars);
void	do_the_p(t_printf *vars);
void	do_the_x(t_printf *vars, char x);
void	do_the_perc(t_printf *vars);

int		get_hexa_len(t_printf *vars, unsigned long long int nb);

char	*ft_ulltohex(unsigned long long int nb, int len, int p);

int		update_nb_len(t_printf *vars, int len, unsigned int nb);

void	printer(t_printf *vars, char *s, int len, int neg);

#endif
