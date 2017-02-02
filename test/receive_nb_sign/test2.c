/*
** test.c for test in /home/brice/Documents/PSU/PSU_2016_navy_bootstrap/task03
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb  2 15:33:51 2017 Brice Lang-Nguyen
** Last update Thu Feb  2 16:40:18 2017 Brice Lang-Nguyen
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int		increm(int pid, int state)
{
  static int	my_pid;

  printf("in func: %i\n", pid);
  if (state == 1)
    return (my_pid);
  else
    my_pid = pid;
  return (my_pid);
}

void	handler(int signal, siginfo_t *info, void *context)
{
  if (signal == SIGUSR1)
    increm(info->si_pid, 0);
}


int			main(int argc, char **argv)
{
  struct sigaction	action;

  action.sa_sigaction = &handler;
  sigaction(SIGUSR1, &action, NULL);
  sigaction(SIGUSR2, &action, NULL);
  pause();
  printf("my_pid: %i\nSender_pid: %i\n", getpid(), increm(0, 1));
  return (EXIT_SUCCESS);
}
