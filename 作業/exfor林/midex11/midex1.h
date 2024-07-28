# ifndef _STATIC_LIB_H_
# define _STATIC_LIB_H_
# include <iostream>
# include <string>
# define N 100
using namespace std;
 class student {
public:
    string firstname[N];
    string lastname[N];
    string phonenumber[N];
    string id[N];
    string password[N];
    int age[N];
       } ;


int Checkpassword(student s, string ID);

void setfirstname(string a,int indx);

void setlastname(string a,int indx);

void setphonenumber(string a,int indx);

void setid(string a,int indx);

void setpassword(string a,int indx);

void setage(int a,int indx);


string getphonenumber(string id);


string getlastname(string id);


int getage(string id);


//int treeEqual(Node_t *root1,Node_t *root2,int (*compare)(void *element,void *element2));

#endif
