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

void room_trim(t_info *data, int storend)
{
    int i;
    i = 0;
    char *temp = NULL;
    if (storend == 0)
        temp = data->startstr;
    else if (storend == 1)
        temp = data->endstr;
    else if (storend == 2)
        temp = data->rooms[data->curr];
    while (temp[i] != ' ' || temp[i] != '\n')
    {
       //add in "spacecount" and check for number of spaces?
        if (temp[i] ==  ' ' || temp[i] == '\n')
            break;
        i++;
    }
    if (storend == 0)
    {
        data->startingroom = ft_strndup(temp, i);
//        printf("data->startingroom: %s\n", data->startingroom);
    }
    else if (storend == 1)
    {
        data->endingroom = ft_strndup(temp, i);
//        printf("data->endingroom: %s\n", data->endingroom);
    }
    else if (storend == 2)
    {
        data->rooms[data->curr] = ft_strndup(temp, i);
//        printf("room-trim data->rooms: %s\n", data->rooms[data->curr]);
    }
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
        if (data->rooms[data->curr] != NULL)
            room_trim(data, 2);
    }
    i = data->start - 1;
    while (++i < data->linecount)
        printf("HERE ARE THE NEW ROOMS: %s\n", data->rooms[i]);

}

void    assign_rooms(t_info *data) {
    int i;
    i = data->start;
    data->rooms = (char **) ft_memalloc(sizeof(char *) * ((data->linecount + 1)));
    while (i < data->linecount) {
        data->rooms[i] = ft_strdup(data->file[i]);
        i++;
    }

    clean_rooms(data);
    //clean non-essential information from the struct
    //then room trim the room info
}
