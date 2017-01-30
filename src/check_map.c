/*
** check_map.c for navy in /home/brice/Documents/PSU/PSU_2016_navy/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Mon Jan 30 15:58:12 2017 Brice Lang-Nguyen
** Last update Mon Jan 30 20:02:32 2017 Brice Lang-Nguyen
*/

#include "navy.h"

int	char_is_num(char c)
{
  if (c > 47 && c < 58)
    return (true);
  return (false);
}


int	char_is_char(char c)
{
  if (c > 64 && c < 91)
    return (true);
  return (false);
}


int	is_low_alpha(char c)
{
  if ((c > 96 && c < 123))
    return (true);
  return (false);
}

int	check_map(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if (is_low_alpha(buffer[i]))
	buffer[i] -= 32;
      if ((i % 8 == 0 || i % 8 == 3 || i % 8 == 6) && !char_is_num(buffer[i]))
	return (false);
      else if ((i % 8 == 2 || i % 8 == 5) && !char_is_char(buffer[i]))
	return (false);
      else if ((i % 8 == 1 || i % 8 == 4) && buffer[i] != ':')
	return (false);
      i++;
    }
  return (true);
}
