# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 15:24:44 by pguranda          #+#    #+#              #
#    Updated: 2022/08/12 14:19:02 by pguranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a


SRCS	=	ft_atoi.c 		ft_bzero.c 		ft_calloc.c\
			ft_isalnum.c	ft_isalpha.c	ft_isascii.c\
			ft_isdigit.c	ft_isprint.c	ft_memchr.c\
			ft_memcmp.c		ft_memcpy.c		ft_memmove.c\
			ft_memset.c		ft_strchr.c		ft_strrchr.c\
			ft_strdup.c		ft_strlen.c		ft_strlcpy.c\
			ft_strlcat.c	ft_strncmp.c	ft_strnstr.c\
			ft_tolower.c	ft_toupper.c	ft_substr.c\
			ft_strjoin.c	ft_split.c\
			ft_itoa.c		ft_strmapi.c	ft_striteri.c\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c\
			ft_putnbr_fd.c	ft_lstadd_front.c	ft_lstadd_back.c\
			ft_lstsize.c	ft_lstlast.c	ft_lstnew.c\
			ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c
			
OBJ		=	$(SRCS:%.c=%.o)

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS = $(BONUS:%.c=%.o)

HEADER	=	libft.h

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	@ar rcs $(NAME) $(OBJ) 

bonus : $(BONUS_OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)

%.o		:	%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all

.PHONY	: clean all fclean