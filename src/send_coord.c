/*
** send_coord.c for navy in /home/brice/Documents/PSU/PSU_2016_navy/src
**
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
**
** Started on  Sat Feb  4 15:52:48 2017 Brice Lang-Nguyen
** Last update Fri Feb 10 18:22:32 2017 Sadisadou
*/

#include <signal.h>
#include "navy.h"

char*	char_to_int(char *s, char *str)
{
  int	i;
  int	j;
  int	n;

  i = 0;
  n = 0;
  while (str[i] != '\0')
    {
      j = 0;
      if (char_is_char(str[i]))
	{
	  while (j++ <= (str[i] - 65))
	    s[n++] = '0';
	}
      else if (char_is_num(str[i]))
	{
	  while (j++ <= (str[i] - 49))
	    s[n++] = '1';
	}
      i++;
    }
  s[n] = '\0';
  return (s);
}

/* char	*int_to_bin(int nb, char *str) */
/* { */
/*   int	rem; */
/*   int	bin; */
/*   int	i; */
/*   int	j; */

/*   bin = 0; */
/*   i = 1; */
/*   j = 0; */
/*   while (nb != 0) */
/*     { */
/*       rem = nb % 2; */
/*       nb /= 2; */
/*       bin += (rem * i); */
/*       str[j++] = rem + '0'; */
/*       i *= 10; */
/*     } */
/*   return (str); */
/* } */


/* char	*bin_crypt(int nb) */
/* { */
/*   char	*str; */

/*   if ((str = malloc(sizeof(char) * 10)) == NULL) */
/*     return (NULL); */
/*   // int_to_bin(nb, str); */
/*   str = my_revstr(str); */
/*   return (str); */
/* } */

int	send_coord(char *coord)
{
  char	*str;
  int	i;

  if ((str = malloc(sizeof(char) * 19)) == NULL)
    return (84);
  str = char_to_int(str, coord);
  printf("%s\n", str);
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
