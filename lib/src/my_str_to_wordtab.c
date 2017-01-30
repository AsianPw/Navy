/*
** my_str_to_wordtab.c<lib> for navy in /home/brice/Documents/PSU/PSU_2016_navy
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Mon Jan 30 14:00:04 2017 Brice Lang-Nguyen
** Last update Mon Jan 30 14:00:25 2017 Brice Lang-Nguyen
*/

#include "lib.h"

char	**my_str_to_wordtab(char *str, char delim)
{
  char	**tab;
  int	i;
  int	a;
  int	b;

  a = 0;
  b = 0;
  i = 0;
  tab = malloc(sizeof(*tab) * (how_many_word(str, delim) + 1));
  while (str[i] != '\t' && str[i] != '\0')
    {
      if (str[i] == delim || str[i] == '\n')
	{
	  while (str[i] == delim)
	    i++;
	  a += 1;
	  b = 0;
	}
      tab[a] = malloc(sizeof(**tab) * (count_char(str + i, delim) + 1));
      while ((str[i] != delim) && (str[i] != '\n') && (str[i] != '\0'))
	tab[a][b++] = str[i++];
      tab[a][b] = '\0';
    }
  tab[a + 1] = 0;
  return (tab);
}
