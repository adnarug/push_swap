# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 15:33:32 by pguranda          #+#    #+#              #
#    Updated: 2022/08/15 19:13:26 by pguranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap.a
CC		=	cc
CFLAGS	=	-Wextra -Wall -Werror
AR		=	ar rcs
PRINTF	=	printf/
OBJ_DIR	=	objs/
SRC_DIR	=	srcs/

DEF_COLOR = \033[0;80m
GREEN = \033[0;92m

SRC_FILES	=	instructions/instructions_a\
				instructions/instructions_b\
				instructions/instructions_utils\
				sorting/presorting\
				sorting/presorting_utils\
				sorting/sorting\
				stack_ops/duplicate_lst\
				stack_ops/move_process\
				stack_ops/rotating_stacks\
				checks\
				input_parsing\
				lst_utils\
				push_swap\
				score\
				stats
				
SRC		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ		=	$(addprefix	$(OBJ_DIR), $(addsuffix .o, $(SRC_FILES))) 
			
all		:	$(NAME)

OBJF	=	.cache_exists

$(NAME)	:	$(OBJ)
		@make -C $(PRINTF)
		@cp printf/libftprintf.a .
		@mv libftprintf.a $(NAME)
		@$(AR) $(NAME) $(OBJ)
		@ $(CC) push_swap.a -o push_swap
		@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

$(OBJF):
		@mkdir -p $(OBJ_DIR)
		@mkdir -p $(OBJ_DIR)/instructions/
		@mkdir -p $(OBJ_DIR)/sorting/
		@mkdir -p $(OBJ_DIR)/stack_ops/


$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJF)
		@$(CC) $(CFLAGS) -c $< -o $@
		
clean	:
		@rm -rf $(OBJ_DIR)
		@make clean -C $(PRINTF)

fclean	:	clean
		@rm -rf $(NAME)
		@rm -rf $(PRINTF)/libftprintf.a
		@rm -rf push_swap.a
		@rm -rf push_swap
		@rm -rf $(PRINTF)/a.out
		@rm -rf $(PRINTF)/libft/libft.a
		
re		: 	fclean all
		@echo "$(GREEN)Cleaned and rebuilt everything.$(DEF_COLOR)"
		
fclean	:	clean

.PHONY	:	all clean fclean re