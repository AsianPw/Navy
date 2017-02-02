/*
** game.c for game in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 14:46:52 2017 Sadisadou
** Last update Thu Feb  2 15:41:13 2017 Sadisadou
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

int	the_game()
{
  char* s;

  //while (1)
  //{
  aff1();
      /*while (s = get_next_line(0))
	{
	  if (s)
	    my_printf("wrong position\n");
	  else
	    my_printf("%s: %s", s, s);
	    }*/
      //}
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
  the_game();
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
  the_game();
}
