#include<iostream>
using namespace std;

int main()
{
    int a1,a2,a3,a4,a5;
    cin>>a1>>a2>>a3>>a4>>a5;
    double averg = (a1 + a2 + a3 + a4 + a5) / 5;
    double d1 = abs(a1 - averg);
    double d2 = abs(a2 - averg);
    double d3 = abs(a3 - averg);
    double d4 = abs(a4 - averg);
    double d5 = abs(a5 - averg);
    double temp = d1;
    int res = a1;
    if(d2 < temp) temp = d2, res = a2;
    if(d3 < temp) temp = d3, res = a3;
    if(d4 < temp) temp = d4, res = a4;
    if(d5 < temp) temp = d5, res = a5;
    cout<<res<<endl;

}
