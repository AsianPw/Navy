/*
** test.c for test in /home/brice/Documents/PSU/PSU_2016_navy_bootstrap/task03
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb  2 15:33:51 2017 Brice Lang-Nguyen
** Last update Fri Feb  3 16:07:30 2017 Brice Lang-Nguyen
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int	g_pid_e;

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

void	handler(int signal, siginfo_t *info, void *context)
{
  g_pid_e = info->si_pid;
  if (signal == SIGUSR1)
    increm('0', 0);
  else if (signal == SIGUSR2)
    increm('1', 0);
}


int			main(int argc, char **argv)
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
      kill(g_pid_e, SIGUSR1);
      i++;
    }
  printf("%s", increm(0, 1));
  return (EXIT_SUCCESS);
}
