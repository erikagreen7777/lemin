#include "../lemin.h"

int      check_start_room(t_info *data)
{
    while (data->file[data->start])
    {
        if (data->file[data->start][0] == '#')
            data->start++;
        if ((data->file[data->start][0] != '#') && (data->file[data->start][0] != 'L'))
        {
            data->startstr = data->file[data->start];
           // printf("start str: %s\n", data->startstr);
            return (1);
        }
    }
    return (0);
}

int      check_end_room(t_info *data)
{
    while (data->file[data->end])
    {
        if (data->file[data->end][0] == '#')
            data->end++;
        if ((data->file[data->end][0] != '#') && (data->file[data->end][0] != 'L'))
        {
            data->endstr = data->file[data->end];
           // printf("end str: %s\n", data->endstr);
            return (1);
        }
    }
    return (0);
}

static int  check_room(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
        {
            if (!(ft_isdigit(str[i + 1])))
                return (1);
        }
        i++;
    }
    return (0);
}

static void    check_room_duplicates(t_info *data)
{
    int i;
    i = 0;
    int j;
     while (i < data->roomcount)
    {
        j = i + 1;
        while (j < data->roomcount)
        {
            if (ft_strcmp(data->rooms[i], data->rooms[j]) == 0)
                ft_error("ERROR");
            else
                j++;
        }
        i++;
    }   
}

char    *room_trim(char *str)
{
    int i = 0;
    char *temp = (char *)ft_memalloc(sizeof(str));
    ft_strcpy(temp, str);
    ft_bzero(str, sizeof(str));
    while (temp[i])
    {
        if (temp[i] == ' ' || temp[i] == '\n' || temp[i] == '\t')
        {
            if (check_room(temp) == 1)
                ft_error("ERROR");
            else
                break;
        }
        i++;
    }
    ft_strncpy(str, temp, i);
    ft_strdel(&temp);
    return (str);
}

void    assign_rooms(t_info *data)
{
    int i;
    i = 1;
    // (data->start > data->end) ? (i = data->end) : (i = data->start);
    int j = 0;
    data->rooms = (char **)ft_memalloc(sizeof(char *) * data->linecount);
    while (data->file[i])
    {
        if (ft_strchr(&data->file[i][0], 'L'))
            ft_error("ERROR");
        if (!ft_strchr(data->file[i], '-') && (!ft_strchr(&data->file[i][0], '#')))
        {
            data->rooms[j] = ft_strdup(data->file[i]);
            // printf("room[%d]: %s\n", i, data->file[i]);
            room_trim(data->rooms[j]);
            // printf("new room[%d]: %s\n", i, data->rooms[j]);
            data->roomcount++;
            j++;
        }
        i++;
    }
    if (data->roomcount == 0)
        ft_error("ERROR");
    check_room_duplicates(data);
    i = -1;
    while (++i < data->roomcount)
        printf("rooms[%d]: %s\n", i, data->rooms[i]);

}
