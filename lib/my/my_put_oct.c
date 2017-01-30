/*
** my_put_oct.c for my_put_oct in /home/Sadisadou/PSU/PSU_2016_my_printf
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Fri Nov 11 15:56:03 2016 Bastien Guillaumat
** Last update Tue Nov 15 23:49:56 2016 Bastien Guillaumat
*/

#include "my_printf.h"
int	my_put_oct(int nb)
{
  int	nbr;
  int	result;

  result = (nb % 8);
  nbr = (nb - result) / 8;
  if (nbr)
    my_put_oct(nbr);
  return (result);
}
