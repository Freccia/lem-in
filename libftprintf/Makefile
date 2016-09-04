# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/27 11:20:09 by lfabbro           #+#    #+#              #
#    Updated: 2016/09/04 13:13:58 by lfabbro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_NAME = ft_printf.c lenght.c parse.c set.c padding.c conversions.c\
		   handle_wchar.c formats_00.c formats_01.c a_char.c a_hex.c\
		   a_int.c a_octal.c a_ptr.c a_str.c a_uint.c a_wstr.c a_wchar.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_LIB_NAME = ft_strlen.o ft_strstr.o ft_strcpy.o ft_strdup.o ft_strndup.o\
			   ft_strcat.o ft_strcmp.o ft_strncpy.o ft_strncat.o ft_strlcat.o\
			   ft_strchr.o ft_strrchr.o ft_strnstr.o ft_strncmp.o ft_atoi.o\
			   ft_itoa_base.o ft_imaxtoa_base.o ft_uimaxtoa_base.o ft_isalpha.o\
			   ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o\
			   ft_tolower.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o\
			   ft_memmove.o ft_memchr.o ft_memcmp.o ft_memdel.o ft_strnew.o\
			   ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o\
			   ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o\
			   ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o\
			   ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putendl_fd.o\
			   ft_putnbr_fd.o ft_putstr_fd.o ft_memalloc.o ft_lstnew.o\
			   ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o\
			   ft_lstmap.o ft_wstrlen.o ft_abs.o ft_swap.o ft_convert_base.o\
			   ft_realloc.o ft_getnbr.o ft_wchar_size.o ft_nbr_size.o\
			   ft_atol.o ft_atoll.o ft_isnbr.o\
			   ft_nbr_size.o ft_getchar.o\
			   get_next_line.o
LIB_NAME = ft

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./inc/
LIB_PATH = ./libft/
LIBFT = $(addprefix $(LIB_PATH),libft.a)

CC = gcc
CFLAGS = -Wall -Wextra -Werror


## SOURCES ##
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ_PRINTF = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_LIBFT = $(addprefix $(LIB_PATH),$(OBJ_LIB_NAME))


## INCLUDES ##
INC = $(addprefix -I,$(INC_PATH))


## LIBRARIES ##
LIB_LINK = $(addprefix -L,$(LIB_PATH))
LIB = $(addprefix -l,$(LIB_NAME))

.PHONY: makelibft clean fclean re norme

## RULES ##
all : 
	@echo "\x1b[44m\x1b[32m Making libft \x1b[0m\x1b[0m"
	@make -C $(LIB_PATH)
	@echo "\x1b[44m\x1b[32m Making libftprintf \x1b[0m\x1b[0m"
	@make $(NAME)

$(NAME): 
	@make $(OBJ_PRINTF)
	ar -rcs $(NAME) $(OBJ_LIBFT) $(OBJ_PRINTF)
	@make -C $(LIB_PATH) clean
	@make clean
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean :
	@/bin/rm -fv $(OBJ_LIBFT)
	@/bin/rm -fv $(OBJ_PRINTF)
	@/bin/rm -rfv $(OBJ_PATH)

fclean : clean
	@/bin/rm -fv $(LIBFT)
	@/bin/rm -fv $(NAME)

re : fclean all

norme :
	norminette **/*.[ch]
