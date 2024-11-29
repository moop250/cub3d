/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:11:23 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/10 17:52:10 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 128
# endif

# ifndef MAX_FD
#  define MAX_FD 4096
# endif

typedef struct s_file
{
	int				fd;
	char			*content;
	struct s_file	*next;
}	t_file;

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_free_str(char **str);
char	*gnl_strjoin(char *s1, char *s2);

#endif
