/*
** send_coord.c for navy in /home/brice/Documents/PSU/PSU_2016_navy/src
**
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
**
** Started on  Sat Feb  4 15:52:48 2017 Brice Lang-Nguyen
** Last update Wed Feb  8 12:34:56 2017 Brice Lang-Nguyen
*/

#include <signal.h>
#include "navy.h"


int	char_to_int(char *str)
{
  int	i;
  int	res;
 
  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      //res += (str[i] - '0') * multi;
      //multi *= 10;
      //i++;
      res += str[i];
      i++;
    }
  res -= 1;
  return (res);
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
      nb /= 2;
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

int	send_coord(char *coord)
{
  char	*str;
  int	i;

  str = bin_crypt(char_to_int(coord));
  i = 0;
  pause();
  while (str[i] != '\0')
    {
      if (str[i] == '0')
	kill(enemy_pid(0, 1), SIGUSR1);
      else if (str[i] == '1')
	kill(enemy_pid(0, 1), SIGUSR2);
      pause();
      i++;
    }
  return (0);
}
