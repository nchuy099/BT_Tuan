#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    cout<<fixed<<setprecision(2)<<sqrt(x*x+y*y);
    return 0;
}
