/*
** load_map.c for navy in /home/brice/Documents/PSU/PSU_2016_navy
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Sat Feb  4 17:28:09 2017 Brice Lang-Nguyen
** Last update Wed Feb  8 13:40:55 2017 Brice Lang-Nguyen
*/

#include <stdlib.h>
#include "navy.h"

void	add_vert(char col, char line, char nb, char **map)
{
  int	i;

  i = 0;
  while (i < nb - '0')
    {
      if (col % 2 == 0)
	map[line - '0' - 1][col % 16] = nb;
      else
	map[line - '0' - 1][col % 16 + 1] = nb;
      line++;
      i++;
    }
}

void	add_hori(char col, char line, char nb, char **map)
{
  int	i;

  i = 0;
  if (col % 2 == 0)
    {
      col += 2;
      map[line - '0' - 1][col % 16] = nb;
    }
  else
    map[line - '0' - 1][col % 16 + 1] = nb;
  while (i < nb - '0')
    {
     map[line - '0' - 1][col % 16] = nb;
     col += 2;
     i++;
    }
}

char	**load_map(char *buff)
{
  char	**map;
  int	i;

  map = create_map();
  i = 0;
  while (buff[i] != '\0')
    {
      if (buff[i + 2] == buff[i + 5])
	add_vert(buff[i+2], buff[i+3], buff[i], map);
      else
	add_hori(buff[i+2], buff[i+3], buff[i], map);
      i += 8;
    }
  return (map);
}
