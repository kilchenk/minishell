# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 14:34:23 by kilchenk          #+#    #+#              #
#    Updated: 2023/10/05 12:52:10 by kilchenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIB_F = Libft
LIB = libft.a
SRC = src
OBJ = obj
INC = inc
CFLAGS = -Wextra -Werror -Wall -fsanitize=address -g -I $(INC)
#DEBUG_SEG_FAULTS = -fsanitize=address #for segfault checking
RM = rm -rf
CC = gcc
SRCS = src/main.c src/lexer.c src/split.c src/split2.c src/lexer2.c src/errors.c \
		src/expander.c src/utils.c src/redirection.c src/redirection2.c src/execut.c \
		src/expander1.c src/cd.c src/exit.c src/unset.c src/signals.c src/execut1.c \
		src/utils1.c src/split3.c src/redirection3.c src/pwd.c src/env.c src/echo.c
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB_F)/$(LIB)
	@$(CC) $(CFLAGS)  $(OBJS) $(LIB_F)/$(LIB) -o $(NAME)  -lreadline

$(LIB_F)/$(LIB):
	@make -C $(LIB_F)
	@echo "libft is done!"

clean:
	@$(RM) $(OBJS)
	@rm -rf obj
	@echo "successfuly cleaned"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_F)
	@echo "executable removed successfuly"

re: fclean all