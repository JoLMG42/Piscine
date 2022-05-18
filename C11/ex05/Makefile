# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 09:42:42 by jtaravel          #+#    #+#              #
#    Updated: 2021/11/03 11:01:49 by jtaravel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS = includes

SRCS =	srcs/ft_calcul.c srcs/ft_fdm.c srcs/main.c

OBJS =	${SRCS:.c=.o}


CC =	gcc

CFLAGS =	-Wall -Wextra -Werror

RM = rm -f

.c.o:
		${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${CC} -o ${NAME} ${OBJS}

all:		${OBJS}
		gcc -o do-op ${OBJS}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} do-op

re:		fclean all

.PHONY:		all clean fclean re
