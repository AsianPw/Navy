/*
** my_strcat.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
**
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
**
** Started on  Fri Jan 27 20:35:58 2017 Brice Lang-Nguyen
** Last update Sat Feb 11 20:29:19 2017 Sadisadou
*/

#include "lib.h"

char	*my_strcat(char *dest, char *src)
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
  dest[i] = '\0';
  return (dest);
}
