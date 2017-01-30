/*
** my_put_point.c for my_put_point in /home/Sadisadou/PSU/PSU_2016_my_printf
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Sat Nov 12 16:10:21 2016 Bastien Guillaumat
** Last update Wed Nov 16 23:13:16 2016 Bastien Guillaumat
*/

#include "my_printf.h"

int	my_put_point(int p)
{
  my_putstr("0x");
  my_puthexa_low(p);
  return (0);
}
