#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[999],c[999];
    scanf("%s",&name);
    int flag,len;
    flag = 1;
    len = strlen(name);
    for(int i =0;i<len;i++)
    {
        if(name[i]>=65 && name[i]<=90)
            {
                c[i]=name[i]+32;
            }
            else
            {
                c[i]=name[i];
            }
    }
		for(int i = 0; i < len/2; i ++)
		{

			if(c[i] != c[len - 1 -i])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("%s is a palindrome",name);
		else
			printf("%s is not a palindrome",name);

}
