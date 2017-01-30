/*
** my_strstr.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 20:10:11 2017 Brice Lang-Nguyen
** Last update Sun Jan 29 01:37:23 2017 Brice Lang-Nguyen
*/

#include "lib.h"

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  int	begin;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == to_find[0])
	{
	  begin = i;
	  while (to_find[j] == str[i])
	    {
	      if (to_find[j + 1] == '\0')
		return (&str[begin]);
	      i++;
	      j++;
	    }
	}
      j = 0;
      i++;
    }
  return (0);
}
