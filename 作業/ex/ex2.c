#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d",&a);
    int c;
    for(int i = 1;i <=a; i++)
    {
        c+=i*i;
    }
    printf("%d",c+3);
    return 0;
}
