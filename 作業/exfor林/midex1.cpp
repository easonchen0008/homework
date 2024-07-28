#include <iostream>
#include <math.h>
#include <string>
#define N 100
using namespace std;

class student{
    public:
    string firstname[N];
    string lastname[N];
    string phonenumber[N];
    string id[N];
    string password[N];
    int age[N];
}s;

bool Checkpassword(string a,string ID)
{

    for(int i = 0 ;i<N;i++)
    {
        if(s.id[i]==ID)
        {
            if (s.password[i]==a)
            {
                return 1;
            }else
            return 0;
        }
    }
}
void setfirstname(string a,int indx)
{
    s.firstname[indx]=a;
}
void setlastname(string a,int indx)
{
    s.lastname[indx]=a;
}
void setphonenumber(string a,int indx)
{
    s.phonenumber[indx]=a;
}
void setid(string a,int indx)
{
    s.id[indx]=a;
}
void setpassword(string a,int indx)
{
    s.password[indx]=a;
}
void setage(int a,int indx)
{
    s.age[indx]=a;
}

string getphonenumber(string id)
{
    for(int i = 0 ;i<N;i++)
    {
        if(s.id[i]==id)
        {
            return s.phonenumber[i];
        }
    }
    return 0;
}

string getlastname(string id)
{
    for(int i = 0 ;i<N;i++)
    {
        if(s.id[i]==id)
        {
            return s.lastname[i];
        }
    }
    return 0;
}

int getage(string id)
{
    for(int i = 0 ;i<N;i++)
    {
        if(s.id[i]==id)
        {
            return s.age[i];
        }
    }
    return 0;
}

int main(){
    //建構資料
    int meber=3;
    string firstname[meber]={"wo","ao","co"};
    string lastname[meber]={"chen","won","lin"};
    string phonenumber[meber]={"0978090778","0966777888","0954878787"};
    string id[meber]={"410721212","410821212","410921212"};
    string password[meber]={"123","456","789"};
    int age[meber] = {21,20,19};
    for(int i = 0;i<meber;i++)
    {
        setfirstname(firstname[i],i);
        setlastname(lastname[i],i);
        setphonenumber(phonenumber[i],i);
        setid(id[i],i);
        setpassword(password[i],i);
        setage(age[i],i);
    }

    //開始執行
    string ID,Password;
    cout<<"Hi Mr."<<endl;
    cout<<"Login first"<<endl<<endl;
    cout<<"Input your ID"<<endl;
    cout<<"ID: ";
    cin>>ID;
    cout<<endl<<"Nice to meet you. Mr."<<getlastname(ID)<<endl;
    cout<<"Input your Password."<<endl;
    cout<<"Password: ";
    cin>>Password;
    if(Checkpassword(Password,ID))
    {
        cout<<"Pass"<<endl;
    }else
    cout<<"Sorry, your password is worng！"<<endl;
}
