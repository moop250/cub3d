# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 14:37:14 by dcaro-ro          #+#    #+#              #
#    Updated: 2024/10/25 19:23:46 by dcaro-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libft.a

CC			=		cc
CFLAGS		=		-Wall -Wextra -Werror

OBJ_DIR		=		obj
INCLUDE_DIR	=		include
PRINTF_DIR	=		ft_printf
STRING_DIR	=		ft_string
LST_DIR		=		ft_lst
GNL_DIR		=		get_next_line
CTYPE_DIR	=		ft_ctype
IO_DIR		=		ft_io
MEM_DIR		=		ft_memory
CONVERT_DIR	=		ft_convert
MATH_DIR	=		ft_math
ALGO_DIR	=		ft_algo

SRCS		=		$(CTYPE_DIR)/ft_isalpha.c\
					$(CTYPE_DIR)/ft_isdigit.c\
					$(CTYPE_DIR)/ft_isalnum.c\
					$(CTYPE_DIR)/ft_isascii.c\
					$(CTYPE_DIR)/ft_isprint.c\
					$(CTYPE_DIR)/ft_isspace.c\
					$(CTYPE_DIR)/ft_toupper.c\
					$(CTYPE_DIR)/ft_tolower.c\
					$(CTYPE_DIR)/ft_isxdigit.c\
					$(CONVERT_DIR)/ft_atoi.c\
					$(CONVERT_DIR)/ft_atoi_base.c\
					$(CONVERT_DIR)/ft_itoa.c\
					$(CONVERT_DIR)/ft_strtol.c\
					$(MATH_DIR)/ft_abs.c\
					$(MATH_DIR)/ft_swap.c\
					$(MATH_DIR)/ft_max.c\
					$(MATH_DIR)/ft_min.c\
					$(MATH_DIR)/ft_clamp.c\
					$(MEM_DIR)/ft_bzero.c\
					$(MEM_DIR)/ft_calloc.c\
					$(MEM_DIR)/ft_free.c\
					$(MEM_DIR)/ft_memchr.c\
					$(MEM_DIR)/ft_memcmp.c\
					$(MEM_DIR)/ft_memcpy.c\
					$(MEM_DIR)/ft_memmove.c\
					$(MEM_DIR)/ft_memresize.c\
					$(MEM_DIR)/ft_memset.c\
					$(MEM_DIR)/ft_realloc.c\
					$(MEM_DIR)/ft_safe_free.c\
					$(MEM_DIR)/ft_safe_malloc.c\
					$(MEM_DIR)/ft_safe_memresize.c\
					$(MEM_DIR)/ft_safe_realloc.c\
					$(STRING_DIR)/ft_strlen.c\
					$(STRING_DIR)/ft_strclen.c\
					$(STRING_DIR)/ft_strcpy.c\
					$(STRING_DIR)/ft_strncpy.c\
					$(STRING_DIR)/ft_strlcpy.c\
					$(STRING_DIR)/ft_strcat.c\
					$(STRING_DIR)/ft_strlcat.c\
					$(STRING_DIR)/ft_strchr.c\
					$(STRING_DIR)/ft_strrchr.c\
					$(STRING_DIR)/ft_strcmp.c\
					$(STRING_DIR)/ft_strncmp.c\
					$(STRING_DIR)/ft_strnstr.c\
					$(STRING_DIR)/ft_strdup.c\
					$(STRING_DIR)/ft_strndup.c\
					$(STRING_DIR)/ft_substr.c\
					$(STRING_DIR)/ft_strjoin.c\
					$(STRING_DIR)/ft_strjoin_char.c\
					$(STRING_DIR)/ft_strtrim.c\
					$(STRING_DIR)/ft_split.c\
					$(STRING_DIR)/ft_free_split.c\
					$(STRING_DIR)/ft_strmapi.c\
					$(STRING_DIR)/ft_striteri.c\
					$(STRING_DIR)/ft_strspn.c\
					$(STRING_DIR)/ft_strstr.c\
					$(STRING_DIR)/ft_strtok.c\
					$(STRING_DIR)/ft_concat_strs.c\
					$(STRING_DIR)/ft_strisalnum.c\
					$(IO_DIR)/ft_putchar_fd.c\
					$(IO_DIR)/ft_putstr_fd.c\
					$(IO_DIR)/ft_putendl_fd.c\
					$(IO_DIR)/ft_putnbr_fd.c\
					$(LST_DIR)/ft_lstnew.c\
					$(LST_DIR)/ft_lstadd_front.c\
					$(LST_DIR)/ft_lstsize.c\
					$(LST_DIR)/ft_lstlast.c\
					$(LST_DIR)/ft_lstadd_back.c\
					$(LST_DIR)/ft_lstdelone.c\
					$(LST_DIR)/ft_lstclear.c\
					$(LST_DIR)/ft_lstiter.c\
					$(LST_DIR)/ft_lstmap.c\
					$(PRINTF_DIR)/ft_printf.c\
					$(PRINTF_DIR)/ft_printf_utils.c\
					$(PRINTF_DIR)/ft_handle_specifier.c\
					$(PRINTF_DIR)/ft_handle_char.c\
					$(PRINTF_DIR)/ft_handle_str.c\
					$(PRINTF_DIR)/ft_handle_int.c\
					$(PRINTF_DIR)/ft_handle_uint.c\
					$(PRINTF_DIR)/ft_handle_hex.c\
					$(PRINTF_DIR)/ft_handle_ptr.c\
					$(PRINTF_DIR)/ft_handle_percent.c\
					$(GNL_DIR)/get_next_line.c\
					$(GNL_DIR)/get_next_line_utils.c\
					$(ALGO_DIR)/ft_bubble_sort.c\

OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
