/*
** errmsg.c for errmsg in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 17:23:25 2017 Sadisadou
** Last update Fri Feb  3 18:16:15 2017 Sadisadou
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
