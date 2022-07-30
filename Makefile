# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 15:33:32 by pguranda          #+#    #+#              #
#    Updated: 2022/07/30 13:51:08 by pguranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap.a
INCLUDE	=	include/push_swap.h
CC		=	cc
CFLAGS	=	-Werror -Wextra -Wall -g -I 
AR		=	ar rcs
PRINTF	=	printf/
OBJ_DIR	=	objs/
SRC_DIR	=	srcs/

#COLORS
DEF_COLOR = \033[0;80m
GREEN = \033[0;92m

SRC_FILES	=	lst_utils\
				instructions\
				cases\
				main
				
SRC		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ		=	$(addprefix	$(OBJ_DIR), $(addsuffix .o, $(SRC_FILES))) 
			
all		:	$(NAME)

OBJF	=	.cache_exists

$(NAME)	:	$(OBJ)
		@make -C $(PRINTF)
		@cp printf/libftprintf.a .
		@mv libftprintf.a $(NAME)
		@$(AR) $(NAME) $(OBJ)
		@ $(CC) -g push_swap.a -o push_swap
		@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

$(OBJF):
		@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJF)
#		@echo "Compiling: $< ..."
		@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
		
clean	:
		@rm -rf $(OBJ_DIR)
		@make clean -C $(PRINTF)

#maybe %.a instead of going into the subfolders
fclean	:	clean
		@rm -rf $(NAME)
		@rm -rf $(PRINTF)/libftprintf.a
		@rm -rf push_swap.a
		@rm -rf a.out
		@rm -rf $(PRINTF)/a.out
		@rm -rf $(PRINTF)/libft/libft.a
		
re		: 	fclean all
		@echo "$(GREEN)Cleaned and rebuilt everything.$(DEF_COLOR)"
		
fclean	:	clean

.PHONY	:	all clean fclean re