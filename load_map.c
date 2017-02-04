/*
** load_map.c for navy in /home/brice/Documents/PSU/PSU_2016_navy
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Sat Feb  4 17:28:09 2017 Brice Lang-Nguyen
** Last update Sat Feb  4 17:42:20 2017 Brice Lang-Nguyen
*/

#include <stdlib.h>

char	*load_map(char *buff)
{
  char	**map;
  int	i;

  map = create_map();
  i = 0;
  while (buff[i] != '\0')
    {
      while (buff[i] != '\n')
	i++;
      if (char_is_char(buff[i-1]) && char_is_char(buff[i-4]))
	
    }
}
