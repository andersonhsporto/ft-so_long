/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:25:24 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/28 00:34:59 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 10

char	*get_next_line(int fd);

/**
 * @brief Searches for the first occurrence of the character c
 * (an unsigned char) in the string pointed to by the argument s. The
 * terminating null	character is considered	part of	the string; therefore
 * if c is \\0, the functions locate the terminating \\0.
 *
 * @param str This is the C string to be scanned.
 * @param c This is the character to be located. It is passed as int,
 * but it is internally converted back to char.
 * @return This returns a pointer to the first occurrence of the character c
 * in the string s, or NULL if the character is not found.
 */
char	*gnl_strchr(char *str, char c);

/**
 * @brief Computes the length of the string s up to, but not including the
 * terminating null character. Example: ft_strlen("1234") => 4
 *
 * @param s This is the string whose length is to be found.
 * @return This function returns the length of string.
 */
size_t	gnl_strlen(const char *s);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’. (s1 free) s1+s2
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strdup(char *s);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
#endif