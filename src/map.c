/*
** map.c for map in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Fri Feb  3 19:12:44 2017 Sadisadou
** Last update Wed Feb  8 20:20:57 2017 Brice Lang-Nguyen
*/

#include "navy.h"

void	map_pos(char** map, int	attack)
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
	  if (attack == x + y)
	    my_printf("touch\n");
	  x1++;
	}
      y1++;
    }
  my_printf("missed\n");
}
