#include "libft.h"
#include <stdio.h>

int main() {

    char    *s = "abcSelamunAleykümcba";
    char    *s2 = "abc";
    char *res = ft_strtrim(s, s2);
   
    printf("%s \n", res);
    
    free(res);
    
    return (0);
}
