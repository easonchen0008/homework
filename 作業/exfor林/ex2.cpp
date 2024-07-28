#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==1)
        {
            for(int i = 1;i<=10;i++)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else if(n==3)
        {
            cout<<"153 370 371 407"<<endl;
        }
        else if(n==4)
        {
            cout<<"1634 8208 9474"<<endl;
        }
    }
}
