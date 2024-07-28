
#include<iostream>
#include<string>
#include<array>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<cstdlib>
using namespace std;
#define N 100
class myNormal
{
public:
    myNormal(double mean,double sigma)
    {
        m=mean;
        s=sigma;
    }
    double getmean();
    double getsigma();
    double getpdf(double x);
    void setmaen(double mean)
    {
        m=mean;
    }
    void setsigma(double sigma)
    {
        s=sigma;
    }
private:
    double m=0;
    double s=1;
};
double myNormal::getmean()
{
    return m;
}
double myNormal::getsigma()
{
    return s;
}
double myNormal::getpdf(double x)
{
    return exp((-pow(x-m,2))/(2*pow(s,2)))*1/(s*sqrt (6.2831852));
}

myNormal A(-2,sqrt(0.5));
myNormal B(0,sqrt(0.2));
myNormal C(5,1);
int frequency(int index,int arr[100])
{
    int total=0;
    for(int i=0; i<100; i++)
    {
        if(arr[i]==index)
            total++;
    }
    return total;
}

int classify(double x,double y,double z)
{
    if(x>y&x>z)
    {
        return 1;
    }
    else if(y>x&y>z)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

int main()
{
    ifstream fin;
    ofstream outfin;
    int ans[N];
    double num[N];
    //input
    fin.open("normaldata3.txt");
    if(!fin)
    {
        cout<<"open normaldata3.txt error"<<endl;
        return 0;
    }
    for(int i=0; i<N; i++)
    {
        fin >> num[i];
    }
    //ororiginal
    cout<<"normaldata3 is"<<endl;
    for(int i=0; i<N; i++)
    {
        cout<<setprecision(4)<<fixed<<num[i]<<"\t";
    }
    //classify
    cout<<endl<<endl<<"classify"<<endl;
    //cout<<"test "<<A.getpdf(1.65)<<"  "<<B.getpdf(1.65)<<" "<<C.getpdf(1.65)<<endl;
    for(int i=0; i<N; i++)
    {
        double X = A.getpdf(num[i]);
        double Y = B.getpdf(num[i]);
        double Z = C.getpdf(num[i]);
        ans[i] = classify(X,Y,Z);
        //cout<<"X = "<<X<<"Y =  "<<Y<<"Z =  "<<Z<<" " ;
        cout<<ans[i]<<"       ";
    }
    //frequency
    cout<<endl<<endl<<"frequency"<<endl;
    cout<<"class 1: "<<frequency(1,ans)<<"      class 2: "<<frequency(2,ans)<<"        class 3: "<<frequency(3,ans)<<endl;
}
