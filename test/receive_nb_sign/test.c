/*
** test.c for test in /home/brice/Documents/PSU/PSU_2016_navy_bootstrap/task03
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb  2 15:33:51 2017 Brice Lang-Nguyen
** Last update Fri Feb  3 17:05:19 2017 Brice Lang-Nguyen
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

char		*increm(char c, int stat)
{
  static char	tab[20];
  static int	i = 0;
  int		j;

  tab[i] = c;
  i++;
  printf("%s\n", tab);
  if (stat == 1)
    {
      j = 0;
      while (j < 20)
	tab[j++] = '\0';
      i = 0;
    }
  return (tab);
}

int	enemy_pid(int pid, int state)
{
  static int	my_pid;

  if (state == 1)
    return (my_pid);
  else
    my_pid = pid;
  return (my_pid);
}


void	handler(int signal, siginfo_t *info, void *context)
{
  if (signal == SIGUSR1)
    increm('0', 0);
  else if (signal == SIGUSR2)
    increm('1', 0);
}


int			main3()
{
  struct sigaction	action;
  int	i;

  action.sa_sigaction = &handler;
  sigaction(SIGUSR1, &action, NULL);
  sigaction(SIGUSR2, &action, NULL);
  i = 0;
  while (i < 19)
    {
      pause();
      kill(enemy_pid(0, 1), SIGUSR1);
      i++;
    }
  printf("%s", increm(0, 1));
  return (EXIT_SUCCESS);
}

void	handleSignal(int sig, siginfo_t *info, void *context)
{
  if (sig == SIGUSR1)
    enemy_pid(info->si_pid, 0);
}


int	main()
{
  struct sigaction	action;

  action.sa_sigaction = &handleSignal;
  action.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &action, NULL);
  pause();
  kill(enemy_pid(0, 1), SIGUSR1);
  main3();
  return (0);
}
