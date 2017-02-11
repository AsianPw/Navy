/*
** touch_miss.c for touch_miss in /home/sadisadou/PSU/PSU_2016_navy/src
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Thu Feb  2 13:25:37 2017 Sadisadou
** Last update Sat Feb 11 20:12:35 2017 Sadisadou
*/

#include <signal.h>
#include "navy.h"


void	attacker1(int state, char** map, char **enemy_map)
{
  char  *s;
  int	attack;

  while (state)
    {
      my_printf("attack:  ");
      s = get_next_line(0);
      if (!is_valid(s))
	my_printf("wrong position\n");
      else
	{
	  my_printf("%s:  ", s);
	  kill(enemy_pid(0, 1), SIGUSR1);
	  send_coord(s);
	  /* pause(); */
	  my_printf("\n\nwaiting for enemy's attack...\n");
	  pause();
	  attack = receive_coord();
	  //map_pos(map, attack);
	  kill(enemy_pid(0, 1), SIGUSR1);
	  state = 0;
	}
      free(s);
    }
}

void	attacker2(int state, char **map, char** enemy_map)
{
  char  *s;
  int	attack;

  my_printf("waiting for enemy's attack...\n");
  pause();
  attack = receive_coord();
  //map_pos(map, attack);
  while (state)
    {
      my_printf("attack:  ");
      s = get_next_line(0);
      if (!is_valid(s))
	my_printf("wrong positions\n");
      else
	{
	  my_printf("%s:  \n\n", s);
	  kill(enemy_pid(0, 1), SIGUSR1);
	  send_coord(s);
	  /* pause(); */
	  state = 0;
	}
      free(s);
    }
}
