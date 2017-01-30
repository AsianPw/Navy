##
## Makefile for lib_epitech in /home/brice/Documents/lib_epitech_piscine
## 
## Made by Brice Lang-Nguyen
## Login   <brice.lang-nguyen@epitech.eu>
## 
## Started on  Fri Jan 27 20:40:45 2017 Brice Lang-Nguyen
## Last update Mon Jan 30 12:36:38 2017 Brice Lang-Nguyen
##

LIST	=	yes

NAME	= 	libmy.a

CC	= 	gcc

RM	= 	rm -f

SRCS	=	./src/error.c	\
		./src/my_getnbr.c \
	  	./src/my_isneg.c \
	  	./src/my_power_rec.c \
	  	./src/my_put_nbr.c \
	  	./src/my_putchar.c \
		./src/my_putstr.c \
		./src/my_revstr.c \
		./src/my_str_isalpha.c \
		./src/my_str_isnum.c \
		./src/my_strcat.c \
		./src/my_strcpy.c \
		./src/my_strlen.c \
		./src/my_strncmp.c \
		./src/my_strncpy.c \
		./src/my_strstr.c \
		./src/my_strcmp.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I./../inc/
CFLAGS += -Wall -Wextra -Werror -ansi -pedantic

all: $(NAME)

$(NAME): $(OBJS)
	 @ar rc $@ $^
	 @echo "\033[33;1mThe $(NAME) is create.\033[0m"

clean:
	@$(RM) $(OBJS)
	@echo "\033[31;1mThe $(NAME) object files have been deleted.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[31;1m$(NAME) is removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re
