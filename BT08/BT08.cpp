#include <iostream>
using namespace std;

int getStrlen(char a[])
{
    int n=0;
    while(a[n]!='\0')
    {
        n++;
    }
    return n;
}
void reverse(char a[])
{
    int r = getStrlen(a) - 1;
    int l =0;
    while(l<r)
    {
        swap(a[l],a[r]);
        l++;
        r--;
    }
}

void delete_char(char a[], char c)
{
    int charLeng = getStrlen(a);
    for(int i = 0; i < charLeng; i++)
    {
        if(a[i] == c)
        {
            charLeng --;
            for(int j = i; j < charLeng; j++)
            {

                a[j] = a[j+1];
            }
        }
    }
    a[charLeng] = '\0';
}

void pad_right(char a[], int n)
{
    int charLeng = getStrlen(a);
    if(charLeng < n)
    {
        while(charLeng < n)
        {
            a[charLeng++] = '_';
        }
    }
}

void pad_left(char a[], int n)
{
    reverse(a);
    pad_right(a,n);
    reverse(a);
}

void truncate(char a[], int n)
{
    int charLeng = getStrlen(a);
    if(charLeng > n)
    {
        a[n]='\0';
    }
}

bool is_palindrome(char a[])
{
    int l = 0;
    int r = getStrlen(a) - 1;
    while(l < r)
    {
        if(a[l] != a[r])    return false;
        l++;
        r--;
    }
    return true;
}

void trim_left(char a[])
{
    reverse(a);
    int charLeng = getStrlen(a);
    int last = charLeng - 1;
    while(a[last] == '_')
    {
        a[last--] = '\0';
    }
    reverse(a);
}

void trim_right(char a[])
{
    int last = getStrlen(a) - 1;
    while(a[last] == '_')
    {
        a[last--] = '\0';
    }
}
int main()
{
    char a[100];
    cin>>a;
    cout<<a<<endl;
    trim_right(a);
    cout<<a<<'.';
    return 0;
}
