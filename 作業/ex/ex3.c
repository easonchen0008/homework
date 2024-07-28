#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j] > arr[i]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
  double c;
    for(int i =3;i<n-3;i++)
    {
        c+=arr[i];
    }
    c/=(n-6);
    printf("%.2f",c);
}
