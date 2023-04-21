#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


int init()
{
    int n = rand();
    return n;
}

int readAGuess()
{
    int guess;
    cin>>guess;
    return guess;
}

bool gameOver(int number, int guessed)
{
    return number==guessed;
}
void displayResult()
{
    cout<<"end"<<endl;
}

void process(int number, int guessed)
{
    if(guessed<number)  cout<<"too small"<<endl;
    else if(guessed>number) cout<<"too big"<<endl;
    else                    cout<<"you won"<<endl;
}

int main()
{
    srand(time(0));
    //phac thao chuong trinh
    int number=init();
    int guessed;
    do {
        guessed = readAGuess();
        process(number,guessed);
    }while(!gameOver(number,guessed));
}
