/*
** my_strncpy.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 19:38:39 2017 Brice Lang-Nguyen
** Last update Sun Jan 29 01:48:50 2017 Brice Lang-Nguyen
*/

#include "lib.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  if (my_strlen(dest) < n + 1)
    {
      my_putstr(ERROR_CPY);
      return (0);
    }
  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
