#include <iostream>
#include <string>
using namespace std;

int main()
{
    while(1)
    {
        string a;
    cin >>a;
    int c=0;
    for(int i = 0 ; i < a.size();i++)
    {
        for(int j=1 ; j<27 ; j++)
        {
            if(a[i]== char('a'+j-1) ||a[i]== char('A'+j-1))
            {
                c+=j;
                //cout<<c<<endl;
            }
        }

    }
    cout<<a<<endl<<c;
    }


}
