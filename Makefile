NAME = lem-in

CC = gcc

FLAG += -Wall -Werror -Wextra -g 

SRC = srcs/main.c \
	  
OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a \

all: $(NAME)

$(NAME): $(OBJ)
	@make re -C libft
	@gcc $(FLAG) -o $(NAME) $(SRC) $(LIBFT)
	@echo "\033[94mReady"

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "\033[34mCleaned"

fclean:
	@make clean
	@make fclean -C libft
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "\033[96mfCleaned"

re: fclean all
