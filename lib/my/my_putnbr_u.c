/*
** my_putnbr_u.c for my_putnbr_u in /home/Sadisadou/PSU/PSU_2016_my_printf
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Wed Nov 16 10:15:16 2016 Bastien Guillaumat
** Last update Wed Nov 16 10:39:41 2016 Bastien Guillaumat
*/

#include "my_printf.h"

void	my_putnbr_u(int nb)
{
  int	mod;

  if (nb < 0)
    {
      nb = -nb;
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
