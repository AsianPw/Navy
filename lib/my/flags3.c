/*
** flags3.c for flags3 in /home/Sadisadou/PSU/PSU_2016_my_printf
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Mon Nov 21 10:49:18 2016 Bastien Guillaumat
** Last update Thu Jan 19 19:15:01 2017 Sadisadou
*/

#include "my_printf.h"

void	aff_point(va_list arg)
{
  my_put_point(va_arg(arg, unsigned int));
}

void	aff_err(va_list arg)
{
  my_strerror(va_arg(arg, char*));
}
