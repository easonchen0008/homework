#include <iostream>

using namespace std;
int main()
{

    int n,i;
    cout<<"input N"<<endl;
    cin>>n;
    float A1[2][10], A2[2][10];
    float B[2][10];
    cout<<"input A1[0][i]"<<endl;
    for(i=0;i<n;i++)
        cin>>A1[0][i];
    cout<<"input A1[1][i]"<<endl;
    for(i=0;i<n;i++)
        cin>>A1[1][i];
    cout<<"input A2[0][i]"<<endl;
    for(i=0;i<n;i++)
        cin>>A2[0][i];
    cout<<"input A2[1][i]"<<endl;
    for(i=0;i<n;i++)
        cin>>A2[1][i];
    int num=0,j;
    for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                float tmp = A1[0][i] * A1[0][i] + A2[0][j] * A2[0][j];
                float tmp2 = min(A1[1][i], A2[1][j]);
                if (num != 0)
            {
                int k = 0;
                for (; k < num; k++)
                {
                    if (B[0][k] == tmp)
                    {
                        B[1][k] = max(B[1][k], tmp2);
                        break;
                    }
                }
                if (k == num)
                {
                    B[0][k] = tmp;
                    B[1][k] = tmp2;
                    num++;
                }
            }
            else
            {
                B[0][num] = tmp;
                B[1][num] = tmp2;
                num++;
            }
            }
        }

    for (int i = 0; i < num; i++)
        for (int j = i + 1; j < num; j++)
            if (B[0][i] > B[0][j])
            {
                float temp = B[0][i], temp2 = B[1][i];
                B[0][i] = B[0][j];
                B[1][i] = B[1][j];
                B[0][j] = temp;
                B[1][j] = temp2;
            }
    cout<<"B=";
    for(i=0;i<num;i++)
    {
        cout<<"( "<<B[0][i]<<" , "<<B[1][i]<<" ) ";
    }
}
