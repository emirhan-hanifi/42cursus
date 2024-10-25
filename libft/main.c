#include "libft.h"
#include <stdio.h>

int main() {
    char    **res;
    char    *s = " emirhan, hanifi, HABEŞ";
    char    c = ' ';
    
    res = ft_split(s, c);

    while (*res)
        printf("%s \n", *res++);

    while (*res)
        free(*res++);

    return (0);
}
