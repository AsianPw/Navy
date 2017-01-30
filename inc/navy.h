/*
** navy.h for navy in /home/brice/Documents/PSU/PSU_2016_navy
**
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
**
** Started on  Mon Jan 30 12:18:17 2017 Brice Lang-Nguyen
** Last update Mon Jan 30 22:54:27 2017 Brice Lang-Nguyen
*/

#ifndef NAVY_H_
#define NAVY_H_


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "lib.h"
#include "../lib/my/my_printf.h"

int	my_printf(const char*, ...);
int	check_map(char*);
void	my_help();
int	player1(int);
int	player2(int);

#endif
