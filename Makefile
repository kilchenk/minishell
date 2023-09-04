# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 14:34:23 by kilchenk          #+#    #+#              #
#    Updated: 2023/09/04 13:48:13 by hsievier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIB_F = Libft
LIB = libft.a
SRC = src
OBJ = obj
INC = inc
#CFLAGS = -fsanitize=address -g -I $(INC) #-Wextra -Werror -Wall
#DEBUG_SEG_FAULTS = -fsanitize=address #for segfault checking
RM = rm -rf
CC = gcc
SRCS = src/main.c src/lexer.c src/split.c src/split2.c src/lexer2.c src/errors.c \
		src/expander.c src/utils.c src/redirection.c src/redirection1.c
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