# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:45:43 by ntoniolo          #+#    #+#              #
#    Updated: 2017/06/05 00:30:58 by ntoniolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Lolilol

DIR_LFT = libft/
DIR_PS = f_push_swap/
DIR_C = f_checker/

.PHONY: all, clean, fclean, re, $(NAME), lft, start, end

all: lib $(NAME)

$(NAME):
	@(cd $(DIR_PS) && make)
	@(cd $(DIR_C) && make)
	@(cp $(DIR_PS)push_swap ./)
	@(cp $(DIR_C)checker ./)

lib:
	@(cd $(DIR_LFT) && $(MAKE))

bonus :
	@(cd $(DIR_PS) && make)
	@(cd $(DIR_C) && make bonus)
	@(cp $(DIR_PS)push_swap ./)
	@(cp $(DIR_C)checker_b ./)

clean:
	@(cd $(DIR_PS) && make clean)
	@(cd $(DIR_C) && make clean)

fclean: clean
	@/bin/rm -f checker
	@/bin/rm -f checker_b
	@/bin/rm -f push_swap
	@(cd $(DIR_PS) && make fclean)
	@(cd $(DIR_C) && make fclean)

re: fclean all
