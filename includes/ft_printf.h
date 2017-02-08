/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 10:26:39 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/08 19:55:30 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <wchar.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_flags
{
	int				left_justify;
	int				fill_w_zero;
	int				pos_nul;
	int				is_blank;
	int				is_sharp;
	int				size_lenght;
	int				size_prec;
	int				which_letter;
	int				h;
	int				l;
	int				j;
	int				z;
}					t_flags;

int					ft_printf(const char *format, ...);

int					ft_check_letter(va_list ap, char c, t_flags flaggs);
int					ft_check_there_is_letter(char c);
t_flags				get_width(int *i, t_flags b, va_list ap);
t_flags				get_precision(const char *s, int *i, t_flags b, va_list ap);

char				*ft_strchar(char c, size_t size);

int					ft_printf_c(va_list ap, t_flags flaggs);
int					ft_printf_c_maj(va_list ap, t_flags flaggs);
int					ft_printf_i(va_list ap, t_flags flaggs, char c);
int					ft_printf_s(va_list ap, t_flags flaggs);
int					ft_printf_s_maj(va_list ap, t_flags flaggs);
int					ft_printf_u(va_list ap, t_flags flaggs, char c);
int					ft_printf_o(va_list ap, t_flags flaggs, char c);
int					ft_printf_x(va_list ap, t_flags flaggs);
int					ft_printf_x_maj(va_list ap, t_flags flaggs);
int					ft_printf_p(va_list ap, t_flags flaggs);
int					ft_print_per_cent(t_flags flaggs);

char				*ft_check_if_flags_str(t_flags flaggs, char *str);
char				*ft_check_if_flags_int(t_flags flaggs, char *str);

char				*ft_size_lenght(t_flags flaggs, char *str);
char				*ft_size_lenght_int(t_flags flaggs, char *str);
char				*ft_size_prec(t_flags flaggs, char *str);
char				*ft_size_prec_int(t_flags flaggs, char *str, int negative);

char				*ft_is_blank(t_flags flaggs, char *str, int negative);
char				*ft_is_pos_nul(t_flags flaggs, char *str, int negative);

char				*convert_int_to_octal(uintmax_t i);
char				*convert_int_to_hex(uintmax_t i);
char				*convert_int_to_hex_maj(uintmax_t i);

char				*ft_itoa_intmax_t(intmax_t n);
char				*ft_itoa_uintmax_t(uintmax_t n);
int					ft_atoi_intmax_t(const char *str);

intmax_t			arg_signed_modifier(va_list ap, t_flags b);
uintmax_t			arg_unsigned_modifier(va_list ap, t_flags b);

char				*ft_unicode(wchar_t c);

int					ft_free_return(char **str);

void				ft_lenght_c(t_flags *b, char **str);
int					ft_check_strong_bite(char byte);
int					ft_apply_width(t_flags b, char c);

int					ft_is_flags(char c);
char				*ftf_join_flags(char *str, t_flags b, char *tmp);
char				*ft_join_unicode(char *out_unicode, wchar_t *str);
char				*ft_convert_octal(char *str, uintmax_t i, t_flags b);
int					ft_free_flags_return(char **str, t_flags b);
char				*ft_join_flags_int(t_flags b, char *str);
char				*ft_join_lenght_int(t_flags b, char *tmp, char *str);

#endif
