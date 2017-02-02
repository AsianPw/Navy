/*
** core.c for core in /home/sadisadou/PSU/PSU_2016_navy/src
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Thu Feb  2 14:40:53 2017 Sadisadou
** Last update Thu Feb  2 21:12:03 2017 Sadisadou
*/

#include "navy.h"

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

void    map()
{
  int   i;
  char	**map;

  map = create_map();
  i = 0;
  my_printf(" |A B C D E F G H\n-+---------------\n");
  while (i < 8)
    {
      my_printf("%d|%s\n", i+1, map[i]);
      i++;
    }
}

void	aff1()
{
  my_printf("my positions:\n");
  map();
  my_printf("\n\nennemy's positions:\n");
  map();
}
