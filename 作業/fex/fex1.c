#include <stdio.h>

void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j] > arr[i]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
}
int main()
{
    int n;
    scanf("%d", &n);
    int sc,mi=-1,mx=101;
    int arr[100];
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &sc);
        arr[i]=sc;
        if(sc<60)
        {
            if(sc>mi)
            {
                mi = sc;
            }
        }
        else
        {
            if(sc<mx)
            {
                mx = sc;
            }
        }
    }
    bubble_sort(arr,n);
    for(int i = 0; i<n; i++)
    {
        printf("%d", arr[i]);
        if(i!=n-1)
            printf(" ");
    }
    printf("\n");
    if(mi != -1)
    {
        printf("%d\n", mi);
        if(mx != 101)
        {
            printf("%d\n", mx);
        }
        else
        {
            printf("worst case\n");
        }
    }
    else
    {
        printf("best case\n");
    }

}
