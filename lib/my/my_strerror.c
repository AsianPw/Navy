/*
** my_strerror.c for my_strerror in /home/Sadisadou/CPool_infinadd
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Fri Oct 28 19:10:09 2016 Bastien Guillaumat
** Last update Tue Nov 22 19:23:43 2016 Bastien Guillaumat
*/

#include "my_printf.h"

void	my_strerror(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_error(str[i]);
      i = i + 1;
    }
}
