/*
** core.c for core in /home/sadisadou/PSU/PSU_2016_navy/src
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Thu Feb  2 14:40:53 2017 Sadisadou
** Last update Fri Feb 10 15:14:54 2017 Sadisadou
*/

#include "navy.h"

int	is_valid(char *entry)
{
  if (my_strlen(entry) != 2)
    return (false);
  else if (char_is_num(entry[0]))
    {
      if (!char_is_char(entry[1]) && !is_low_alpha(entry[1]))
	return (false);
    }
  else if ((char_is_char(entry[0])) || (is_low_alpha(entry[0])))
    {
      if (!char_is_num(entry[1]))
	return (false);
    }
  else
    return (false);
  return (true);
}

char	**create_map()
{
  char	**map;
  int	i;
  int	j;

  i = 0;
  map = malloc(sizeof(char*) * 9);
  while (i < 8)
    {
      j = 0;
      map[i] = malloc(sizeof(char) * 17);
      while (j < 16)
	{
	  if ((j % 2) == 0)
	    map[i][j] = '.';
	  else
	    map[i][j] = ' ';
	  j++;
	}
      map[i][j] = '\0';
      i++;
    }
  map[i] = '\0';
  return (map);
}

void	map(char **map)
{
  int   i;

  i = 0;
  my_printf(" |A B C D E F G H\n-+---------------\n");
  while (i < 8)
    {
      my_printf("%d|%s\n", i+1, map[i]);
      i++;
    }
  my_printf("\n\n");
}

void	enemy_map(char **map)
{
  int   i;

  i = 0;
  my_printf(" |A B C D E F G H\n-+---------------\n");
  while (i < 8)
    {
      my_printf("%d|%s\n", i+1, map[i]);
      i++;
    }
  my_printf("\n\n");
}


void	aff1(char **map_l, char** map_e)
{
  my_printf("my positions:\n");
  map(map_l);
  my_printf("enemy's positions:\n");
  enemy_map(map_e);
}
