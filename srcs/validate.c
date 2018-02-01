#include "../lemin.h"


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
        ;
        // start_trim(data);
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
        ;
        // room_trim(data, 1);
    if (ft_strcmp(data->startstr, data->endstr) == 0)
        ft_error("ERROR");
    ft_printf("data->endstr: %s\n", data->endstr);
}


void    validate(t_info *data)
{

    find_start(data);
    find_end(data);
    assign_rooms(data);

}

   //  int j = -1;
   // // printf("data->linecount: %d\n", data->linecount);
   //  while (++j < data->linecount)
   //  {
   //      // if (data->rooms[j] != NULL)
   //          printf("HERE ARE THE NEW ROOMS[%d]: %s\n", j, data->rooms[j]);
   //  }


