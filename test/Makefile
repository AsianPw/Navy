NAME	= program

CC	= gcc

RM	= rm -f

SRCS	= ./main.c 

OBJS	= $(SRCS:.c=.o)

LIB = -L. -lgnl
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
