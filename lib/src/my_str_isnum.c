/*
** my_str_isnum.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 20:31:19 2017 Brice Lang-Nguyen
** Last update Sun Jan 29 01:36:22 2017 Brice Lang-Nguyen
*/

#include "lib.h"

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 47 && str[i] < 58)
	i++;
      else
	return (0);
    }
  return (1);
}
