/*
** send_coord.c for navy in /home/brice/Documents/PSU/PSU_2016_navy/src
**
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
**
** Started on  Sat Feb  4 15:52:48 2017 Brice Lang-Nguyen
** Last update Sat Feb 11 22:38:46 2017 Sadisadou
*/

#include <signal.h>
#include "navy.h"


/* int	char_to_int(char *str) */
/* { */
/*   int	i; */
/*   int	res; */

/*   i = 0; */
/*   res = 0; */
/*   while (str[i] != '\0') */
/*     { */
/*       res += str[i]; */
/*       i++; */
/*     } */
/*   res -= 1; */
/*   return (res); */
/* } */

char*	int_to_bin2(int nb, char* str)
{
  int	rem;
  int	bin;
  int	i;
  int	x;

  bin = 0;
  i = 1;
  x = 0;
  while (nb != 0)
    {
      rem = nb % 2;
      nb /= 2;
      bin += (rem * i);
      str[x] = rem + '0';
      x++;
      i *= 10;
    }
  return (str);
}

char	*int_to_bin(int nb, char *str, int nb2)
{
  char*	str2;
  int	rem;
  int	bin;
  int	i;
  int	j;

  if ((str2 = malloc(sizeof(char) * 6)) == NULL)
    return (NULL);
  bin = 0;
  i = 1;
  j = 0;
  while (nb != 0)
    {
      rem = nb % 2;
      nb /= 2;
      bin += (rem * i);
      str[j] = rem + '0';
      j++;
      i *= 10;
    }
  str2 = int_to_bin2(nb2, str2);
  str = my_strcat(str, str2);
  return (str);
}


char	*bin_crypt(char *s)
{
  char	*str;
  int	nb;
  int	nb2;

  if ((char_is_char(s[0]) || is_low_alpha(s[0])) && char_is_num(s[1]))
    {
      nb = s[1];
      nb2 = s[0];
    }
  else
    {
      nb = s[0];
      nb2 = s[1];
    }
  if ((str = malloc(sizeof(char) * 14)) == NULL)
    return (NULL);
  str = int_to_bin(nb, str, nb2);
  str = my_revstr(str);
  return (str);
}

int	send_coord(char *coord)
{
  char	*str;
  int	i;

  str = bin_crypt(coord);
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
