#include "libft.h"

char		*ft_strndup(const char *s1, int n)
{
    char	*ret;
    int		i;

    if (!(ret = (char*)malloc(sizeof(*ret) * (n + 1))))
        return (NULL);
    i = -1;
    while (++i < n)
        ret[i] = s1[i];
    ret[i] = '\0';
    return (ret);
}