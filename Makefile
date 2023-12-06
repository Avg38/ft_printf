SRCS	=	ft_printf1.c ft_printf2.c
OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -I.

RM	= rm -f

%.c%.o:	ft_printf.h $<
		${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all : 		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
re:			fclean all
