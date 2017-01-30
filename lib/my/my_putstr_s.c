/*
** my_putstr_S.c for my_putstr_S in /home/Sadisadou/PSU/PSU_2016_my_printf
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Mon Nov 14 10:18:30 2016 Bastien Guillaumat
** Last update Sat Dec  3 17:28:34 2016 Bastien Guillaumat
*/

#include "my_printf.h"

void	my_putstr_s(char *str)
{
  int	i;
  int	x;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_putchar('\\');
	  x = my_put_oct(str[i]);
	  if (x < 10)
	    my_putstr("00");
	  else if (x < 100)
	    my_putchar(48);
	  my_putnbr(x);
	}
      else
	my_putchar(str[i]);
      i++;
    }
}
