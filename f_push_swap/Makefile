# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:45:43 by ntoniolo          #+#    #+#              #
#    Updated: 2017/05/17 23:58:49 by ntoniolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

DIR_LFT = ../libft/

FLAGS = -Wall -Werror -Wextra -g

SRC_PS = main.c \
		 to_libft.c \
		 loop_check.c \
		 ft_remove_index_lst.c \
		 instruction_swap.c \
		 instruction_rotate.c \
		 instruction_reverse_rotate.c \
		 ft_lstlast.c \
		 instruction_push.c \
		 crea_var.c

SRC_DIR = srcs/

CC = gcc

INC = includes/

INC_FILES = includes/push_swap.h

OBJET_PS = $(SRC_PS:.c=.o)

OBJ_DIR = objs/

.PHONY: all, clean, fclean, re, $(NAME), lft, start, end

all: start lib $(NAME) end

$(NAME): $(OBJ_DIR) $(addprefix $(OBJ_DIR), $(OBJET_PS)) $(INC_FILES)
	@$(CC) -I$(INC) $(addprefix $(OBJ_DIR), $(OBJET_PS)) -L./$(DIR_LFT) -lft -o $(NAME)

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

start:
	@echo "\033[4m\033[33mCreation de $(NAME)   ...\033[0m"

end:
	@echo "\033[4m\033[1m\033[32m>$(NAME) done.\033[0m"

$(OBJ_DIR)%.o: $(addprefix $(SRC_DIR), %.c) $(INC_FILES)
	@echo "\033[34m$^ \033[0m-> \033[1m\033[37m$@\033[0m"
	#@$(CC) $(FLAGS) -I$(INC) -c $^ -o $@
	@($(CC) $(FLAGS) -I$(INC) -c -o $@ $<)

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
