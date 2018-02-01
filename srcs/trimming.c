#include "../lemin.h"

void    start_trim(t_info *data)
{
    int i;
    i = 0;
   printf("startstr: %s\n", data->startstr);
    int j = -1;
    while (data->file[++j])
        printf("beforethefile[%d]: %s\n", j, data->file[j]);
    printf("data->startstr: %s\n", data->startstr);
    while (data->startstr[i])
    {
       //add in "spacecount" and check for number of spaces?
        if (data->startstr[i] ==  ' ' || data->startstr[i] == '\n')
            break;
        i++;
    }
    printf("i: %d\tnewstartstr: %s\n", i, data->startstr);
    // data->startingroom = ft_strndup(temp, i);
    // printf("linecound: %d\n", data->linecount);
    printf("data_.startingroom: %s\n", data->startingroom);

}

void room_trim(t_info *data, int storend)
{
    int i;
    i = 0;
    char *temp = NULL;
    if (storend == 0)
        temp = data->startstr;
    while (temp[i] != ' ' || temp[i] != '\n')
    {
       //add in "spacecount" and check for number of spaces?
        if (temp[i] ==  ' ' || temp[i] == '\n')
            break;
        i++;
    }
    if (storend == 0)
        data->startingroom = ft_strndup(temp, i);
   else if (storend == 1)
        data->endingroom = ft_strndup(temp, i);
}
