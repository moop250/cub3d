# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 15:13:08 by hlibine           #+#    #+#              #
#    Updated: 2024/10/07 17:42:45 by hlibine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -D GARBAGE_COLLECTER=0

NAME = extended_ft.a

OBJDIR		= .obj
SRCDIR		= srcs

CC = gcc
CFLAGS += -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

FILES = ft_atoi \
			ft_bzero \
			ft_calloc \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_itoa \
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memmove \
			ft_memset \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putstr_fd \
			ft_split \
			ft_strchr \
			ft_strcmp \
			ft_strdup \
			ft_striteri \
			ft_strjoin \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strmapi \
			ft_strncmp \
			ft_strnstr \
			ft_strrchr \
			ft_strtrim \
			ft_substr \
			ft_tolower \
			ft_toupper \
			ft_realloc \
			ft_3dfree \
			ft_2dfree \
			garbage_collecter \
			garbage_collector_utils \
			ft_lstnew \
			ft_lstadd_front \
			ft_lstsize \
			ft_lstlast \
			ft_lstadd_back \
			ft_lstdelone \
			ft_lstclear \
			ft_lstiter \
			get_next_line/get_next_line \
			ft_printf/ft_printf_utils \
			ft_printf/ft_printf \
			ft_isnumeric \


SRCS = $(addprefix $(SRCDIR)/, $(FILES:=.c))
OBJS = $(addprefix $(OBJDIR)/, $(FILES:=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@printf "\033[0;32mCompiling $<...\033[0m\r"
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf "\033[K"

$(NAME): $(OBJS) $(SRCS)
	@$(AR) $@ $^
	@echo "\033[0;32mextended_ft compiled\033[0m"

all: $(NAME)

clean:
	@$(RM) $(OBJDIR)
	@echo "\033[0;32mextended_ft cleaned\033[0m"

s_clean:
	@$(RM) $(OBJDIR)

fclean: s_clean
	@$(RM) $(NAME)
	@echo "\033[0;32mextended_ft fully cleaned\033[0m"

re: fclean all

.PHONY: all clean fclean re