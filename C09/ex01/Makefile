# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 16:55:06 by jtaravel          #+#    #+#              #
#    Updated: 2021/11/02 09:51:22 by jtaravel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS =	includes

SRCS =	srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c

OBJS =	${SRCS:.c=.o}

NAME =	libft.a	

CC =	gcc

RM =	rm -f

CFLAGS =	-Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

all :		${NAME}

clean:
		${RM} ${OBJS}

fclean: 	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean flcean re

