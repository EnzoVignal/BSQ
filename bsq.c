/*
** bsq.c for bsq in /home/nonnen_p/CPE_2015_BSQ
** 
** Made by Paul NONNENMACHER
** Login   <nonnen_p@epitech.net>
** 
** Started on  Mon Nov 30 12:01:05 2015 Paul NONNENMACHER
** Last update Tue May  3 18:12:39 2016 paul nonnenmacher
*/

#include "bsq.h"

void	print_map(t_map map)
{
  int	i;

  i = 0;
  while (i < map.height)
    {
      my_putstr(map.map[i]);
      ++i;
      my_putchar('\n');
    }
}

t_map	fill_map(t_map map)
{
  int	i;

  i = 0;
  while ((map.map[i] = get_next_line(map.fd)) != NULL)
    ++i;
  map.map[i] = NULL;
  return (map);
}

void	aff_end(t_map map)
{
  t_pos	pos;

  pos = get_pos(map, pos);
  map = fill_final(map, pos);
  print_map(map);
}

int	do_all(t_map map)
{
  char	*str;

  str = get_next_line(map.fd);
  map.height = my_getnbr(str);
  if ((map.map = malloc(sizeof(char *) * map.height + 1)) == NULL)
    return (EXIT_FAILURE);
  if ((map.square = malloc(sizeof(int *) * map.height + 1)) == NULL)
    return (EXIT_FAILURE);
  map = fill_map(map);
  close(map.fd);
  if (check_line(map) == EXIT_FAILURE || check_carac(map) == EXIT_FAILURE
      || check_n(map) == EXIT_FAILURE || check_dot(map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  map = fill_square(map, 0, 0);
  aff_end(map);
  free(map.map);
  free(map.square);
  return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
  t_map		map;

  if (ac < 2)
    {
      my_putstr("Usage : ./bsq [FILE]\n");
      return (EXIT_SUCCESS);
    }
  if ((map.fd = open(av[1], O_RDONLY)) == -1)
    {
      OPEN_ERROR;
      return (EXIT_FAILURE);
    }
  return (do_all(map));
}
