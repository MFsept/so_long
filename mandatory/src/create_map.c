/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:03:52 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/31 15:25:20 by mfernand         ###   ########.fr       */
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

char	**maplist_to_tab(t_maplist *lst, int size)
{
	char		**map;
	int			i;
	t_maplist	*tmp;

	map = malloc(sizeof(char *) * (size + 1));
	i = 0;
	tmp = lst;
	if (!map)
		return (NULL);
	while (tmp)
	{
		map[i++] = ft_strdup(tmp->line);
		tmp = tmp->next;
	}
	map[i] = NULL;
	return (map);
}

char	**create_map(int fd)
{
	t_maplist *lst;
	char *line;
	int size;
	char **map;

	lst = NULL;
	size = 0;
	while ((line = get_next_line(fd)))
	{
		if (!maplist_add(&lst, line))
			return (maplist_clear(lst), NULL);
		size++;
	}
	map = maplist_to_tab(lst, size);
	maplist_clear(lst);
	return (map);
}