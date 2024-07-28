#include <stdio.h>
#include <stdlib.h>
struct day
{
 int yy, mm, dd; /* 年、月、日 */
};
struct data
{
 char name[20]; /* 姓名 */
 char classNo; /* 班別 */
 struct day birthday; /* 生日 */
 int math, eng; /* 數學 與 英文成績 */
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
