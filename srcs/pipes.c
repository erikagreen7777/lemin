#include "../lemin.h"

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
        if (!(ft_strchr(data->file[i], '-')) && (data->file[i][0] != '#'))
            ft_error("not a pipe ERROR");
        if (ft_strchr(data->file[i], '-'))
        {
            if ((is_pipe(data->file[i]) == 1))
                ft_error("is_pipe ERROR");
            if (((i < data->start || i < data->end)) || (i == data->start || i == data->end))
                ft_error("assign pipes ERROR");
            else/* if (data->file[i][0] != '#')*/
                data->pipes[j] = ft_strdup(data->file[i]);
            j++;
        }
        i++;
    }
    data->pipes[j] = NULL;
    // check_pipe_duplicates(data);

}

void    parse_pipes(t_info *data, t_graph *graph)
{
	int i;
	i = 0;
    
	// int j = -1;
 //    while (data->pipes[++j])
 //        printf("data->pipes[%d]: %s\n", j, data->pipes[j]);
	while (data->pipes[i])
	{	
        data->vertex = ft_strsplit(data->pipes[i], '-');
        addEdgeString(graph, data->vertex[0], data->vertex[1]);
        i++;
       
	}
}

//underflow room trim error
//overflow weird pointer malloc thing
//test1 has two ##starts
//map14 no solution found
//europe
//europe-utf
//42
//bmap no solution found
//big
//mmkr2