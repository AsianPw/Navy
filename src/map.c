/*
** map.c for map in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Fri Feb  3 19:12:44 2017 Sadisadou
** Last update Thu Feb  9 16:14:59 2017 Sadisadou
*/

#include "navy.h"

char**	map_pos(char** map, int	attack)
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
	      if (map[y][x] > '1' && map[y][x] < '6')
		kill(enemy_pid(0, 1), SIGUSR1);
	      else
		kill(enemy_pid(0, 1), SIGUSR2);
	      return (0);
	    }
	  x1++;
	}
      y1++;
    }
}
