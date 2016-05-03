/*
** bsq.h for bsqpointh in /home/nonnen_p/CPE_2015_BSQ
** 
** Made by Paul NONNENMACHER
** Login   <nonnen_p@epitech.net>
** 
** Started on  Mon Nov 30 11:59:55 2015 Paul NONNENMACHER
** Last update Wed Dec  9 16:22:04 2015 Paul NONNENMACHER
*/

#ifndef BSQ_H_
# define BSQ_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define OPEN_ERROR {my_putstrerror("bsq: cannot access ");\
    my_putstrerror(av[1]); my_putstrerror(": No such file or directory\n");}

typedef struct	s_map
{
  char	**map;
  int	**square;
  int	lenght;
  int	height;
  int	fd;
}		t_map;

typedef struct s_pos
{
  int	x;
  int	y;
}		t_pos;

/*
** get_next_line.c
*/

char	*get_next_line(const int);

/*
** my_print.c
*/

void	my_putchar(char);
int	my_putstr(char	*);
void	my_putcharerror(char);
int	my_putstrerror(char *);
int	my_strlen(char *);

/*
** my_get_nbr.c
*/

int	my_getnbr(char *);

/*
** algo.c
*/

t_map	fill_square(t_map, int, int);
t_pos	get_pos(t_map, t_pos);
t_map	fill_final(t_map, t_pos);

/*
** check.c
*/

int	check_line(t_map);
int	check_carac(t_map);
int	check_n(t_map);
int	check_dot(t_map);

/*
** bsq.c
*/

void	print_map(t_map);
#endif /* !BSQ_H_ */
