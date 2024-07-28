#include <iostream>

using namespace std;

int main()
{
    long long int n;
    int num=0,sum=0;
    cin>>n;
    for(int i=1 ;i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
            num++;
            sum+=i;
        }
    }
    cout<<"num "<<num<<" sum "<<sum<<endl;
    return 0;
}
