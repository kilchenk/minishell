# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 15:03:48 by hsievier          #+#    #+#              #
#    Updated: 2023/08/30 15:03:50 by hsievier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIB_F = Libft
LIB = libft.a
SRC = src
OBJ = obj
INC = inc
CFLAGS = -Wall -Wextra -Werror -g -I $(INC)
DEBUG_SEG_FAULTS = -fsanitize=address #for segfault checking
RM = rm -rf
CC = gcc
SRCS = src/main.c 
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