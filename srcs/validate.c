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

// static void check_pipe_duplicates(t_info *data)
// {
//     int i;
//     i = 0;
//     int j;
//     while (i < data->pipecount)
//     {
//         j = i + 1;
//         while (j < data->pipecount)
//         {
//             if (ft_strcmp(data->pipes[i], data->pipes[j]) == 0){
//                 printf("duplicate pipe - what to do with the adjacency list?\n");
//                 break;
//             }
//             else
//                 j++;
//         }
//         i++;
//     }
// }



void    find_pipes(t_info *data)
{
    int i;
    i = 0;
    int commentcount = 0;

    while (data->file[i])
    {
        if ((ft_strchr(data->file[i], '-')) && (i < data->end))
            ft_error("pipes in rooms ERROR");
        if ((ft_strchr(data->file[i], '-') || data->file[i][0] == '#') && i > data->end){
            if (data->file[i][0] == '#'){
                commentcount++;
            }
            data->pipecount++;
        }
        // if (data->file[i][0] == '#' && i > data->end)

        i++;
    }
    if (data->pipecount == 0)
        ft_error("find pipesERROR");
    data->pipecount -= commentcount;
    data->pipestart = data->linecount - data->pipecount;
    // printf("data->end: %d\npipecount: %d\n", data->end, data->pipecount);
    // printf("comomentcount: %d\npipestart: %d\n", commentcount, data->pipestart);
    data->pipes = (char **)ft_memalloc(sizeof(data->pipes) * data->pipecount + 1);
    assign_pipes(data);
}

void    validate(t_info *data)
{

    find_start(data);
    find_end(data);
    // printf("before data->start: %d\nbefore data->end: %d\nbefore data->swap: %d\n", data->start, data->end, data->swap);
    if (data->start > data->end)
    {
        ft_swap(&data->end, &data->start);
        data->swap = 1;
    }
    // printf("after data->start: %d\nafter data->end: %d\nafter data->swap: %d\n", data->start, data->end, data->swap);
    find_pipes(data);
    assign_rooms(data);
}




