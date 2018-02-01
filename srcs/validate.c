#include "../lemin.h"

//nopath isn't accounted for
//no_tubes isn't accounted for
//bad_rooms
//space_room && space_room2
//apparently simple2 is INVALID



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
        ft_error("ERROR");
    if (check_start_room(data))
        room_trim(data, 0);
    else
        ft_error("ERROR");
}

void    find_end(t_info *data)
{
    int i;
    i = 0;

    while (data->file[i])
    {
        if (ft_strstr("##end", data->file[i])){
            data->end = i;
//            printf("found it! line: %d data->end: %d\n", i, data->end);
            break;
        }
        i++;
    }
    if (data->end == -1)
        ft_error("ERROR");
    if (check_end_room(data))
        room_trim(data, 1);
    if (ft_strcmp(data->startstr, data->endstr) == 0)
        ft_error("ERROR");
}


void    validate(t_info *data)
{
    find_start(data);
    find_end(data);
    assign_rooms(data);

}

