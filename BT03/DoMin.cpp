#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int a[100][100];
    for(int i = 0; i < m + 2; i++)
    {
        for(int j = 0; j < n + 2; j++)
        {
            if(i!= 0 && j !=0 && i != m+1 && j != n+1)
            {
                char c;
                cin>>c;
                if(c == '*')    a[i][j] = 1;
                else            a[i][j] = 0;
            }
            else    a[i][j] = 0;
        }
    }
    int b[100][100];
    for(int i = 1; i <= m ;i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(a[i][j] != 1)
            {
                b[i-1][j-1] = a[i-1][j-1] + a[i-1][j] + a[i-1][j+1]
                            + a[i][j-1] + a[i][j] + a[i][j+1]
                            + a[i+1][j-1]+ a[i+1][j] + a[i+1][j+1];
            }
            else b[i-1][j-1] = -1;
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(b[i][j] == -1)   cout<<"* ";
            else                cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
