/*
** get_next_line.c for get_next_line in /home/sadisadou/C-Prog_Elem/CPE_2016_getnextline
**
** Made by Bastien Guillaumat
** Login   <sadisadou@epitech.net>
**
** Started on  Mon Jan  2 13:09:31 2017 Bastien Guillaumat
** Last update Sun Feb 19 21:39:31 2017 Sadisadou
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int	loop(char *buff)
{
  int	i;

  i = 0;
  while (buff[i] != '\0' && buff[i] != '\n')
    {
      i++;
    }
  return (i);
}

char*	get(int	i, int n, char* buff, char* final)
{
  i = loop(buff);
  final = malloc(sizeof(char) * i + 1);
  if (final == NULL)
    return (NULL);
  while (n < i)
    {
      final[n] = buff[n];
      n++;
    }
  if (buff[0] != 10 && i == 0)
    final = NULL;
  else
    final[n] = '\0';
  return (final);
}

char*	get_next_line(const int fd)
{
  static char	*buff;
  char		*final;
  int		i;
  int		ssread;
  int		n;

  n = 0;
  buff = malloc(sizeof(char) * (READ_SIZE + 1));
  if (buff == NULL)
    return (NULL);
  ssread = read(fd, buff, READ_SIZE);
  buff[ssread] = '\0';
  if (ssread != -1)
    {
      final = get(i, n, buff, final);
      free(buff);
      return (final);
    }
  else
    return (NULL);
}
