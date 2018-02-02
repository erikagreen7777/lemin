#include "../lemin.h"


void    find_start(t_info *data)
{
    int i;
    i = 0;
    while (data->file[i])
    {
        if (ft_strstr("##start", data->file[i])){
            data->start = i;
            break;
        }
        i++;
    }
    if (data->start == -1)
        ft_error("ERROR");
    if (check_start_room(data))
        ;
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
            break;
        }
        i++;
    }
    if (data->end == -1)
        ft_error("ERROR");
    if (check_end_room(data))
        ;
    if (ft_strcmp(data->startstr, data->endstr) == 0)
        ft_error("ERROR");
}

static void check_pipe_duplicates(t_info *data)
{
    int i;
    i = 0;
    int j;
    while (i < data->pipecount - 1)
    {
        j = i + 1;
        while (j < data->pipecount)
        {
            if (ft_strcmp(data->pipes[i], data->pipes[j]) == 0)
                ft_error("ERROR");
            else
                j++;
        }
        i++;
    }
}

void    assign_pipes(t_info *data)
{
    int i = 0;
    int j = 0;
    while (data->file[i])
    {
        if (ft_strchr(data->file[i], '-'))
        {
            if (((i < data->start || i < data->end)) || (i == data->start || i == data->end))
                ft_error("ERROR");
            else
                data->pipes[j] = ft_strdup(data->file[i]);

            j++;
        }
        i++;
    }
    data->pipes[j] = NULL;
    check_pipe_duplicates(data);
    j = -1;
    while (data->pipes[++j])
        printf("data->pipes[%d]: %s\n", j, data->pipes[j]);
}

void    find_pipes(t_info *data)
{
    int i;
    i = 0;

    while (data->file[i])
    {
        if (ft_strchr(data->file[i], '-'))
            data->pipecount++;
        i++;
    }
    if (data->pipecount == 0)
        ft_error("ERROR");
    data->pipes = (char **)ft_memalloc(sizeof(data->pipes) * data->pipecount + 1);
    assign_pipes(data);
}

void    validate(t_info *data)
{
    find_start(data);
    find_end(data);
    assign_rooms(data);
    find_pipes(data);
}




