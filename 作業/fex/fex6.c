#include <stdio.h>
#include <stdlib.h>
int main()
{
    char c,cc;
    int n;
    scanf("%c %c %d", &c,&cc,&n);
    float ans=0;
    if(n%2==0)
    {
        for(float i=2 ;i<=n;i+=2)
        {
            ans+=1/i;
            int j = i;
            printf("1/%d",j);
            if(i!=n)
            {
                printf("+");
            }else
            {
                printf("=");
            }
        }
        printf("%.3f",ans);
    }else
    {
        for(float i=1 ;i<=n;i+=2)
        {
            ans+=1/i;
            int j = i;
            printf("1/%d",j);
            if(i!=n)
            {
                printf("+");
            }else
            {
                printf("=");
            }
        }
        printf("%.3f",ans);
    }

}
