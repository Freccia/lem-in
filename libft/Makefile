# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/27 11:20:09 by lfabbro           #+#    #+#              #
#    Updated: 2016/09/21 10:24:34 by lfabbro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME = ft_printf.c ft_pf_lenght.c ft_pf_parse.c ft_pf_set.c\
		   ft_pf_padding.c ft_pf_conversions.c ft_pf_handle_wchar.c\
		   ft_pf_formats_00.c ft_pf_formats_01.c ft_pf_a_char.c ft_pf_a_hex.c\
		   ft_pf_a_int.c ft_pf_a_octal.c ft_pf_a_ptr.c ft_pf_a_str.c\
		   ft_pf_a_uint.c ft_pf_a_wstr.c ft_pf_a_wchar.c

SRC_LIB_NAME = ft_strlen.c ft_strstr.c ft_strcpy.c ft_strdup.c ft_strndup.c\
			   ft_strcat.c ft_strcmp.c ft_strncpy.c ft_strncat.c ft_strlcat.c\
			   ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c\
			   ft_itoa_base.c ft_imaxtoa_base.c ft_uimaxtoa_base.c ft_isalpha.c\
			   ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
			   ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
			   ft_memmove.c ft_memchr.c ft_memcmp.c ft_memdel.c ft_strnew.c\
			   ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
			   ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
			   ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c\
			   ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putendl_fd.c\
			   ft_putnbr_fd.c ft_putstr_fd.c ft_memalloc.c ft_lstnew.c\
			   ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c\
			   ft_lstmap.c ft_wstrlen.c ft_abs.c ft_swap.c ft_convert_base.c\
			   ft_realloc.c ft_getnbr.c ft_wchar_size.c ft_nbrlen.c\
			   ft_atol.c ft_atoll.c ft_isnbr.c ft_getchar.c\
			   get_next_line.c


LIB_NAME = ft

SRC_PATH = ./srcs/
OBJ_PATH = ./objs
INC_PATH = ./includes
LIB_PATH = ./libft/

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INC)


## OBJECTS ##
OBJ_NAME = $(addprefix $(SRC_PATH),$(SRC_NAME:.c=.o))
OBJ_LIB = $(addprefix $(LIB_PATH),$(SRC_LIB_NAME:.c=.o))
OBJ = $(OBJ_NAME) $(OBJ_LIB)

## INCLUDES ##
INC = $(addprefix -I,$(INC_PATH))

## LIBRARIES ##
LIB_LINK = $(addprefix -L,$(LIB_PATH))
LIB = $(addprefix -l,$(LIB_NAME))

.PHONY: $(NAME) all clean fclean re norme

## RULES ##
all : 
	@echo "\x1b[44m\x1b[32mMaking libft\x1b[0m\x1b[0m"
	@make $(NAME)

$(NAME): 
	@make $(OBJ_LIB)
	@make $(OBJ_NAME)
	@ar -rc $(NAME) $(OBJ) $(OBJ_LIB)
	@ranlib $(NAME)

clean:
	@/bin/rm -fv $(OBJ_NAME)
	@/bin/rm -fv $(OBJ_LIB)

fclean: clean
	@/bin/rm -fv $(NAME)

re: fclean all

norme :
	norminette **/*.[ch]
