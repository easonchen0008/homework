#include <iostream>
#include <random>
#include <math.h>
using namespace std;
int main(){
    random_device rd;
    mt19937 generator( rd() );

  /* �зǱ`�A���� */
    normal_distribution<double> norm(5, sqrt(3));

  /* ���ͼзǱ`�A�������ü� */
  double arr[300],sum=0,biao =0;
  for (int i=0; i < 300; ++i) {
  double x = norm(generator);
    cout << "x = " << x <<endl;
    arr[i]=x;
    sum+=x;
  }
  sum/=300;
  for (int i=0; i < 300; ++i) {
      biao+=pow(arr[i]-sum,2);
      cout<<biao<<endl;
  }
  biao=sqrt(biao);
    cout<<"sum ="<<sum<<"  biao ="<<biao<<endl;
}
