/*
** my_putstr.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
**
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
**
** Started on  Fri Jan 27 18:56:46 2017 Brice Lang-Nguyen
** Last update Mon Jan 30 21:04:32 2017 Sadisadou
*/

#include "lib.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
