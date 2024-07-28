
#include"midex1.h"

int Checkpassword(string a,string ID)
{
    student s;
    for(int i = 0 ;i<N;i++)
    {
        if((s.id)[i]==ID)
        {
            if (s.password[i]==a)
            {
                return 1;
            }else
            return 0;
        }
    }
}
void setfirstname(student s,int indx)
{
    s.firstname[indx]=a;
}
void setlastname(string a,int indx)
{
    student s;
    s.lastname[indx]=a;
}
void setphonenumber(string a,int indx)
{
    student s;
    s.phonenumber[indx]=a;
}
void setid(string a,int indx)
{
    student s;
    s.id[indx]=a;
}
void setpassword(string a,int indx)
{
    student s;
    s.password[indx]=a;
}
void setage(int a,int indx)
{
    student s;
    s.age[indx]=a;
}

string getphonenumber(string id)
{
    student s;
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
    student s;
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
    student s;
    for(int i = 0 ;i<N;i++)
    {
        if(s.id[i]==id)
        {
            return s.age[i];
        }
    }
    return 0;
}

