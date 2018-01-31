#include "../lemin.h"

static void room_trim(t_info *data, int storend)
{
    int i;
    i = 0;
    char *temp = data->startstr;
    while (temp[i] != ' ' || temp[i] != '\n')
    {
        if (temp[i] ==  ' ' || temp[i] == '\n')
            break;
        i++;
    }
    if (storend == 0)
    {
        data->startingroom = ft_strndup(temp, i);
        printf("data->startingroom: %s\n", data->startingroom);
    }
    else if (storend == 1)
    {
        data->endingroom = ft_strndup(temp, i);
        printf("data->endingroom: %s\n", data->endingroom);
    }
}

static int      check_start_room(t_info *data)
{
    while (data->file[data->start])
    {
        if (data->file[data->start][0] == '#')
            data->start++;
        if ((data->file[data->start][0] != '#') && (data->file[data->start][0] != 'L'))
        {
            data->startstr = data->file[data->start];
            printf("start str: %s\n", data->startstr);
            return (1);
        }
    }
    return (0);
}

static int      check_end_room(t_info *data)
{
    while (data->file[data->end])
    {
        if (data->file[data->end][0] == '#')
            data->end++;
        if ((data->file[data->end][0] != '#') && (data->file[data->end][0] != 'L'))
        {
            data->endstr = data->file[data->end];
            printf("end str: %s\n", data->endstr);
            return (1);
        }
    }
    return (0);
}
void    find_start(t_info *data)
{
    int i;
    i = 0;
    while (data->file[i])
    {
        if (ft_strstr("##start", data->file[i])){
            data->start = i;
//            printf("found it! line: %d data->start: %d\n", i, data->start);
            break;
        }
        i++;
    }
    if (data->start == -1)
        ft_error("error: no start room");
    if (check_start_room(data))
        room_trim(data, 0);
    else
        ft_error("no start room found");
}

void    find_end(t_info *data)
{
    int i;
    i = 0;

    while (data->file[i])
    {
        if (ft_strstr("##end", data->file[i])){
            data->end = i;
            printf("found it! line: %d data->end: %d\n", i, data->end);
            break;
        }
        i++;
    }
    if (data->end == -1)
        ft_error("error: no end room");
    if (check_end_room(data))
        room_trim(data, 1);
    if (ft_strcmp(data->startstr, data->endstr) == 0)
        ft_error("error: no start/end room");
}

void    validate(t_info *data)
{
    find_start(data);
    find_end(data);
}

