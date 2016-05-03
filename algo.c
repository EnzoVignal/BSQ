/*
** algo.c for algo in /home/nonnen_p/CPE_2015_BSQ
** 
** Made by Paul NONNENMACHER
** Login   <nonnen_p@epitech.net>
** 
** Started on  Wed Dec  2 00:20:55 2015 Paul NONNENMACHER
** Last update Tue May  3 18:12:25 2016 paul nonnenmacher
*/

#include "bsq.h"

int	lower(t_map map, int i, int j)
{
  int	lower;

  lower = map.square[i][j - 1];
  if (map.square[i - 1][j] < lower)
    lower = map.square[i -1][j];
  if (map.square[i - 1][j - 1] < lower)
    lower = map.square[i -1][j - 1];
  ++lower;
  return (lower);
}

t_map	fill_square(t_map map, int i, int j)
{
  while (map.map && map.map[i])
    {
      if ((map.square[i] = malloc(sizeof(int)
				  * my_strlen(map.map[i]) + 1)) == NULL)
	exit(EXIT_FAILURE);
      j = 0;
      while (map.map[i] && map.map[i][j])
	{
	  if (map.map[i][j] == 'o')
	    map.square[i][j] = 0;
	  else
	    {
	      if (i == 0 || j == 0)
		map.square[i][j] = 1;
	      else
		map.square[i][j] = lower(map, i, j);
	    }
	  ++j;
	}
      map.square[i][j] = -1;
      ++i;
    }
  map.square[i] = NULL;
  return (map);
}

t_pos	get_pos(t_map map, t_pos pos)
{
  int	i;
  int	j;
  int	max;

  i = 0;
  max = 0;
  while (map.square && map.square[i])
    {
      j = 0;
      while (map.square[i] && map.square[i][j] != -1)
	{
	  if (map.square[i][j] > max)
	    {
	      max = map.square[i][j];
	      pos.y = j;
	      pos.x = i;
	    }
	  ++j;
	}
      ++i;
    }
  return (pos);
}

t_map	fill_final(t_map map, t_pos pos)
{
  int	i;
  int	j;
  int	max;

  max = map.square[pos.x][pos.y];
  i = 0;
  while (max - i != 0)
    {
      j = 0;
      while (max - j != 0)
	{
	  map.map[pos.x - i][pos.y - j] = 'x';
	  ++j;
	}
      ++i;
    }
  return (map);
}
