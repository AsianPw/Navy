/*
** my_putstr.c for my_putstr in /home/Sadisadou/CPool_Day04
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Thu Oct  6 17:56:14 2016 Bastien Guillaumat
** Last update Tue Nov 15 23:52:27 2016 Bastien Guillaumat
*/

#include "my_printf.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
