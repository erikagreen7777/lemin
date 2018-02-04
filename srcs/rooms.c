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
    int spacecount;
    i = 0;
    spacecount = 1;
    while (str[i])
    {
        if (str[i] == ' ')
        {   spacecount++;
            if (!ft_isdigit(str[i + 1]))
                return (1);
        }
        i++;
    }
    if (spacecount != 3)
        ft_error("spacecount ERROR");
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
            if (ft_strcmp(data->rooms[i], data->rooms[j]) == 0){
                printf("data->rooms[i]: %s\n", data->rooms[i]);
                ft_error("rooms ERROR");
            }
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
        if (temp[i] == ' ')
        {
            if (check_room(temp) == 1){
                printf("temp[%d]: %s\n", i, temp);
                ft_error("room trim ERROR");
            }
            else
                break;
        }
        i++;
    }
    ft_strncpy(str, temp, i);
    return (str);
}

void    assign_rooms(t_info *data)
{
    int i;
    i = 1;
    int j = 0;
    data->rooms = (char **)ft_memalloc(sizeof(char *) * data->linecount);
    while (data->file[i]/* && (i >= data->start && i <= data->end)*/)
    {
        if (ft_strchr(&data->file[i][0], 'L'))
            ft_error("assign rooms ERROR");
        // if (ft_strchr(data->file[i]))
        if ((!ft_strchr(data->file[i], '-') && (data->file[i][0] != '#')) && (i < data->pipestart))
        {
            data->rooms[j] = ft_strdup(data->file[i]);
            room_trim(data->rooms[j]);
            data->roomcount++;
            j++;
        }
        i++;
    }
    if (data->roomcount == 0)
        ft_error("assign rooms 2ERROR");
    check_room_duplicates(data);
    // i = -1;
    // while (++i < data->roomcount)
    //     printf("rooms[%d]: %s\n", i, data->rooms[i]);

}