/*
** get_next_line.c for gentxtline in /home/nonnen_p/get_next_line
** 
** Made by Paul NONNENMACHER
** Login   <nonnen_p@epitech.net>
** 
** Started on  Wed Oct 28 15:26:22 2015 Paul NONNENMACHER
** Last update Tue May  3 18:13:09 2016 paul nonnenmacher
*/

#include "bsq.h"

char	*realloc_str(char *str, char c)
{
  char	*new_str;
  int	i;

  i = 0;
  if ((new_str = malloc(sizeof(char) * my_strlen(str) + 2)) == NULL)
    return (NULL);
  while (str && str[i])
    {
      new_str[i] = str[i];
      ++i;
    }
  new_str[i] = c;
  new_str[i + 1] = 0;
  return (new_str);
}

char	*get_var(int fd, char *str, char *buff)
{
  static int	i = 0;
  int		is_last;

  is_last = 0;
  while (read(fd, buff, 1) > 0)
    {
      is_last = 1;
      if (buff[0] != '\n')
	str = realloc_str(str, buff[0]);
      else
	{
	  ++i;
	  return (str);
	}
    }
  return (is_last > 0? str : NULL);
}

char	*get_next_line(int fd)
{
  char		*str;
  char		*buff;

  if ((str = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  if ((buff = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  return (get_var(fd, str, buff));
}
