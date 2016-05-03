/*
** check.c for check in /home/nonnen_p/CPE_2015_BSQ
** 
** Made by Paul NONNENMACHER
** Login   <nonnen_p@epitech.net>
** 
** Started on  Thu Dec  3 15:00:42 2015 Paul NONNENMACHER
** Last update Tue May  3 18:12:52 2016 paul nonnenmacher
*/

#include "bsq.h"

int	check_line(t_map map)
{
  int	i;
  int	line;

  i = 0;
  line = my_strlen(map.map[i]);
  while (map.map && map.map[i])
    {
      if (my_strlen(map.map[i]) == line)
	++i;
      else
	{
	  my_putstrerror("File incorrect.\n");
	  return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}

int	check_carac(t_map map)
{
  int	i;
  int	j;

  i = 0;
  while (map.map && map.map[i])
    {
      j = 0;
      while (map.map[i] && map.map[i][j])
	{
	  if (map.map[i][j] == '.' || map.map[i][j] == 'o')
	    ++j;
	  else
	    {
	      my_putstrerror("File incorrect.\n");
	      return (EXIT_FAILURE);
	    }
	}
      ++i;
    }
  return (EXIT_SUCCESS);
}

int	check_n(t_map map)
{
  int	i;

  while (map.map && map.map[i])
    ++i;
  if (i != map.height)
    {
      my_putstrerror("File incorrect.\n");
      return (EXIT_FAILURE);
    }
  else
    return (EXIT_SUCCESS);
}

int	check_dot(t_map map)
{
  int	i;
  int	j;

  i = 0;
  while (map.map && map.map[i])
    {
      j = 0;
      while (map.map[i] && map.map[i][j])
	{
	  if (map.map[i][j] == '.')
	    return (EXIT_SUCCESS);
	  else
	    ++j;
	}
      ++i;
    }
  print_map(map);
  return (EXIT_FAILURE);
}
