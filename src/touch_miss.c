/*
** touch_miss.c for touch_miss in /home/sadisadou/PSU/PSU_2016_navy/src
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Thu Feb  2 13:25:37 2017 Sadisadou
** Last update Fri Feb  3 15:44:40 2017 Sadisadou
*/

#include <signal.h>
#include "navy.h"

void	attacker1(int state)
{
  char *s;

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
	  my_printf("\n\nwaiting for enemy's attack...\n");
	  pause();
	  kill(enemy_pid(0, 1), SIGUSR1);
	  state = 0;
	}
      free(s);
    }
}

void	attacker2(int state)
{
  char *s;

  my_printf("waiting for enemy's attack...\n");
  pause();
  while (state)
    {
      my_printf("attack:  ",);
      s = get_next_line(0);
      if (!is_valid(s))
	my_printf("wrong positions\n");
      else
	{
	  my_printf("%s:  \n\n", s);
	  kill(enemy_pid(0, 1), SIGUSR1);
	  pause();
	  state = 0;
	}
      free(s);
    }
}
