# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 18:07:52 by lfabbro           #+#    #+#              #
#    Updated: 2016/09/04 13:12:49 by lfabbro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRC_NAME = main.c\
		   lem_in.c\
		   weights.c path.c\
		   parsing_nodes.c parsing_tubes.c options.c\
		   check.c help.c new.c ft_free.c error.c ft_xword.c\
		   print.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAMES = ftprintf

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
LIB_PATH = ./libftprintf/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

## SOURCES ##
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))


## INCLUDES ##
INC = $(addprefix -I,$(INC_PATH))


## LIBRARIES ##
LIB_LINK = $(addprefix -L,$(LIB_PATH))
LIB = $(addprefix -l,$(LIB_NAMES))

.PHONY: all clean fclean re norme

## RULES ##
all:
	@make -C $(LIB_PATH)
	@make -C $(LIB_PATH) clean
	@echo "\x1b[44m\x1b[32mMaking $(NAME)\x1b[0m\x1b[0m"
	@make $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(INC) $(LIB_LINK) $(LIB) $(SRC) -o $(NAME)

clean :
	@/bin/rm -fv $(OBJ)

fclean : clean
	@/bin/rm -fv $(NAME)

libre :
	@make -C $(LIB_PATH) re

libclean :
	@make -C $(LIB_PATH) clean

libfclean :
	@make -C $(LIB_PATH) fclean

re : fclean all

norme :
	norminette $(SRC)
	norminette $(INC_PATH)*
