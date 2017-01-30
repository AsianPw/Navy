##
## Makefile for Navy in /home/brice/Documents/PSU/PSU_2016_navy
## 
## Made by Brice Lang-Nguyen
## Login   <brice.lang-nguyen@epitech.eu>
## 
## Started on  Mon Jan 30 12:15:14 2017 Brice Lang-Nguyen
## Last update Mon Jan 30 12:26:03 2017 Brice Lang-Nguyen
##

DEBUG	=	no

NAME	=	navy

CC	= 	gcc

RM	= 	rm -f

SRCS	= 

OBJS	= 	$(SRCS:.c=.o)

CFLAGS = 	-I./inc/

ifeq ($(DEBUG), yes)
	CFLAGS += 	-g -Wall -Wextra
else
	CFLAGS += 	-Wall -Wextra -Werror
endif

all: $(NAME)

$(NAME): $(OBJS)
ifeq ($(DEBUG), yes)
	@echo "\033[31;1mGeneration in debug mode\033[0m"
else
	@echo "\033[32;1mGeneration in release mode\033[0m"
endif
	$(CC) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
