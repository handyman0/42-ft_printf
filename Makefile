# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 16:34:59 by lmelo-do          #+#    #+#              #
#    Updated: 2025/08/07 20:57:18 by lmelo-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
RESET = \033[0m

SRCS =  ft_printf.c ft_putchar.c ft_putstr.c \
		ft_putnbr.c ft_puthex.c ft_putptr.c
OBJS = ${SRCS:.c=.o}

header:
	@echo "$(GREEN)██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗$(RESET)"
	@echo "$(GREEN)██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝$(RESET)"
	@echo "$(GREEN)██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗$(RESET)"
	@echo "$(GREEN)██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝$(RESET)"
	@echo "$(GREEN)██║     ██║  ██║██║██║ ╚████║   ██║   ██║$(RESET)"
	@echo "$(GREEN)╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝$(RESET)"
	@echo "$(GREEN)                               by lmelo-do$(RESET)"

all: header ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

.PHONY: all clean fclean re
