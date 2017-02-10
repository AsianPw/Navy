##
## Makefile for Makefile in /home/Sadisadou/PSU/PSU_2016_my_printf
##
## Made by Bastien Guillaumat
## Login   <Sadisadou@epitech.net>
##
## Started on  Sat Nov 12 18:57:01 2016 Bastien Guillaumat
## Last update Fri Feb 10 16:06:02 2017 Sadisadou
##

SRC	=	my_printf.c\
		my_putchar.c\
		my_puthexa_low.c\
		my_puthexa_up.c\
		my_putnbr.c\
		my_put_oct.c\
		my_put_point.c\
		my_put_bin.c\
		my_strerror.c\
		error.c\
		my_putnbr_u.c\
		my_putstr_s.c\
		my_putstr.c\
		flags1.c\
		flags2.c\
		flags3.c\
		free.c\
		my_str_to_wordtab.c\
		get_next_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy1.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
