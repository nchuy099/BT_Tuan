#include<iostream>
using namespace std;

int main()
{
    cout<<"Nhap so nguyen duong le: "<<endl;
    int n;
    do
    {
        cin>>n;
    }while(n<=0 || n%2==0);
    int a[100][100];
    bool mark[100][100];
    for(int i = 0; i<n;i++)
    {
        for(int j = 0;j <n;j++) mark[i][j] = false;
    }
    int cnt = 1;
    int i = 0;
    int j = n/2;
    while(cnt<=n*n)
    {
        if(mark[i][j] == false)
        {
            a[i][j] = cnt;
            mark[i][j] = true;
        }
        else
        {
            i++;
            j--;
            if(j<0)     j = n-1;
            if(i>n-1)   i = 0;
            i++;
            a[i][j] = cnt;
            mark[i][j] = true;
        }
        i--;
        j++;
        if(i<0)     i = n-1;
        if(j>n-1)   j = 0;
        cnt++;
    }
    for(int i = 0; i<n;i++)
    {
        for(int j = 0;j<n;j++)  cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
