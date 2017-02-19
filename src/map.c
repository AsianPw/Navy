/*
** map.c for map in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Fri Feb  3 19:12:44 2017 Sadisadou
** Last update Sun Feb 19 21:52:26 2017 Sadisadou
*/

#include "navy.h"

void	handletouch(int sig, siginfo_t* info, void* context)
{
  if (sig == SIGUSR1)
    my_bool(0, 0);
  else if (sig == SIGUSR2)
    my_bool(1, 0);
  else if (context != NULL && info == NULL)
    return ;
}


int	the_enemy(char** map, char* coord)
{
  struct sigaction	action;
  int			i;
  static int x = 0;

  action.sa_sigaction = &handletouch;
  action.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &action, NULL);
  sigaction(SIGUSR2, &action, NULL);
  kill(enemy_pid(0, 1), SIGUSR1);
  pause();
  if ((i = my_bool(0, 1)) == 0)
    {
      if ((map[coord[1] - 49][(coord[0] - 65) * 2]) == '.')
	map[coord[1] - 49][(coord[0] - 65) * 2] = 'o';
      my_printf("missed\n\n");
    }
  else if (i == 1)
    {
      map[coord[1] - 49][(coord[0] - 65) * 2] = 'x';
      my_printf("hit\n\n");
      x++;
    }
  return (x);
}

void	check(char **map, int x, int y)
{
  pause();
  if (map[y - 49][(x - 65) * 2] > '1' && map[y - 49][(x - 65) * 2] < '6')
    {
      map[y - 49][(x - 65) * 2] = 'x';
      my_printf("%c%c: hit\n\n", x, y);
      kill(enemy_pid(0, 1), SIGUSR2);
    }
  else if (map[y - 49][(x - 65) * 2] == 'x')
    {
      map[y - 49][(x - 65) * 2] = 'x';
      my_printf("%c%c: missed\n\n", x, y);
      kill(enemy_pid(0, 1), SIGUSR1);
    }
  else
    {
      map[y - 49][(x - 65) * 2] = 'o';
      my_printf("%c%c: missed\n\n", x, y);
      kill(enemy_pid(0, 1), SIGUSR1);
    }
  usleep(250);
}

int	the_map(char **map)
{
  int	x;
  int	y;

  x = 0;
  while (x < 8)
    {
      y = 0;
      while (y < 16)
	{
	  if ((y % 2) == 0)
	    if (map[x][y] > 49 && map[x][y] < 54)
	      return (1);
	  y++;
	}
      x++;
    }
  return (0);
}

int	map_pos(char** map, t_coord *attack)
{
  int	x;
  int	y;
  int	x1;
  int	y1;

  y1 = 0;
  while (y1 < 8)
    {
      y = '1' + y1;
      x1 = 0;
      while (x1 < 8)
	{
	  x = 'A' + x1;
	  if (attack->y == x && attack->x == y)
	    {
	      check(map, x, y);
	      free(attack);
	      return (0);
	    }
	  x1++;
	}
      y1++;
    }
  return (0);
}
