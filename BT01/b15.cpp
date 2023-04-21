#include<iostream>
using namespace std;

string f[10];
void fibonacci()
{
    f[0] = "a";
    f[1] = "b";
    cout<<f[0]<<endl<<f[1]<<endl;
    for(int i=2;i<=10;i++)
    {
        f[i] = f[i-1]+ f[i-2];
        cout<<f[i]<<endl;
    }
}
int main()
{
    fibonacci();
    return 0;
}
