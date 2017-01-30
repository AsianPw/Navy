/*
** strcmp.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 20:15:17 2017 Brice Lang-Nguyen
** Last update Sun Jan 29 01:35:32 2017 Brice Lang-Nguyen
*/

#include "lib.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    i++;
  return (s1[i] - s2[i]);
}
