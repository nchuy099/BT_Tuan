#include<iostream>
#include<random>
#include<time.h>
using namespace std;

int main()
{
    srand(time(0));
    int t;
    cout<<"Nhap so lan choi: ";
    cin>>t;
    int cnt = 0;
    while(t--)
    {
        int a,b;
        a = 0 + rand() % (100 - 0 + 1);
        b = 0 + rand() % (100 - 0 + 1);
        cout<<"Chon xem the:\n 1. The a\n 2. The b"<<endl;
        int c;
        c = 1 + rand() % (2 - 1 + 1);
        int c2;
        switch(c){
        case 1:
            cout<<a<<endl;
            if(a>50)    c2 = 1;
            else        c2 = 2;
            break;
        case 2:
            cout<<b<<endl;
            if(b>50)    c2 = 2;
            else        c2 = 1;
            break;
        }
        cout<<"Hay doan the lon hon \n 1. The a \n 2. The b"<<endl;
        switch(c2){
        case 1:
            if(a>b)
            {
                cout<<"Doan dung"<<endl, cout<<a<<" "<<b<<endl;
                cnt++;
            }
            else    cout<<"Doan sai"<<endl, cout<<a<<" "<<b<<endl;
            break;
        case 2:
            if(b>a)
            {
                cout<<"Doan dung"<<endl, cout<<a<<" "<<b<<endl;
                cnt++;
            }
            else    cout<<"Doan sai"<<endl, cout<<a<<" "<<b<<endl;
            break;
        }
    }
    cout<<"so lan doan dung: "<<cnt<<"\n------------------\n";
    return 0;
}
