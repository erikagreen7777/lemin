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
        ft_error("find_startERROR");
    if (check_start_room(data))
        ;
    else
        ft_error("find start 2ERROR");
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
        ft_error("infd_end ERROR");
    if (check_end_room(data))
        ;
    if (ft_strcmp(data->startstr, data->endstr) == 0)
        ft_error("find end 2ERROR");
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
            if (ft_strcmp(data->pipes[i], data->pipes[j]) == 0){
                printf("duplicate pipe - what to do with the adjacency list?\n");
                break;
            }
            else
                j++;
        }
        i++;
    }
}

static int  is_pipe(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (str[i] == '-')
            break;
        i++;
    }
    if (!ft_isalnum(str[i - 1]) || (!ft_isalnum(str[i + 1])))
        return (1);
    return (0);
}

void    assign_pipes(t_info *data)
{
    int i = data->pipestart;
    int j = 0;
    while (data->file[i])
    {
        if (!(ft_strchr(data->file[i], '-')))
            ft_error("not a pipe ERROR");
        if (ft_strchr(data->file[i], '-'))
        {
            if ((is_pipe(data->file[i]) == 1))
                ft_error("is_pipe ERROR");
            if (((i < data->start || i < data->end)) || (i == data->start || i == data->end))
                ft_error("assign pipes ERROR");

            else {
                data->pipes[j] = ft_strdup(data->file[i]);
            }
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
        if (ft_strchr(data->file[i], '-') && (i > data->end))
            data->pipecount++;

        i++;
    }
    if (data->pipecount == 0)
        ft_error("find pipesERROR");
    data->pipestart = data->linecount - data->pipecount;
    printf("pipestart: %d\n", data->pipestart);
    data->pipes = (char **)ft_memalloc(sizeof(data->pipes) * data->pipecount + 1);
    assign_pipes(data);
}

void    validate(t_info *data)
{
    find_start(data);
    find_end(data);
    find_pipes(data);
    assign_rooms(data);
}




