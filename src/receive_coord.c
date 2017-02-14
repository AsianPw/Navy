/*
** receive_coord.c for navy in /home/brice/Documents/PSU/PSU_2016_navy/src
**
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
**
** Started on  Sat Feb  4 16:09:54 2017 Brice Lang-Nguyen
** Last update Tue Feb 14 14:21:51 2017 Sadisadou
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

int	binchar_to_int2(char *str, int i)
{
  int		dec;

  dec = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '1')
	dec = dec * 2 + 1;
      else if (str[i] == '0')
	dec = dec * 2;
      i++;
    }
  return (dec);
}

t_coord		*binchar_to_int(char *str)
{
  int		i;
  int		dec;
  t_coord	*coord;

  coord = malloc(sizeof(*coord));
  i = 0;
  dec = 0;
  while (i < 7)
    {
      if (str[i] == '1')
	dec = dec * 2 + 1;
      else if (str[i] == '0')
	dec = dec * 2;
      i++;
    }
  coord->y = dec;
  coord->x = binchar_to_int2(str, i);
  return (coord);
}


t_coord		*receive_coord()
{
  struct sigaction	action;
  t_coord		*coord;
  int			i;

  action.sa_sigaction = &handler;
  action.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &action, NULL);
  sigaction(SIGUSR2, &action, NULL);
  i = 0;
  increm(0, 1);
  usleep(250);
  kill(enemy_pid(0, 1), SIGUSR1);
  while (i < 13)
    {
      pause();
      kill(enemy_pid(0, 1), SIGUSR1);
      i++;
    }
  coord = binchar_to_int(increm(0, 2));
  return (coord);
}
