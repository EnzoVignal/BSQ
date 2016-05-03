/*
** my_print.c for myprint in /home/nonnen_p/PSU_2015_my_ls
** 
** Made by Paul NONNENMACHER
** Login   <nonnen_p@epitech.net>
** 
** Started on  Fri Nov 20 10:47:40 2015 Paul NONNENMACHER
** Last update Tue May  3 18:13:40 2016 paul nonnenmacher
*/

#include "bsq.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  if (str)
    while (*str)
      my_putchar(*str++);
  return (EXIT_SUCCESS);
}

void	my_putcharerror(char c)
{
  write(2, &c, 1);
}

int	my_putstrerror(char *str)
{
  if (str)
    while (*str)
      my_putcharerror(*str++);
  return (EXIT_FAILURE);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    ++i;
  return (i);
}
