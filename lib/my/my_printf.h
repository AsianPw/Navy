/*
** my_printf.h for my_printf in /home/Sadisadou/PSU/PSU_2016_my_printf
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Tue Nov 15 23:30:29 2016 Bastien Guillaumat
** Last update Thu Feb  2 21:17:39 2017 Sadisadou
*/

#include <stdarg.h>
#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_
#include "get_next_line.h"
#define FLAGS 13

typedef void	(*fct)(va_list arg);

typedef struct s_flags {
  char	fonction_name;
  fct	fonction;
}	t_flags;

void	aff_perc(va_list arg);
void	aff_str(va_list arg);
void	aff_Str(va_list arg);
void	aff_nbr(va_list arg);
void	aff_uns(va_list arg);
void	aff_hex(va_list arg);
void	aff_char(va_list arg);
void	aff_heX(va_list arg);
void	aff_oct(va_list arg);
void	aff_bin(va_list arg);
void	aff_point(va_list arg);
void	aff_err(va_list arg);
void	my_putchar(char);
void	my_error(char);
void	my_putnbr(int);
void	my_putnbr_u(int);
void	my_strerror(char*);
void	my_putstr(char*);
int	my_puthexa_low(unsigned int);
int	my_puthexa_up(unsigned int);
int	my_put_oct(int);
void	my_putstr_s(char*);
int	my_put_bin(int);
int	my_put_point(int);
int	my_printf(const char*, ...);


#endif /*MY_PRINTF_H_*/
