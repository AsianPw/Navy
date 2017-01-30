/*
** my_strlen.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 18:58:17 2017 Brice Lang-Nguyen
** Last update Sun Jan 29 01:36:36 2017 Brice Lang-Nguyen
*/

#include "lib.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
