#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    while(scanf("%d",&a)!=EOF)
    {
    int arr[9]={0};
    scanf("%d",&b);
    c=b-a;
    while(c>=2000)
    {
        c-=2000;
        arr[0]++;
    }
    while(c>=1000)
    {
        c-=1000;
        arr[1]++;
    }

    while(c>=500)
    {
        c-=500;
        arr[2]++;
    }

    while(c>=200)
    {
        c-=200;
        arr[3]++;
    }
    while(c>=100)
    {
        c-=100;
        arr[4]++;
    }
    while(c>=50)
    {
        c-=50;
        arr[5]++;
    }
    while(c>=10)
    {
        c-=10;
        arr[6]++;
    }
    while(c>=5)
    {
        c-=5;
        arr[7]++;
    }

    while(c>=1)
    {
        c-=1;
        arr[8]++;
    }
    for(int i =0 ;i<9;i++)
    {
        printf("%d ",arr[i]);
    }
    }


}
