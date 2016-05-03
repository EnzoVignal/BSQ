/*
** my_getnbr.c for getnbr in /home/nonnen_p/Piscine_C_J04
** 
** Made by Paul NONNENMACHER
** Login   <nonnen_p@epitech.net>
** 
** Started on  Thu Oct  1 09:54:53 2015 Paul NONNENMACHER
** Last update Tue May  3 18:13:58 2016 paul nonnenmacher
*/

#include "bsq.h"

int	my_ssstrlen(char *str)
{
  int	i;
  int	a;

  a = 0;
  i = 0;
  while (str && str[a] && (str[a] < '0' || str[a] > '9'))
    a = a + 1;
  while (str && str[a] && (str[a] >= '0' && str[a] <= '9'))
    {
      i = i + 1;
      a = a + 1;
    }
  return (i);
}

int	check_neg(char *str)
{
  int	neg;
  int	i;

  i = 0;
  neg = 0;
  while (str && str[i] && (str[i] < '0' || str[i] > '9'))
    {
      if (str[i] == '-')
	neg = neg + 1;
      i = i + 1;
    }
  if (neg % 2 != 0)
    return (1);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int	nb;
  int	i;
  int	result;

  i = my_ssstrlen(str);
  nb = 1;
  result = 0;
  while (i > 0)
    {
      nb = nb * 10;
      i = i - 1;
    }
  nb = nb / 10;
  while (str && str[i] && (str[i] < '0' || str[i] > '9'))
    i = i + 1;
  while (nb >= 1)
    {
      result = result + nb * (str[i] - 48);
      i = i + 1;
      nb = nb / 10;
    }
  if ((i = check_neg(str)) == 1)
    result = result  * -1;
  return (result);
}
