# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:45:43 by ntoniolo          #+#    #+#              #
#    Updated: 2017/06/04 18:42:08 by ntoniolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

DIR_LFT = ../libft/
DIR_MLXJI = ../libmlxji/

FLAGS = -Wall -Werror -Wextra -g -I ./include/

LIB_MLX = -L./../libmlxji/ -lmlxji -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

SRC_PS = main.c \
		 pars.c \
		 free_env.c \
		 loop_check.c \
		 crea_var.c \
		 do_op.c \
		 tool/to_libft.c \
		 tool/ft_remove_index_lst.c \
		 tool/find_mediane.c \
		 tool/size_grp.c \
		 tool/verif_order.c \
		 tool/aff_final.c \
		 tool/sort_tab.c \
		 tool/find_place.c \
		 tool/ft_lstlast.c \
		 tool/print_pile.c \
		 instruction/instruction_swap.c \
		 instruction/instruction_rotate.c \
		 instruction/instruction_reverse_rotate.c \
		 instruction/instruction_push.c \
		 algo/little_algo_1.c \
		 algo/little_algo_2.c \
		 algo/algo_p_a.c \
		 algo/algo_p_b.c \
		 algo/my_algo.c \
		 algo/case_p_a.c \
		 algo/case_p_b.c

SRC_GRAPH =

SRC_DIR = srcs/
GRAPH_DIR = srcs/graph/

CC = gcc

INC = includes/

INC_FILES = includes/push_swap.h

OBJET_PS = $(SRC_PS:.c=.o)
OBJET_GRAPH = $(SRC_GRAPH:.c=.o)

OBJ_DIR = objs/
OBJ_GRAPH = objs/graph/

.PHONY: all, clean, fclean, re, $(NAME), lft, start, end

all: start lib $(NAME) end

$(NAME): $(OBJ_DIR) $(OBJ_GRAPH) $(addprefix $(OBJ_DIR), $(OBJET_PS)) $(addprefix $(OBJ_GRAPH), $(OBJET_GRAPH)) $(INC_FILES)
	@$(CC) -I$(INC) $(addprefix $(OBJ_DIR), $(OBJET_PS)) $(addprefix $(OBJ_GRAPH), $(OBJET_GRAPH)) -L./$(DIR_LFT)  -lft -o $(NAME)

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)
	@mkdir $(OBJ_DIR)/tool
	@mkdir $(OBJ_DIR)/algo
	@mkdir $(OBJ_DIR)/instruction

$(OBJ_GRAPH) :
	@mkdir $(OBJ_GRAPH)

start:
	@echo "\033[4m\033[33mCreation de $(NAME)   ...\033[0m"

end:
	@echo "\033[4m\033[1m\033[32m>$(NAME) done.\033[0m"

$(OBJ_DIR)%.o: $(addprefix $(SRC_DIR), %.c) $(INC_FILES)
	@echo "\033[34m$^ \033[0m-> \033[1m\033[37m$@\033[0m"
	@($(CC) $(FLAGS)  -I$(INC) -c -o $@ $<)

$(OBJ_GRAPH)%.o: $(addprefix $(GRAPH_DIR), %.c) $(INC_FILES)
	@echo "\033[34m$^ \033[0m-> \033[1m\033[37m$@\033[0m"
	@($(CC) $(FLAGS)  -I$(INC) -c -o $@ $<)

lib:
	@(cd $(DIR_LFT) && $(MAKE))

clean:
	@echo "\033[31mDelete .o of $(NAME)\033[0m"
	@/bin/rm -rf $(OBJ_DIR)
	@(cd $(DIR_LFT) && make clean)

fclean: clean
	@echo "\033[31mDelete .o and $(NAME)\033[0m"
	@/bin/rm -f $(NAME)
	@(cd $(DIR_LFT) && make fclean)

re: fclean all
