/*
** flags1.c for flags1 in /home/Sadisadou/PSU/PSU_2016_my_printf
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Mon Nov 21 10:32:39 2016 Bastien Guillaumat
** Last update Sat Dec  3 17:27:49 2016 Bastien Guillaumat
*/

#include "my_printf.h"

void	aff_perc(va_list arg)
{
  my_putchar('%');
}

void	aff_str(va_list arg)
{
  my_putstr(va_arg(arg, char *));
}

void	aff_Str(va_list arg)
{
  my_putstr_s(va_arg(arg, char *));
}

void	aff_char(va_list arg)
{
  my_putchar((char)va_arg(arg, int));
}

void	aff_nbr(va_list arg)
{
  my_putnbr(va_arg(arg, int));
}
