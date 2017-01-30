/*
** count_char.c<lib> for navy in /home/brice/Documents/PSU/PSU_2016_navy
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Mon Jan 30 14:02:53 2017 Brice Lang-Nguyen
** Last update Mon Jan 30 14:03:15 2017 Brice Lang-Nguyen
*/

#include "lib.h"

int	count_char(char *str, char delim)
{
  int	i;

  i = 0;
  while (str[i] != delim && str[i] != '\0' && str[i] != '\n')
    i++;
  i++;
  return (i);
}
