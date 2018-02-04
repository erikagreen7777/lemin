# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egreen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/24 12:02:21 by egreen            #+#    #+#              #
#    Updated: 2017/10/04 14:50:06 by egreen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
	  ft_putchar_fd.c \
	  ft_strdel.c \
	  ft_strnequ.c \
	  ft_bzero.c \
	  ft_putendl.c \
	  ft_strdup.c \
	  ft_strnew.c \
	  ft_memalloc.c \
	  ft_putendl_fd.c \
	  ft_strequ.c \
	  ft_strnstr.c \
	  ft_isalnum.c \
	  ft_memccpy.c \
	  ft_putnbr.c \
	  ft_striter.c \
	  ft_strrchr.c \
	  ft_isalpha.c \
	  ft_memchr.c \
	  ft_putnbr_fd.c \
	  ft_striteri.c \
	  ft_isascii.c \
	  ft_memcmp.c \
	  ft_putstr.c \
	  ft_strjoin.c \
	  ft_strstr.c \
	  ft_isdigit.c \
	  ft_memcpy.c \
	  ft_putstr_fd.c \
	  ft_strlcat.c \
	  ft_strsub.c \
	  ft_isprint.c \
	  ft_memdel.c \
	  ft_strcat.c \
	  ft_strlen.c \
	  ft_strtrim.c \
	  ft_itoa.c \
	  ft_memmove.c \
	  ft_strchr.c \
	  ft_strmap.c \
	  ft_memset.c \
	  ft_strclr.c \
	  ft_strmapi.c \
	  ft_tolower.c \
	  ft_strcmp.c \
	  ft_strncat.c \
	  ft_toupper.c \
	  ft_strncmp.c \
	  ft_putchar.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_intlen.c \
	  ft_strrev.c \
	  ft_strsplit.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_strfjoin.c \
	  get_next_line.c \
	  casting.c \
	  decimal_helper.c \
	  find_flags.c \
	  format_char.c \
	  format_decimal.c \
	  format_hex.c \
	  format_octal.c \
	  format_percent.c \
	  format_pointer.c \
	  format_string.c \
	  format_udecimal.c \
	  format_wstring.c \
	  ft_printf.c \
	  ft_ptf_itoabase.c \
	  helper.c \
	  hex_helper.c \
	  parse.c \
	  ft_ispositive.c \
	  ft_swap.c \
	  ft_error.c \
	  ft_fputstr_fd.c \
	  ft_strndup.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c -I libft.a -g $(SRC)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean