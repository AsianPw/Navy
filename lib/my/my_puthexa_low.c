/*
** my_puthexa_low.c for my_puthexa_low in /home/Sadisadou/PSU/PSU_2016_my_printf
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Sat Nov 12 16:01:33 2016 Bastien Guillaumat
** Last update Tue Nov 15 23:49:26 2016 Bastien Guillaumat
*/

#include "my_printf.h"
#define HEXA_LOW "0123456789abcdef"

int	my_puthexa_low(unsigned int n)
{
  unsigned int nbr;
  unsigned int result;

  result = n % 16;
  nbr = (n - result) / 16;
  if (nbr)
    my_puthexa_low(nbr);
  my_putchar(HEXA_LOW[result]);
  return (0);
}
