/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:53:55 by egreen            #+#    #+#             */
/*   Updated: 2018/02/10 16:03:14 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdbool.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

# define HEXVALUE "0123456789abcdef0123456789ABCDEF"

typedef struct		s_print
{
	int				fd;
	int				ret;
	int				strlen;
	bool			wstr;
	char			*format;
	va_list			arg;
}					t_print;

typedef union		u_raw
{
	wchar_t			*bigs;
	char			chr;
	char			*str;
	intmax_t		super;
	uintmax_t		super_u;
	void			*ptr;
}					t_raw;

typedef struct		s_spec
{
	bool			aform;
	bool			left_align;
	bool			prepend_space;
	bool			prepend_zero;
	bool			show_sign;
	char			lgth[3];
	char			type;
	int				len;
	int				prec;
	int				width;
	int				*ret;
	int				*fd;

	va_list			*arg;
	t_raw			data;
}					t_spec;

typedef struct		s_format
{
	char			sign;
	char			*print;
	int				lgth;
	int				spaces;
	int				zrs;
}					t_format;

int					ft_isflag(char test);
int					flags(t_spec *ts, char *format);
int					ft_islgth(char c);
void				parse(t_print *ptr);
int					find_flags(t_spec *ts, char *format, int *x);
void				casting(t_print *ptr, t_spec *ts);
void				unsigned_casting(t_print *ptr, t_spec *ts);
void				format_char(t_print *ptr, t_spec *ts);
void				format_percent(t_spec *ts);
void				format_string(t_print *ptr, t_spec *ts);
void				format_decimal(t_print *ptr, t_spec *ts);
void				format_udecimal(t_print *ptr, t_spec *ts);
void				format_pointer(t_print *ptr, t_spec *ts);
void				format_octal(t_print *ptr, t_spec *ts);
void				format_hex(t_print *ptr, t_spec *ts);
char				*ft_ptf_itoabase(uintmax_t val, int base, int opt);
void				format_wstring(t_print *ptr, t_spec *ts);
void				form_dec_helper(t_format *form, t_spec *ts);
void				d_print_char(t_spec *ts, char c, int times);
void				hex_helper(t_format *form, t_spec *ts);
void				hex_helper2(t_format *form, t_spec *ts);
void				hex_print(t_spec *ts, char print, int times);
int					ft_printf(const char *format, ...);

#endif
