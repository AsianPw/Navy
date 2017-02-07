/*
** touch_miss.c for touch_miss in /home/sadisadou/PSU/PSU_2016_navy/src
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Thu Feb  2 13:25:37 2017 Sadisadou
** Last update Tue Feb  7 19:13:15 2017 Sadisadou
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
	  //usleep(140000);
	  send_coord(s);
	  my_printf("\n\nwaiting for enemy's attack...\n");
	  pause();
	  kill(enemy_pid(0, 1), SIGUSR1);
	  state = 0;
	}
      free(s);
    }
}

void	ignore(int sig, siginfo_t *info, void *context)
{
  if (sig == SIGUSR1 || sig == SIGUSR2)
    return ;
  if (context != NULL)// || info == NULL)
    return ;
  return ;
}


void	attacker2(int state)
{
  struct sigaction	action;
  char *s;

  action.sa_sigaction = &ignore;
  action.sa_flags = SA_SIGINFO;
  my_printf("waiting for enemy's attack...\n");
  sigaction(SIGUSR1, &action, NULL);
  sigaction(SIGUSR2, &action, NULL);
  pause();
  receive_coord();
  kill(enemy_pid(0, 1), SIGUSR1);
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
