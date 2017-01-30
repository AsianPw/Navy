/*
** how_many_word.c<lib> for navy in /home/brice/Documents/PSU/PSU_2016_navy
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Mon Jan 30 14:03:57 2017 Brice Lang-Nguyen
** Last update Mon Jan 30 14:04:19 2017 Brice Lang-Nguyen
*/

#include "lib.h"

int	how_many_word(char *str, char delim)
{
  int	i;
  int	word;

  i = 0;
  word = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == delim && str[i + 1] != '\0')
	word++;
      i++;
    }
  return (word);
}
