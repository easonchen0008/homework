#include <iostream>
#define N 100
using namespace std;

int main(){
    int n,k;
    cout<<"intput n & k for n choose k :"<<endl;
    cin>>n>>k;
    int arrn[N]={1},arrk[N]={1},temp;
    //��n�����O���U��
    if(k>=n-k)
        temp=k;
    else
        temp=n-k;

        int j =0;
        for(int i = n ;i>temp;i--,j++)
        {
            arrn[j]=i;
            arrk[j]=n-temp-j;
        }
    cout<<"�Q����"<<endl;
    for(int i = 0;i<n-temp;i++)
    {
        cout<<arrn[i]<<" ";
    }
    cout<<endl<<"����"<<endl;;
    for(int i = 0;i<n-temp;i++)
    {
        cout<<arrk[i]<<" ";
    }
    cout<<endl<<endl;
    for(int i = 0;i<n-temp;i++)
    {
        for(int j = 0;j<n-temp;j++)
        {
            if(arrn[i] % arrk[j] ==0 && arrk[j]!=1)
            {
                arrn[i]/=arrk[j];
                arrk[j]=1;
            }
        }
    }
    cout<<"���˹L��"<<endl;
    cout<<"�Q����"<<endl;
    for(int i = 0;i<n-temp;i++)
    {
        cout<<arrn[i]<<" ";
    }
    cout<<endl<<"����"<<endl;;
    for(int i = 0;i<n-temp;i++)
    {
        cout<<arrk[i]<<" ";
    }
    cout<<endl;
    long long int ans=1 ,bns=1;
    for(int i = 0;i<n-temp;i++)
    {
        ans*=arrn[i];
        bns*=arrk[i];
    }
    ans=ans/bns;
    cout<<"Combinations without repetition is :"<<ans;
}
