# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 23:06:56 by ljerinec          #+#    #+#              #
#    Updated: 2023/04/05 14:47:22 by ljerinec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ftprintf.a

SRCS = 	ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putnbr_hexa.c \
		ft_putstr.c \

OBJS = $(SRCS:%.c=%.o)

NAME     := ft_printf
PRINT_PREFIX	= \033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Compiling \033[0m\n"
	@ar -rcs ft_printf.a $(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Done \033[0m\n"

clean:
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
	@rm -f $(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Done \033[0m\n"

fclean: clean
	@rm -f ft_printf.a

re: fclean all
