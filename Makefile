# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manki <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/01 17:31:36 by manki             #+#    #+#              #
#    Updated: 2019/10/06 18:02:28 by manki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

NAME = lem-in

SRC_PATH = ./src/
INC_PATH = ./inc/
OBJ_PATH = ./obj/
LIB_PATH = ./libft/

SRC_NAME = main.c ft_check_line.c ft_check_map.c ft_stock_room.c free.c \
		  ft_add_tube.c ft_room_list.c ft_stock_tube.c \
		   ft_breadth_first_search.c ft_queue_utils.c ft_bfs_utils.c \
		   ft_bfs_utils_2.c ft_cost_computation.c sort.c display_tools.c \
		   ft_debbug_display.c ft_check_arg.c ft_sort_queue.c display.c \
		   ft_display_all.c

INC_NAME = lem_in.h
LIB_NAME = libft.a

OBJ_NAME = $(SRC_NAME:.c=.o)

INC = $(addprefix $(INC_PATH), $(INC_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

CFLAGS = -Wall -Wextra -Werror
CC = gcc -g


##################
##    COLORS    ##
##################

_GREY=$ \033[30m
_RED=$ \033[31m
_GREEN=$ \033[32m
_YELLOW=$ \033[33m
_BLUE=$ \033[34m
_PURPLE=$ \033[35m
_CYAN=$ \033[36m
_WHITE=$ \033[37m
_END=$ \033[0m

##################
##   TARGETS    ##
##################

.PHONY: all clean fclean re norme

all: $(LIB) $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(LIB) $(INC) $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)
	echo "\n✅  $(_GREEN)$(NAME) created 😎 $(_END)"

$(LIB): FORCE
	$(MAKE) -C libft all

FORCE:

clean:
	$(MAKE) -C libft clean
	$(RM) -r $(OBJ_PATH)
	echo "❌  $(_RED)OBJECT FILES DELETED 😱 $(_END)"

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)
	echo "❌  $(_RED)$(NAME) DELETED 😱 $(_END)"

re: fclean all

norme:
	norminette $(INC_PATH) $(SRC_PATH)

.SILENT:
