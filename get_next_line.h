/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <mea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:08:40 by mea               #+#    #+#             */
/*   Updated: 2022/05/30 13:11:57 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

char *ft_strjoin(char *s1, char *s2);
void ft_bzero(void *ptr, size_t count);
void *ft_calloc(size_t count, size_t size);
char *get_next_line(int fd);

#endif

