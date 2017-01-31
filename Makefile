##
## Makefile for Navy in /home/brice/Documents/PSU/PSU_2016_navy
##
## Made by Brice Lang-Nguyen
## Login   <brice.lang-nguyen@epitech.eu>
##
## Started on  Mon Jan 30 12:15:14 2017 Brice Lang-Nguyen
## Last update Tue Jan 31 17:31:59 2017 Sadisadou
##

DEBUG	=	yes

NAME	=	navy

CC	= 	gcc

RM	= 	rm -f

SRCS	=	main.c\
		game.c\
		./src/check_map.c\
		./src/errmsg.c

LIB	=	-L./lib -lmy -L./lib/my -lmy1

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
	@make -s -C lib/ all
	@make -s -C lib/my all
	@$(CC) $^ -o $@ $(LIB)
	@echo "\033[32;1mCompilation Done.\033[0m"

clean:
	@make -s -C lib/ clean
	@make -s -C lib/my clean
	@$(RM) $(OBJS)
	@echo "\033[31;1mThe Object file are delete.\033[0m"

fclean: clean
	@make -s -C lib/ fclean
	@make -s -C lib/my fclean
	@$(RM) $(NAME)
	@echo "\033[31;1m$(NAME) is delete.\033[0m"

re: fclean all

.PHONY: all clean fclean re
