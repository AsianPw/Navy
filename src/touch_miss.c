/*
** touch_miss.c for touch_miss in /home/sadisadou/PSU/PSU_2016_navy/src
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Thu Feb  2 13:25:37 2017 Sadisadou
** Last update Sat Feb  4 17:04:43 2017 Brice Lang-Nguyen
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
	  usleep(150000);
	  send_coord(s);
	  pause();
	  my_printf("\n\nwaiting for enemy's attack...\n");
	  pause();
	  kill(enemy_pid(0, 1), SIGUSR1);
	  state = 0;
	}
      free(s);
    }
}

void	ignore(int sig)
{
  if (sig == SIGUSR1 || sig == SIGUSR2)
    return ;
  return ;
}


void	attacker2(int state)
{
  struct sigaction	action;
  char *s;

  action.sa_sigaction = &ignore;
  my_printf("waiting for enemy's attack...\n");
  sigaction(SIGUSR1, &action, NULL);
  sigaction(SIGUSR2, &action, NULL);
  pause();
  receive_coord();
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
	  pause();
	  state = 0;
	}
      free(s);
    }
}
