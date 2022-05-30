/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <mea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:51:02 by mea               #+#    #+#             */
/*   Updated: 2022/05/30 14:07:25 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i; 
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *ret;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2)
		return (NULL);
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

char *save_buffer(char *buffer, int *i)
{
	int	j;
	char *part1;
	char *part2;
	char *ret;

	part1 = calloc(4096, sizeof(char));
	j = 0;
	while (j < 4096)
	{
		part1[j] = buffer[*i];
		if (buffer[*i] == '\0'|| buffer[(*i)++] == '\n')
			return (part1);
		j++;
	}
	part2 = save_buffer(buffer, i);
	ret = ft_strjoin(part1, part2);
	free(part1);
	free(part2);
	return (ret);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(char *)(s + i++) = 0;
}

void *ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char *get_next_line(int fd)
{
	static char buffer[4096 + 1];
	static int 	i;
	char 		*line;
	char		*ret;
	char		*tmp;
	size_t		read_size;

	if (!*buffer)
	{
		read_size = read(fd, buffer, 4096);
		if (read_size <= 0)
			return (NULL);
		buffer[read_size] = 0;
	}
	ret = ft_calloc(1, sizeof(char));
	while (buffer[i])
	{
		tmp = save_buffer(buffer, &i);
		line = ft_strjoin(ret, tmp);
		free(ret);
		free(tmp);
		ret = line;
		if (buffer[i - 1] == '\n')
			break;
		read_size = read(fd, buffer, 4096);
		buffer[read_size] = 0;
		i = 0;
	}
	if (*ret)
		return (ret);
	free(ret);
	return (NULL);
}
