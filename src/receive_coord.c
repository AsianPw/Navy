/*
** receive_coord.c for navy in /home/brice/Documents/PSU/PSU_2016_navy/src
**
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
**
** Started on  Sat Feb  4 16:09:54 2017 Brice Lang-Nguyen
** Last update Wed Feb  8 19:42:10 2017 Brice Lang-Nguyen
*/


#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "navy.h"

char		*increm(char c, int stat)
{
  static char	tab[20];
  static int	i = 0;
  int		j;

  tab[i] = c;
  i++;
  if (stat == 1)
    {
      j = 0;
      while (j < 20)
	tab[j++] = '\0';
      i = 0;
    }
  if (stat == 2)
    tab[i] = '\0';
  return (tab);
}


void	handler(int signal, siginfo_t *info, void *context)
{
  if (signal == SIGUSR1)
    increm('0', 0);
  else if (signal == SIGUSR2)
    increm('1', 0);
  else if (info->si_pid != enemy_pid(0, 1) || context != NULL)
    return ;
}

int	binchar_to_int(char *str)
{
  int	i;
  int	dec;

  i = 0;
  dec = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '1')
	dec = dec * 2 + 1;
      else if (str[i] == '0')
	dec = dec * 2;
      i++;
    }
  dec = dec + 1;
  return (dec);
}


int	receive_coord(char **map)
{
  struct sigaction	action;
  int			i;
  int			res;

  action.sa_sigaction = &handler;
  action.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &action, NULL);
  sigaction(SIGUSR2, &action, NULL);
  res = 0;
  i = 0;
  increm(0, 1);
  kill(enemy_pid(0, 1), SIGUSR1);
  while (i < 7)
    {
      pause();
      kill(enemy_pid(0, 1), SIGUSR1);
      i++;
    }
  res = binchar_to_int(increm(0, 2));
  map_pos(map, res);
  return (res);
}
