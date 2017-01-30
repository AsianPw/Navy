/*
** my_put_nbr.c for my_put_nbr in /home/Sadisadou/CPool_Day03
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Thu Oct  6 18:32:36 2016 Bastien Guillaumat
** Last update Tue Nov 15 23:45:53 2016 Bastien Guillaumat
*/

#include "my_printf.h"

void	my_putnbr(int nb)
{
  int	mod;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  mod = (nb % 10);
	  nb = (nb - mod) / 10;
	  my_putnbr(nb);
	  my_putchar(48 + mod);
	}
      else
	my_putchar(48 + nb % 10);
    }
}
