/*
** my_put_bin.c for my_put_bin in /home/Sadisadou/PSU/PSU_2016_my_printf
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Sat Nov 12 19:10:15 2016 Bastien Guillaumat
** Last update Tue Nov 15 23:51:00 2016 Bastien Guillaumat
*/

#include "my_printf.h"

int	my_put_bin(int n)
{
  int	nbr;
  int	result;

  result = (n % 2);
  nbr = (n - result) / 8;
  if (nbr)
    my_put_bin(nbr);
  my_putnbr(result);
  return (0);
}
