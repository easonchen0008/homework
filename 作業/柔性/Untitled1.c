#include <stdio.h>
#define size 10

float getmin(float a, float b)
{
    if (a > b)
        return b;
    return a;
};

float getmax(float a, float b)
{
    if (a > b)
        return a;
    return b;
};

int main()
{
    int n;
    float A1[2][size], A2[2][size];
    float B[2][size];

    printf("enter the number of elements in set A1 and A2\n");
    scanf("%d", &n);

    printf("enter the elements on fuzzy set A1\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &A1[0][i]);

    printf("enter the corresponding membership values in A1\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &A1[1][i]);

    printf("enter the elements on fuzzy set A2\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &A2[0][i]);

    printf("enter the corresponding membership values in A2\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &A2[1][i]);

    int number_of_b = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            float tmp_e = A1[0][i] * A1[0][i] + A2[0][j] * A2[0][j];
            float tmp_c = getmin(A1[1][i], A2[1][j]);
            if (number_of_b != 0)
            {
                int k = 0;
                for (; k < number_of_b; k++)
                {
                    if (B[0][k] == tmp_e)
                    {
                        B[1][k] = getmax(B[1][k], tmp_c);
                        break;
                    }
                }
                if (k == number_of_b)
                {
                    B[0][k] = tmp_e;
                    B[1][k] = tmp_c;
                    number_of_b++;
                }
            }
            else
            {
                B[0][number_of_b] = tmp_e;
                B[1][number_of_b] = tmp_c;
                number_of_b++;
            }
        }
    }

    for (int i = 0; i < number_of_b; i++)
        for (int j = i + 1; j < number_of_b; j++)
            if (B[0][i] > B[0][j])
            {
                float tmp1 = B[0][i], tmp2 = B[1][i];
                B[0][i] = B[0][j];
                B[1][i] = B[1][j];
                B[0][j] = tmp1;
                B[1][j] = tmp2;
            }

    for (int i = 0; i < number_of_b; i++)
        printf("y: %.2f B(y): %.4f\n", B[0][i], B[1][i]);

    return 0;
}
