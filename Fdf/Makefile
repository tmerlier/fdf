# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/20 14:06:06 by tmerlier          #+#    #+#              #
#    Updated: 2015/02/10 14:50:44 by tmerlier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBMLX = /usr/X11/lib -lmlx -lXext -lX11

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

DIRLIB = libft/

DIRSRC = srcs/

DIRH = includes/

SRC = main.c \
	  matrix.c \
	  fdf.c \
	  read_matrix.c \
	  draw.c \
	  mlx.c \
	  clear.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(DIRLIB)
	@$(CC) $(FLAGS) -o $(NAME) $^ -I$(DIRLIB) -I$(DIRH) -L$(DIRLIB) -lft -L$(LIBMLX)
	@echo "\033[1;32m$(NAME): OK\033[0m"

%.o: $(DIRSRC)%.c $(DIRH)
	@echo -n .
	@$(CC) $(FLAGS) -o $@ -c $< -I$(DIRLIB)$(DIRH) -I$(DIRH)

clean:
	@rm -f $(OBJ)
	@make clean -s -C $(DIRLIB)
	@echo "\033[4;32mDeleted:\033[0;33m $(OBJ)\033[0m"

fclean: clean
	@make -C $(DIRLIB) $@
	@rm -f $(NAME)
	@echo "\033[4;32mDeleted:\033[0;33m $(NAME)\033[0m"

re: fclean all

.PHONY: all clean fclean re
