/*
** same_size.c for navy in /home/brice/Documents/PSU/PSU_2016_navy
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Wed Feb 15 15:33:56 2017 Brice Lang-Nguyen
** Last update Wed Feb 15 15:39:43 2017 Brice Lang-Nguyen
*/

#include "navy.h"

int	same_size(char *mp)
{
  if (mp[0] == mp[8] || mp[0] == mp[16] || mp[0] == mp[24])
    return (false);
  else if (mp[8] == mp[16] || mp[8] == mp[24])
    return (false);
  else if (mp[16] == mp[24])
    return (false);
  return (true);
}
