/*
** my_revstr.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 19:46:07 2017 Brice Lang-Nguyen
** Last update Sat Feb  4 16:08:23 2017 Brice Lang-Nguyen
*/

#include "lib.h"

char	*my_revstr(char *str)
{
  char	tmp;
  int	i;
  int	j;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      tmp = str[j];
      str[j] = str[i];
      str[i] = tmp;
      i++;
      j--;
    }
  return (str);
}
