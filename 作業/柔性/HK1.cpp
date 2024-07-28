#include <iostream>

using namespace std;

int main()
{
    int N_A,N_B;
    cout << "Enter the number of rows and columns in interval matrices [A] and [B] " << endl;
    cin >> N_A >> N_B;
    double AUP[N_A][N_A],ADOW[N_A][N_A];
    double BUP[N_B][N_B],BDOW[N_B][N_B];
    int i,j,k;
    cout << "Enter the lower (Al) bound of first interval matrix [A]:" << endl;
    for(i= 0;i<N_A;i++)
    {
        for(j = 0;j<N_A;j++)
        {
            cin >> AUP[i][j];
        }
    }
    cout << "Enter the upper (Au) bound of first interval matrix [A]:" << endl;
    for(i= 0;i<N_A;i++)
    {
        for(j= 0;j<N_A;j++)
        {
            cin >> ADOW[i][j];
        }
    }
    cout << "Enter the lower (Bl) bound of second interval matrix [B]:"<< endl;
    for(i= 0;i<N_B;i++)
    {
        for(j= 0;j<N_B;j++)
        {
            cin >> BUP[i][j];
        }
    }
    cout << "Enter the upper (Bu) bound of second interval matrix [B]:" << endl;
    for(i= 0;i<N_B;i++)
    {
        for(j= 0;j<N_B;j++)
        {
            cin >> BDOW[i][j];
        }
    }
    cout<<"The addition of two interval matrices [A] and [B] is [C]=[A]+[B]: "<<endl;
    double CUP[N_A][N_B] , CDOW[N_A][N_B];
    for(i= 0;i<N_A;i++)
    {
        for(j= 0;j<N_B;j++)
        {
            for(k = 0 ; k < N_B ; k++)
            {
                CUP[i][j] += AUP[i][k] * BUP[k][j];
                CDOW[i][j] += ADOW[i][k] * BDOW[k][j];
            }
            cout<<"[" <<CUP[i][j]<<" , "<<CDOW[i][j]<< "] ";
        }
        cout<<endl;
    }
    return 0;
}
