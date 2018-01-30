#include "../lemin.h"

void    find_start(t_info *data)
{
    int i;
    i = 0;
    while (data->file[i])
    {
        if (ft_strstr("##start", data->file[i])){
            data->start = i;
            printf("found it! data->start: %d\n", data->start);
        }
        i++;
    }
    if (data->start == -1)
        ft_error("error: no start room");
}

void    find_end(t_info *data)
{
    int i;
    i = 0;
    while (data->file[i])
    {
        if (ft_strstr("##end", data->file[i])){
            data->end = i;
            printf("found it! data->end: %d\n", data->end);
        }
        i++;
    }
    if (data->end == -1)
        ft_error("error: no start room");
}

void    validate(t_info *data)
{
    find_start(data);
    find_end(data);
}

