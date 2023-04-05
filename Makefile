# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 12:22:07 by ljerinec          #+#    #+#              #
#    Updated: 2023/04/05 14:45:46 by ljerinec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME     := so_long
PRINT_PREFIX	= \033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS =	sources/so_long.c \
		sources/hitbox.c \
		sources/parsing/parsing.c \
		includes/get_next_line/get_next_line.c \
		includes/get_next_line/get_next_line_utils.c \
		sources/parsing/map_checker.c \
		sources/parsing/map_checker_2.c \
		sources/parsing/map_checker_3.c \
		sources/parsing/utils.c \
		sources/drawing.c \

OBJS := $(SRCS:%.c=%.o)

FLAGS    = -Wall -Wextra -Werror
CC       = gcc $(FLAGS)

LIBFT_DIR = includes/libft/libft.a
PRINTF_DIR = includes/libft/ft_printf/ft_printf.a
# MLX42_INC = -lglfw -L /Users/ljerinec/.brew/Cellar/glfw/3.3.8/lib/
MLX42_INC = -lglfw -L /opt/homebrew/Cellar/glfw/3.3.8/lib/
MLX42_DIR = includes/MLX42/build/libmlx42.a

################################################################################
#                                  Makefile  objs                              #
################################################################################

all: ${NAME}

$(NAME): $(OBJS)
	@make -C includes/libft
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Compiling so_long \033[0m\n"
	@$(CC) -o $(NAME) $(OBJS) $(MLX42_DIR) $(MLX42_INC) $(LIBFT_DIR) $(PRINTF_DIR)
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Done \033[0m\n"

clean:
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
	@rm -f $(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Done \033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@make -C includes/libft fclean

re: fclean all

.PHONY: all clean fclean re
