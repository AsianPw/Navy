/*
** my_strcat.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 20:35:58 2017 Brice Lang-Nguyen
** Last update Sun Jan 29 01:35:15 2017 Brice Lang-Nguyen
*/

#include "lib.h"

char	*strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i++;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      j++;
      i++;
    }
  return (dest);
}
