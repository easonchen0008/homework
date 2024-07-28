#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,r,b;
    scanf("%d %d %d",&h,&r,&b);
    if(h<=r)
    {
        printf("1");
    }
    else if(b>=r)
    {
        printf("-1");
    }else
    {
    int c=1;
    while(1)
    {
        h-=r;
        if(h<=0)
            break;
        h+=b;
        c++;
    }
    printf("%d",c);
    }

}
