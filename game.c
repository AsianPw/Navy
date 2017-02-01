/*
** game.c for game in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 14:46:52 2017 Sadisadou
** Last update Thu Feb  2 00:22:43 2017 Sadisadou
*/

#include <signal.h>
#include "navy.h"

int	g_pid;

void	handleSignal(int sig, siginfo_t* info, void* context)
{
  if (sig == SIGUSR1)
    g_pid = info->si_pid;
  if (context != NULL)
    return ;
}

void	the_game()
{
  char* s;

  while ()
    {
      my_printf("my positions:\n");
      my_printf("ennemy's positions:\n");
      my_printf("attack:  ");
      while (s = get_next_line(0))
	{

	}
    }
}

void	game1(char *buff)
{
  struct sigaction	action;

  my_printf("my_pid:  %d\n", getpid());
  action.sa_sigaction = &handleSignal;
  action.sa_flags = SA_SIGINFO;
  my_printf("waiting for ennemy connexion...\n");
  sigaction(SIGUSR1, &action, NULL);
  pause();
  kill(g_pid, SIGUSR1);
  my_printf("ennemy connected\n\n");
}

void	game2(char* buff, int pid1)
{
  struct sigaction	action;

  my_printf("my_pid:  %d\n", getpid());
  action.sa_sigaction = &handleSignal;
  action.sa_flags = SA_SIGINFO;
  kill(pid1, SIGUSR1);
  sigaction(SIGUSR1, &action, NULL);
  pause();
  my_printf("successfully connected\n\n");
}
