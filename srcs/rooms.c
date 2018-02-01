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
//            printf("start str: %s\n", data->startstr);
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
//            printf("end str: %s\n", data->endstr);
            return (1);
        }
    }
    return (0);
}

void	room_trim_rooms(t_info *data)
{
    char *temp = NULL;
    int i = 0;
    temp = (char *)ft_memalloc(sizeof(data->rooms[data->curr] + 1));
    temp = data->rooms[data->curr];
	while (temp[i] != ' ' || temp[i] != '\n')
    {
       //add in "spacecount" and check for number of spaces?
        if (temp[i] ==  ' ' || temp[i] == '\n')
            break;
        i++;
    }
    data->rooms[data->curr] = ft_strndup(temp, i);
}

void clean_rooms(t_info *data) {
    int i;
    i = data->start - 1;
    while (++i < data->linecount)
    {
        if (ft_strstr("##end", data->rooms[i]))
            ft_strdel(&data->rooms[i]);
    }

    data->curr = data->start - 1;
    while (++data->curr < data->linecount)
    {
        if (data->rooms[data->curr] != NULL && (!(ft_strstr(data->rooms[data->curr], "##start"))
            && (!(ft_strstr(data->rooms[data->curr], "##end")))) )
            room_trim_rooms(data);
        else
            ;
    }

}

void    assign_rooms(t_info *data) {

    int i;
    i = data->start;
    data->rooms = (char **)ft_memalloc(sizeof(char *) * data->linecount + 1);
    while (i < data->linecount) {
        data->rooms[i] = ft_strdup(data->file[i]);
        i++;
    }
    clean_rooms(data);
    int j = -1;
    while (++j < data->linecount)
    {
        if (data->rooms[j] != NULL)
            printf("after: HERE ARE THE NEW ROOMS[%d]: %s\n", j, data->rooms[j]);
    }
    //clean non-essential information from the struct
    //then room trim the room info
}
