/*
** game.c for game in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 14:46:52 2017 Sadisadou
** Last update Fri Feb  3 19:45:44 2017 Sadisadou
*/

#include <signal.h>
#include "navy.h"

int		enemy_pid(int pid, int state)
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
    enemy_pid(info->si_pid, 0);
  if (context != NULL)
    return ;
  return ;
}

int	the_game(int i)
{
  int	state;

  while (1)
  {
    aff1();
    state = 1;
    if (i == 0)
      {
	attacker1(state);
	i = 0;
      }
    else
      {
	attacker2(state);
	i = 1;
      }
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
  my_printf("waiting for enemy connexion...\n");
  sigaction(SIGUSR1, &action, NULL);
  pause();
  kill(enemy_pid(0, 1), SIGUSR1);
  my_printf("enemy connected\n\n");
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
