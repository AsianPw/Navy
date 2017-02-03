/*
1;4205;0c** crypt.c for navy in /home/brice/Documents/PSU/PSU_2016_navy/test/binary
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb  2 22:50:44 2017 Brice Lang-Nguyen
** Last update Fri Feb  3 16:11:52 2017 Brice Lang-Nguyen
*/

#include <signal.h>
#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}


char	*my_revstr(char *str)
{
  char	tmp;
  int	i;
  int	j;

  i = 0;
  j = my_strlen(str) - 1;
  while (i <= j)
    {
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
      i++;
      j--;
    }
  return (str);
}


char	*int_to_bin(int nb, char *str)
{
  int	rem;
  int	bin;
  int	i;
  int	j;

  bin = 0;
  i = 1;
  j = 0;
  while (nb != 0)
    {
      rem = nb % 2;
      nb = nb / 2;
      bin += (rem * i);
      str[j++] = rem + '0';
      i *= 10;
    }
  return (str);
}


char	*bin_crypt(int nb)
{
  char	*str;

  if ((str = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  int_to_bin(nb, str);
  str = my_revstr(str);
  return (str);
}

void	handler_sender(int signal, siginfo_t *info, void *context)
{
  if (signal == SIGUSR1)
    return ;
}

int	main(int argc, char **argv)
{
  struct sigaction	action;
  char	*str;
  int	i;

  action.sa_sigaction = &handler_sender;
  str = bin_crypt(19);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '0')
	kill(atoi(argv[1]), SIGUSR1);
      else if (str[i] == '1')
	kill(atoi(argv[1]), SIGUSR2);
      sigaction(SIGUSR1, &action, NULL);
      pause();
      i++;
    }
  return (0);
}
