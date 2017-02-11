/*
** map.c for map in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Fri Feb  3 19:12:44 2017 Sadisadou
** Last update Sat Feb 11 12:22:25 2017 Brice Lang-Nguyen
*/

#include "navy.h"

void	check(char **map, int x, int y)
{
  if (map[y - 49][(x - 65) * 2] > '1' && map[y - 49][(x - 65) * 2] < '6')
    {
      map[y - 49][(x - 65) * 2] = 'x';
      my_printf("%c%c: hit\n\n", x, y);
    }
  else if (map[y - 49][(x - 65) * 2] == 'x')
    {
      map[y - 49][(x - 65) * 2] = 'x';
      my_printf("%c%c: missed\n\n", x, y);
    }
  else
    {
      map[y - 49][(x - 65) * 2] = 'o';
      my_printf("%c%c: missed\n\n", x, y);
    }
}

int	map_pos(char** map, int	attack)
{
  int	x;
  int	y;
  int	x1;
  int	y1;

  y1 = 0;
  while (y1 < 7)
    {
      y = '1' + y1;
      x1 = 0;
      while (x1 < 8)
	{
	  x = 'A' + x1;
	  if (attack == (x + y))
	    {
	      check(map, x, y);
	      return (0);
	    }
	  x1++;
	}
      y1++;
    }
}
