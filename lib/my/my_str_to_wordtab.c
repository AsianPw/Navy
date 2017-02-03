/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/sadisadou/ShellP/PSU_2016_minishell1
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Thu Jan 19 19:24:09 2017 Sadisadou
** Last update Fri Jan 27 17:25:06 2017 Sadisadou
*/

#include <stdlib.h>
#include "include/my.h"

int	args(char* str, char a)
{
  int	i;
  int	nb;

  i = 0;
  nb = 1;
  while (str[i])
    {
      if (str[i] == a)
	nb++;
      i++;
    }
  return (nb);
}

int	wlen(char* str, int i, char a)
{
  int	nb;

  nb = 0;
  while (str[i] && str[i] != a)
    {
      nb++;
      i++;
    }
  return (nb);
}

void	myc_alloc_verif(char *s)
{
  if (s == NULL)
    exit (84);
}

void	mycc_alloc_verif(char** s)
{
  if (s == NULL)
    exit (84);
}

char**	my_str_to_wordtab(char *str, char a)
{
  char**	word;
  int		n;
  int		i;
  int		j;

  n = 0;
  j = 0;
  mycc_alloc_verif(word = malloc(sizeof(char *) * (args(str, a) + 1)));
  while (str[n] != '\0')
    {
      i = 0;
      myc_alloc_verif(word[j] = malloc(sizeof(char) * (wlen(str, n, a) + 1)));
      while (str[n] && str[n] != a)
	{
	  word[j][i] = str[n];
	  i++;
	  n++;
	}
      while (str[n] == a && str[n])
	n++;
      word[j][i] = '\0';
      j++;
    }
  word[j] = '\0';
  return (word);
}
