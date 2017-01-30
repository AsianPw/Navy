/*
** my_strcpy.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 19:32:20 2017 Brice Lang-Nguyen
** Last update Sun Jan 29 01:48:16 2017 Brice Lang-Nguyen
*/

#include "lib.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (my_strlen(dest) < my_strlen(src))
    {
      my_putstr(ERROR_CPY);
      return (0);
    }
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
