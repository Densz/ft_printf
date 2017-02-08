# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/27 10:32:34 by dzheng            #+#    #+#              #
#    Updated: 2017/02/08 19:16:39 by dzheng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Werror -Wextra
LIB = ./libft/libft.a
SRCS_NAME = ft_printf.c \
	ft_print_unsigned.c \
	ft_print_signed.c \
	ft_print_char.c \
	ft_printf_pointer.c \
	ftf_size_prec_lenght.c \
	ftf_check_if_flags.c \
	ftf_convert_arg.c \
	ftf_itoa_max_int.c \
	ftf_convert_to_o_hex.c \
	ft_print_unicode.c \
	ft_free_return.c \
	ftf_lenght_width_spec.c \
	ftf_checker.c \
	ft_join_unicode.c \
	ft_get_width_prec.c
SRCS_PATH		=		srcs/
SRCS			=		$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=		$(SRCS_NAME:.c=.o)
OBJ_PATH		=		obj/
OBJ				=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC				=		./includes/

#COLORS
C_GREEN			=	"\033[33m"
C_END			= 	"\033[0m"

#MESSAGE
SUCCESS			=	SUCCESS$(C_END)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) -I $(INC) $< -o $@

exe:
		@make -C ./libft/
		@cc $(FLAG) $(SRCS) ./test/test_main.c $(LIB) -o a.out
		@echo $(C_GREEN)"Compiling" [ a.out ] $(SUCCESS)
		@./a.out

clean:	
		@make -C ./libft/ fclean
		/bin/rm -rf $(OBJ_PATH)

fclean: clean
		/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
