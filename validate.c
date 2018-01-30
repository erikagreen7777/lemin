#include "../lemin.h"

// static char		*ft_strndup(const char *s1, int n)
// {
//     char	*ret;
//     int		i;

//     if (!(ret = (char*)malloc(sizeof(*ret) * (n + 1))))
//         return (NULL);
//     i = -1;
//     while (++i < n)
//         ret[i] = s1[i];
//     ret[i] = '\0';
//     return (ret);
// }

static void room_trim(t_info *data, char *str, int storend)
{
    int i;
    i = 0;
    char *temp = str;
    while (temp[i] != ' ' || temp[i] != '\n')
    {
        if (temp[i] ==  ' ' || temp[i] == '\n')
        {
            break;
        }
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

void    find_start(t_info *data)
{
    int i;
    i = 0;
    char *str;

    while (data->file[i])
    {
        if (ft_strstr("##start", data->file[i])){
            data->start = i;
            printf("found it! line: %d data->start: %d\n", i, data->start);
            break;
        }
        i++;
    }
    if (data->start == -1)
        ft_error("error: no start room");
    str = data->file[data->start + 1];
    room_trim(data, str, 0);

}

void    find_end(t_info *data)
{
    int i;
    i = 0;
    char *str;

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
        ft_error("error: no start room");
    str = data->file[data->end + 1];
    room_trim(data, str, 1);
}

void    validate(t_info *data)
{
    find_start(data);
    find_end(data);
}

