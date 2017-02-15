/*
** check_map.c for navy in /home/brice/Documents/PSU/PSU_2016_navy/src
**
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
**
** Started on  Mon Jan 30 15:58:12 2017 Brice Lang-Nguyen
** Last update Wed Feb 15 15:35:51 2017 Brice Lang-Nguyen
*/

#include "navy.h"

int	char_is_num(char c)
{
  if ((c > 48 && c <= 56))
    return (true);
  return (false);
}


int	char_is_char(char c)
{
  if ((c > 64 && c <= 72) || is_low_alpha(c))
    return (true);
  return (false);
}


int	is_low_alpha(char c)
{
  if ((c > 96 && c <= 104))
    return (true);
  return (false);
}

int	size_is_ok(char *buff)
{
  int	i;

  i = 0;
  while (i < 32)
    {
      i += 8;
      if (buff[i-3] == buff[i-6])
	{
	  if (buff[i-8] != (buff[i-2] - buff[i-5] + '0' + 1))
	    return (false);
	}
      else if (buff[i-2] ==  buff[i-5])
	{
	  if (buff[i-8] != (buff[i-3] - buff[i-6] + '0' + 1))
	    return (false);
	}
      else
	return (false);
    }
  return (true);
}

int	check_map(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if ((i % 8 == 0 || i % 8 == 3 || i % 8 == 6) && !char_is_num(buffer[i]))
	return (false);
      else if ((i % 8 == 2 || i % 8 == 5) && !char_is_char(buffer[i]))
	return (false);
      else if ((i % 8 == 1 || i % 8 == 4) && buffer[i] != ':')
	return (false);
      i++;
    }
  if (!size_is_ok(buffer))
    return (false);
  else if (!same_size(buffer))
    return (false);
  return (true);
}
