#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;

const string WORD_LIST[]= {
        "angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house", "island", "jewel",  "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
        "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
    };
const int WORD_COUNT = sizeof(WORD_LIST)/sizeof(string);
const string FIGURE[]={
         "   -------------    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |           |    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          /     \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          / \\  \n"
         "   |     \n"
         " -----   \n",
};
char readAGuess();
string chooseWord();
bool contains(string &secretWord, char &guess);
string update(string &guessedWord,string &secretWord,char &guess);
void renderGame(string &guessedWord, int &badGuessCount,int &hints);
char aAlpha(string &secretWord,string &guessedWord);
bool chooseHint(int &hints);
int main()
{
    srand((int)time(0));
    string secretWord = chooseWord();
    string guessedWord = string(secretWord.size(),'_');
    int badGuessCount = 0 ;
    const int MAX_BAD_GUESSED = 7;
    int hints = 0;
    char guess;
    do
    {
        renderGame(guessedWord, badGuessCount,hints);
        if(chooseHint(hints)&& badGuessCount<MAX_BAD_GUESSED-1)
        {
            guess=aAlpha(secretWord,guessedWord);
            update(guessedWord, secretWord,guess);
            hints--;
            continue;
        }
        guess = readAGuess();
        if(contains(secretWord, guess))
        {
            guessedWord = update(guessedWord, secretWord,guess);
            hints++;
        }
        else    badGuessCount++;

    }while(badGuessCount < 7 && secretWord != guessedWord);
    renderGame(guessedWord, badGuessCount,hints);
    if(badGuessCount < MAX_BAD_GUESSED ) cout<<"Congratulations! You win!";
    else    cout<<"You lost. The correct word is "<<secretWord;
}
char aAlpha(string &secretWord,string &guessedWord)
{
    for(int i=0;i<secretWord.size();i++)
    {
        if(secretWord[i]!='_'&&guessedWord[i]=='_')  return secretWord[i];
    }
    return '!';
}
bool chooseHint(int &hints)
{
    if(hints==0)    return false;
    int choice=1;
    while(choice==1)
    {
        cout<<"Want a hint?\n1.Yes\n2.No"<<endl;
        cin>>choice;
        if(choice==1)   return true;
    }
    return false;
}
string chooseWord()
{
    int randomIndex = rand()%WORD_COUNT;
    return WORD_LIST[randomIndex];
}
void renderGame(string &guessedWord, int &badGuessCount,int &hints)
{
    cout<<FIGURE[badGuessCount]<<endl;
    cout<<guessedWord<<endl;
    cout<<"Hints: "<<hints<<endl;
}

bool contains(string &secretWord,char &guess)
{
    for(int i=0;i<secretWord.size();i++)
    {
        if(secretWord[i]==guess)    return true;
    }
    return false;
}

string update(string &guessedWord,string &secretWord,char &guess)
{
    for(int i=0;i<secretWord.size();i++)
    {
        if(secretWord[i]==guess)    guessedWord[i]=guess;
    }
    return guessedWord;
}

char readAGuess()
{
    cout<<"Guess an alphabet: "<<endl;
    char c;
    cin>>c;
    return c;
}
