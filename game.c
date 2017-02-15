/*
** game.c for game in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 14:46:52 2017 Sadisadou
** Last update Wed Feb 15 15:21:58 2017 Sadisadou
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

int	the_game(int i, char **map, char **enemy_map)
{
  int	state;

  while (1)
    {
      aff1(map, enemy_map);
      state = 1;
      if (i == 0)
	{
	  if (attacker1(state, map, enemy_map) == 2)
	    return (84);
	  i = 0;
	}
      else
	{
	  if (attacker2(state, map, enemy_map) == 2)
	    return (84);
	  i = 1;
	}
    }
  my_free(map);
  my_free(enemy_map);
  return (0);
}

int	game1(char *buff)
{
  struct sigaction	action;
  int			i;
  char			**map;
  char		        **enemy_map;

  i = 0;
  map = load_map(buff);
  enemy_map = create_map();
  my_printf("my_pid:  %d\n", getpid());
  sigemptyset(&action.sa_mask);
  action.sa_sigaction = &handleSignal;
  action.sa_flags = SA_SIGINFO;
  my_printf("waiting for enemy connexion...\n");
  sigaction(SIGUSR1, &action, NULL);
  pause();
  kill(enemy_pid(0, 1), SIGUSR1);
  my_printf("enemy connected\n\n\n");
  if (the_game(i, map, enemy_map) == 1)
    return (1);
  return (0);
}

int	game2(char* buff, int pid1)
{
  struct sigaction	action;
  int			i;
  char			**map;
  char			**enemy_map;

  i = 1;
  enemy_map = create_map();
  map = load_map(buff);
  my_printf("my_pid:  %d\n", getpid());
  sigemptyset(&action.sa_mask);
  action.sa_sigaction = &handleSignal;
  action.sa_flags = SA_SIGINFO;
  kill(pid1, SIGUSR1);
  sigaction(SIGUSR1, &action, NULL);
  pause();
  my_printf("successfully connected\n\n\n");
  if (the_game(i, map, enemy_map) == 1)
    return (1);
  return (0);
}
