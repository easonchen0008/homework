#include <stdio.h>
#include <stdlib.h>
struct day
{
 int yy, mm, dd; /* �~�B��B�� */
};
struct data
{
 char name[20]; /* �m�W */
 char classNo; /* �Z�O */
 struct day birthday; /* �ͤ� */
 int math, eng; /* �ƾ� �P �^�妨�Z */
};
int main()
{
    char str[100];
    int all[100][26];
    int j =0;
    while(scanf("%s",&str)!=EOF)
    {
        size_t length = strlen(str);
        for(int i =0;i<length;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                all[j][str[i]-'a']++;
            }
        }
        printf("%s",str);
        printf("%d\n",all[j][0]);
        j++;
    }

    for(int i = 0;i<j;i++)
    {
        for(int k = i;k<j;k++)
        {

        }
    }
}
