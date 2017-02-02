/*
** errmsg.c for errmsg in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 17:23:25 2017 Sadisadou
** Last update Tue Jan 31 17:36:09 2017 Sadisadou
*/

#include "navy.h"

int	openerr(int fd)
{
  if (fd == -1)
    {
      my_strerror("Can't open the pos file.\n");
      return (fd);
    }
  return (fd);
}
