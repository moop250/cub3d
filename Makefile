# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:51:54 by hlibine           #+#    #+#              #
#    Updated: 2024/10/21 16:29:44 by dcaro-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Genral values
NAME		= cub3d

CC			= gcc
FLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf

OBJDIR		= .obj
SRCDIR		= srcs

# Minilibx stuff
MINILIBX_LINUX_PATH = libs/minilibx-linux/
MINILIBX_MAC_PATH = libs/minilibx_opengl/
MINILIBX = libmlx.a
MINILIBX_PATH =

# Detect the OS
OS = $(shell uname -s)

ifeq ($(OS),Linux)
	FLAGS += -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MINILIBX_PATH = $(MINILIBX_LINUX_PATH)
endif

ifeq ($(OS),Darwin)
	FLAGS += -framework OpenGL -framework AppKit
	MINILIBX_PATH = $(MINILIBX_MAC_PATH)
endif

# Colors
GREEN		= \033[0;32m
ORANGE		= \033[38;5;208m
LBLUE		= \033[0;36m
RESET		= \033[0m
RESETNL		= \033[0m\n

# Files

FILES		= main \
				parsing/parsing \
				parsing/parse_file \
				parsing/parse_map \
				parsing/parse_clean \
				parsing/parse_textures \
				parsing/parse_colors \
				error_handling/error \

SRCS		= $(addprefix $(SRCDIR)/, $(FILES:=.c))
OBJS		= $(addprefix $(OBJDIR)/, $(FILES:=.o))

# External libs
MINILIBX := $(MINILIBX_PATH)$(MINILIBX)

LIBFT_DIR = libs/libft/
EXFT_LIB = $(LIBFT_DIR:%=%libft.a)

# Compilation
$(NAME): $(SRCS) $(OBJS) $(EXFT_LIB) $(MINILIBX)
	@printf "$(ORANGE)Compiling $(NAME)$(RESET)"
	@ $(CC) $(OBJS) $(EXFT_LIB) $(MINILIBX) -o $(NAME) $(FLAGS)
	@printf "\r\033[K"
	@printf "$(GREEN)$(NAME) compiled$(RESETNL)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(ORANGE)Compiling $@...$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@
	@printf "\r\033[K"
	@printf "\033[0;32m$(GREEN)$@ compiled!$(RESETNL)"

$(EXFT_LIB): $(LIBFT_DIR)Makefile
	@make -C $(LIBFT_DIR)

$(MINILIBX): $(MINILIBX_PATH)Makefile
	@make -s all -C $(MINILIBX_PATH)

# Rules
all: $(NAME)

clean:
	@printf "$(ORANGE)Cleaning up...$(RESET)"
	@$(RM) $(OBJDIR) $(OBJS)
	@make -s fclean -C $(LIBFT_DIR)
	@make -s clean -C $(MINILIBX_PATH)
	@printf "\r\033[K"
	@printf "$(GREEN)Clean up successful$(RESETNL)"

s_clean:
	@$(RM) $(NAME) $(OBJDIR) $(OBJS)
	@make -s fclean -C $(LIBFT_DIR)
	@make -s clean -C $(MINILIBX_PATH)

fclean: s_clean
	@printf "$(ORANGE)Full clean up...$(RESET)"
	@$(RM) $(NAME)
	@printf "\r\033[K"
	@printf "$(GREEN)Full clean up successful$(RESETNL)"

clear: clean

fclear: fclean

re: fclean all

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/default.cub

help:
	@printf "$(LBLUE)make$(RESET) : complies the project.\n"
	@printf "$(LBLUE)make all$(RESET) : complies the project.\n"
	@printf "$(LBLUE)make re$(RESET) : recompiles the project.\n"
	@printf "$(LBLUE)make clean$(RESET) : removes the object files.\n"
	@printf "$(LBLUE)make fclean$(RESET) : removes all files generated by this Makefile.\n"

.PHONY: all clean fclean clear fclear re help valgrind
