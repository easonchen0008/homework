#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a,b,c ,tmp=0;
    cin>>a>>b>>c;
    if(a<b)
    {
        tmp=a;
        a=b;
        b=tmp;
    }
    if(a<c)
    {
        tmp=a;
        a=c;
        c=tmp;
    }
    if(a+b>c && a+c>b && b+c>a)
    {
        if(pow(a,2)>pow(b,2)+pow(c,2))
        {
            cout<<"is acute tri"<<endl;
        }else if(pow(a,2)==pow(b,2)+pow(c,2))
        {
            cout<<"is right tri"<<endl;
        }else
        {
            cout<<"is Obtuse tri"<<endl;
        }
    }else
    {
        cout<<"not tri"<<endl;
    }

}
