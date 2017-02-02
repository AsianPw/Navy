/*
** test.c for test in /home/brice/Documents/PSU/PSU_2016_navy_bootstrap/task03
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb  2 15:33:51 2017 Brice Lang-Nguyen
** Last update Thu Feb  2 16:31:59 2017 Brice Lang-Nguyen
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

void	handler(int signal, siginfo_t *info, void *context)
{
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
  i = 0;
  while (i < 5)
    {
      sigaction(SIGUSR1, &action, NULL);
      sigaction(SIGUSR2, &action, NULL);
      pause();
      i++;
    }
  printf("%s", increm(0, 1));
  sigaction(SIGUSR1, &action, NULL);
  sigaction(SIGUSR2, &action, NULL);
  pause();
  printf("%s", increm(0, 1));
  return (EXIT_SUCCESS);
}
