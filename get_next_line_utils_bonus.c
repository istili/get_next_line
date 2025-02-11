/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 09:13:44 by istili            #+#    #+#             */
/*   Updated: 2023/12/08 23:48:27 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	if (str && str[len] == '\n')
		len++;
	return (len);
}

int	check_str(char *s)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (s && s[i])
	{
		if (flag > 0)
			s[j++] = s[i];
		else if (s[i] == '\n')
			flag = 1;
		s[i] = '\0';
		i++;
	}
	return (flag);
}

char	*ft_strjoin(char *line, char *bufr)
{
	char	*s;
	size_t	i;
	size_t	j;

	s = (char *)malloc(ft_strlen(line) + ft_strlen(bufr) + 1);
	if (!s)
		return ((free(line)), NULL);
	i = 0;
	while (line != NULL && line[i] != '\0')
	{
		s[i] = line[i];
		i++;
	}
	j = 0;
	while (bufr != 0 && bufr[j] != '\0' && bufr[j] != '\n')
	{
		s[i + j] = bufr[j];
		j++;
	}
	if (bufr != 0 && bufr[j] == '\n')
		s[i + j++] = '\n';
	s[i + j] = '\0';
	if (line)
		free(line);
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	size_t			i;
	size_t			s;
	unsigned char	*bytes;

	s = count * size;
	ret = malloc(s);
	if (!ret)
		return (NULL);
	bytes = (unsigned char *)ret;
	i = 0;
	while (i < s)
		bytes[i++] = 0;
	return (ret);
}
