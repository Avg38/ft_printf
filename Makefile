SRCS	=	ft_printf.c ft_prints.c
OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -I

RM	= rm -f

.c.o:	libftprintf.h
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all : 		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
re:			fclean all
