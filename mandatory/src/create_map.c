/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:03:52 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/31 14:24:51 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_maplist	*maplist_add(t_maplist **lst, char *line)
{
	t_maplist	*node;
	t_maplist	*last;

	node = malloc(sizeof(t_maplist));
	if (!node)
		return (NULL);
	node->line = line;
	node->next = NULL;
	if (!*lst)
		*lst = node;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = node;
	}
	return (node);
}

static void	maplist_clear(t_maplist *lst)
{
	t_maplist	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->line);
		free(lst);
		lst = tmp;
	}
}

char	**create_map(int fd)
{
	t_maplist	*lst;
	t_maplist	*tmp;
	char		**map;
	char		*line;
	int			i;

	lst = NULL;
    i = 0;
	while (1)
	{
        line = get_next_line(fd);
        if (!line)
            break;
		if (!maplist_add(&lst, line))
			return (maplist_clear(lst), NULL);
		i++;
	}
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (maplist_clear(lst), NULL);
    i = 0;
	tmp = lst;
	while (tmp)
	{
		map[i++] = ft_strdup(tmp->line);
		tmp = tmp->next;
	}
	map[i] = NULL;
	maplist_clear(lst);
	return (map);
}
