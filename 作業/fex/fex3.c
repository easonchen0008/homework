#include <stdio.h>
using namespace std;

int main()
{
    int m,n;
    scanf("%d%d",&m ,&n);
    printf("A=\n");
    int in=1;
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            printf("%d ", in);
            in++;
        }
        printf("\n");
    }
    printf("\n");
    printf("B=\n");
    in=1;
for(int i = 0; i<n; i++)
    {
        in = i+1;
        for(int j = 0; j<m; j++)
        {
            printf("%d ", in);
            in+=n;
        }
        printf("\n");
    }
}
