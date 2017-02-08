/*
** load_map.c for navy in /home/brice/Documents/PSU/PSU_2016_navy
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Sat Feb  4 17:28:09 2017 Brice Lang-Nguyen
** Last update Wed Feb  8 17:04:06 2017 Brice Lang-Nguyen
*/

#include <stdlib.h>
#include "navy.h"

void	add_vert(char col, char line, char line2, char **map)
{
  int	i;

  i = 0;
  while (line + i <= line2)
    i++;
  while (line <= line2)
    {
      map[line - '0' - 1][(col - 'A') * 2] = i + '0';
      line++;
    }
}

void	add_hori(char col, char col2, char line, char **map)
{
  int	i;

  i = 0;
  while (col + i <= col2)
    i++;
  while (col <= col2)
    {
      map[line - '0' - 1][(col - 'A') * 2] = i + '0';
      col++;
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
	add_vert(buff[i+2], buff[i+3], buff[i+6], map);
      else
      	add_hori(buff[i+2], buff[i+5], buff[i+3], map);
      i += 8;
    }
  return (map);
}
