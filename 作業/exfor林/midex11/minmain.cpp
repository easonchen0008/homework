#include "midex1.cpp"
# include <iostream>
# include <string>
# define N 100
using namespace std;
int main(){
    student s;
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

    cout<<"dddd"<<s.age[0]<<endl;;
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
