/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:39:56 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/27 19:46:57 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// check_errors;

// check_map; --> checker si c est rectangle ou pas 
// check_content -> si il ya au moins 1 sortie 1 find_player_pos et au moins 1 collect 
// check_double; -> si il y a plus d une sortie ou d un player return error;
// check_wall -> verifier que toutes la map est encadre par des murs sinon return error;
// check_chemin_valid -> verifier si il y a

// int    check_errors(t_data m, int ac, char **av)
// {
        // 
// }
int check_file(int ac, char **av)
{
    if (ac != 2)
    {
        perror("Wrong number of arguments");
        return (0);
    }
    if (!(ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) == 0))
    {
        perror("Bad extension for the map");
        return (0);
    }
    return (1);
       
}
int check_map(t_data m)
{
    size_t len;
    int i = 0;

    if (!m.map || !m.map[0])
        return (0);
    len = ft_strlen(m.map[0]);
    while (m.map[i])
    {
        if (ft_strlen(m.map[i]) != len)
            return (0);
        i++;
    }
    return (1);
}

int check_content(t_data m)
{
    int j;
    int exit;
    int coll;
    int player;

    j = 0;
    exit = 0;
    coll = 0;
    player = 0;
    while(m.map[j])
    {
        if (ft_strchr(m.map[j], 'P') != 0)
            player++;
        else if (ft_strchr(m.map[j], 'C') != 0)
            coll++;
        else if (ft_strchr(m.map[j], 'E') != 0)
            exit++;
        else if (ft_strchr(m.map[j], '0') != 0 || ft_strchr(m.map[j], '1') != 0)
            continue;
        else
            return (0);
        j++;        
    }
    return(1);
}
int check_double(t_data m)
{
    int i;
    int j;
    int count_exit;
    int count_player;

    j = 0;
    count_exit = 0;
    count_player = 0;
    while (m.map[j])
    {
        i = 0;
        while (m.map[j][i])
        {
            if (m.map[j][i] == 'P')
                count_player++;
            else if (m.map[j][i] == 'E')
                count_exit++;
            i++;
        }
        j++;
    }
    return(1);
}
// int check_wall(t_data m)
// {
//     int i;
//     int j;
    
// }


// int check_valid_path(t_data m)
// {
    // 
// }