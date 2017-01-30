/*
** my_str_isalpha.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 20:25:41 2017 Brice Lang-Nguyen
** Last update Sun Jan 29 16:14:31 2017 Brice Lang-Nguyen
*/

#include "lib.h"

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (((str[i] > 64) && (str[i] < 91)) || ((str[i] > 96) && (str[i] < 123)))
	i++;
      else
	return (false);
    }
  return (true);
}
