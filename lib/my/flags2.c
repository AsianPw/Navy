/*
** flags2.c for flags2 in /home/Sadisadou/PSU/PSU_2016_my_printf
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Mon Nov 21 10:43:35 2016 Bastien Guillaumat
** Last update Mon Nov 21 11:17:09 2016 Bastien Guillaumat
*/

#include "my_printf.h"

void	aff_uns(va_list arg)
{
  my_putnbr_u(va_arg(arg, unsigned int));
}

void	aff_hex(va_list arg)
{
  my_puthexa_low(va_arg(arg, unsigned int));
}

void	aff_heX(va_list arg)
{
  my_puthexa_up(va_arg(arg, unsigned int));
}

void	aff_oct(va_list arg)
{
  my_putnbr(my_put_oct(va_arg(arg, int)));
}

void	aff_bin(va_list arg)
{
  my_put_bin(va_arg(arg, unsigned int));
}
