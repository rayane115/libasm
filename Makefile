# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 14:54:43 by ncolomer          #+#    #+#              #
#    Updated: 2020/05/13 02:09:51 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_strlen.s ft_write.s ft_read.s ft_strcpy.s ft_strcmp.s ft_strdup.s
OBJS		=	$(SRCS:.s=.o)
NA			=	nasm
NA_FLAGS	=	-f elf64
FLAGS 		=	-Wall -Werror -Wextra
NAME		=	libasm.a

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar crs $(NAME) $(OBJS)
				ranlib $(NAME)

				
clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME)
				

re:				fclean $(NAME)


.PHONY:			clean fclean re test bonus test_bonus
