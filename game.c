/*
** game.c for game in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 14:46:52 2017 Sadisadou
** Last update Fri Feb  3 00:24:51 2017 Sadisadou
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

int	is_valid(char *entry)
{
  if (my_strlen(entry) != 2)
    return (false);
  else if (char_is_num(entry[0]))
    {
      if (!char_is_char(entry[1]))
	return (false);
      if (!is_low_alpha(entry[1]))
	return (false);
    }
  else if((char_is_char(entry[0])) || (is_low_alpha(entry[0])))
    {
      if (!char_is_num(entry[1]))
	return (false);
    }
  else
    return (false);
  return (true);
}

int	the_game(int i)
{
  char* s;
  int	state;

  while (1)
  {
    aff1();
    state = 1;
    if (i == 0)
      {
	while (state)
	  {
	    my_printf("\n\nattack:  ");
	    s = get_next_line(0);
	    if (!is_valid(s))
	      my_printf("wrong position\n");
	    else
	      {
		my_printf("%s:  \n\n", s);
		kill(enemy_pid(0, 1), SIGUSR1);
		pause();
		state = 0;
	      }
	  }
	i = 1;
      }
    else
      {
	my_printf("\n\nwaiting for enemy's attack...\n");
	pause();
	kill(enemy_pid(0, 1), SIGUSR1);
	i = 0;
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
