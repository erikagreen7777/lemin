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
    // ft_printf("data->endstr: %s\n", data->endstr);
}

void    assign_pipes(t_info *data)
{
    int i = 0;
    int j = 0;
    while (data->file[i])
    {
        if (ft_strchr(data->file[i], '-'))
        {
            data->pipes[j] = ft_strdup(data->file[i]);

            j++;
        }
        i++;
    }
    data->pipes[j] = NULL;
    j = -1;
    while (data->pipes[++j])
        printf("data->pipes[%d]: %s\n", j, data->pipes[j]);
}

void    find_pipes(t_info *data)
{
    int i;
    i = 0;
    int pipecount;
    pipecount = 0;

    while (data->file[i])
    {
        if (ft_strchr(data->file[i], '-'))
            pipecount++;
        i++;
    }
    if (pipecount == 0)
        ft_error("ERROR");
    data->pipes = (char **)ft_memalloc(sizeof(data->pipes) * pipecount + 1);
    assign_pipes(data);
}

void    validate(t_info *data)
{
    find_start(data);
    find_end(data);
    find_pipes(data);
    assign_rooms(data);
}




