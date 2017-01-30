/*
** my_getnbr.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 19:00:30 2017 Brice Lang-Nguyen
** Last update Sun Jan 29 01:47:10 2017 Brice Lang-Nguyen
*/

#include "lib.h"

int	my_getnbr(char *str)
{
  int	result;
  int	i;

  if (my_strlen(str) > 16)
    {
      my_putstr("MY_GETNBR: str is too long\n");
      return (0);
    }
  i = 0;
  result = 0;
  if (str[0] == '-' && str[1] != '\0')
    i++;
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      result += str[i] - '0';
      result *= 10;
      i++;
    }
  result /= 10;
  if (str[0] == '-')
    return (-1 * result);
  else
    return (result);
}
