
/*
** game.c for game in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 14:46:52 2017 Sadisadou
** Last update Thu Feb  2 17:35:27 2017 Sadisadou
*/

#include <signal.h>
#include "navy.h"

int		ennemy_pid(int pid, int state)
{
  static int	my_pid;

  if (state == 1)
    return (my_pid);
  else
    my_pid = pid;
  return (my_pid);
}

void	handleSignal(int sig, siginfo_t* info, void* context)
{
  if (sig == SIGUSR1)
    ennemy_pid(info->si_pid, 0);
  if (context != NULL)
    return ;
  return ;
}

int	the_game(int i)
{
  char* s;

  while (1)
  {
    aff1();
    if (i == 0)
      {
	while (1)
	  {
	    my_printf("attack:  ");
	    s = get_next_line(0);
	    if (s)
	      my_printf("wrong position\n");
	    else
	      my_printf("%s:", s, s);
	  }
      }
    pause();
  }
}

void	game1(char *buff)
{
  struct sigaction	action;
  int			i;

  i = 0;
  my_printf("my_pid:  %d\n", getpid());
  sigemptyset(&action.sa_mask);
  action.sa_sigaction = &handleSignal;
  action.sa_flags = SA_SIGINFO;
  my_printf("waiting for ennemy connexion...\n");
  sigaction(SIGUSR1, &action, NULL);
  pause();
  kill(ennemy_pid(0, 1), SIGUSR1);
  my_printf("ennemy connected\n\n");
  the_game(i);
}

void	game2(char* buff, int pid1)
{
  struct sigaction	action;
  int			i;

  i = 1;
  my_printf("my_pid:  %d\n", getpid());
  sigemptyset(&action.sa_mask);
  action.sa_sigaction = &handleSignal;
  action.sa_flags = SA_SIGINFO;
  kill(pid1, SIGUSR1);
  sigaction(SIGUSR1, &action, NULL);
  pause();
  my_printf("successfully connected\n\n");
  the_game(i);
}
