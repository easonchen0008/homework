#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
char c,cc;
int n;
scanf("%c %c %d", &c,&cc,&n);
srand( time(NULL) );

for(int i =0;i<n;i++)
{
    int x = rand()%51;
    if(x/13==0)
    {
        int i = (x%13) +1;
        printf("A%d(愛心%d), ",i,i);
    }else if(x/13 == 1)
    {
        int i = (x%13) +1;
        printf("B%d(黑桃%d), ",i,i);
    }else if(x/13 == 2)
    {
        int i = (x%13) +1;
        printf("C%d(方塊%d), ",i,i);
    }else if(x/13 == 3)
    {
        int i = (x%13) +1;
        printf("D%d(梅花%d), ",i,i);
    }
}

}
