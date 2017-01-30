/*
** my_puthexa_up.c for my_puthexa_up in /home/Sadisadou/PSU/PSU_2016_my_printf
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Sat Nov 12 16:07:09 2016 Bastien Guillaumat
** Last update Tue Nov 15 23:49:41 2016 Bastien Guillaumat
*/

#include "my_printf.h"
#define HEXA_UP "0123456789ABCDEF"

int	my_puthexa_up(unsigned int n)
{
  unsigned int	nbr;
  unsigned int	result;

  result = n % 16;
  nbr = (n - result) / 16;
  if (nbr)
    my_puthexa_up(nbr);
  my_putchar(HEXA_UP[result]);
  return (0);
}
