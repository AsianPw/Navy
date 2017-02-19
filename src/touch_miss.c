/*
** touch_miss.c for touch_miss in /home/sadisadou/PSU/PSU_2016_navy/src
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Thu Feb  2 13:25:37 2017 Sadisadou
** Last update Sun Feb 19 21:30:36 2017 Sadisadou
*/

#include <signal.h>
#include "navy.h"

int	attacker1(int state, char** map, char **enemy_map)
{
  char		*s;
  t_coord	*attack;

  while (state)
    {
      my_printf("attack:  ");
      if ((s = get_next_line(0)) == NULL)
	return (2);
      if (!is_valid(s))
	my_printf("wrong position\n");
      else
	{
	  my_printf("%s:  ", s);
	  kill(enemy_pid(0, 1), SIGUSR1);
	  send_coord(s);
	  the_enemy(enemy_map, s);
	  my_printf("waiting for enemy's attack...\n");
	  pause();
	  attack = receive_coord();
	  map_pos(map, attack);
	  kill(enemy_pid(0, 1), SIGUSR1);
	  state = 0;
	}
      free(s);
    }
  return (0);
}

int	attacker2(int state, char **map, char** enemy_map)
{
  char		*s;
  t_coord	*attack;

  my_printf("waiting for enemy's attack...\n");
  pause();
  attack = receive_coord();
  map_pos(map, attack);
  while (state)
    {
      my_printf("attack:  ");
      if ((s = get_next_line(0)) == NULL)
	return (2);
      if (!is_valid(s))
	my_printf("wrong positions\n");
      else
	{
	  my_printf("%s:  ", s);
	  kill(enemy_pid(0, 1), SIGUSR1);
	  send_coord(s);
	  the_enemy(enemy_map, s);
	  state = 0;
	}
      free(s);
    }
  return (0);
}
