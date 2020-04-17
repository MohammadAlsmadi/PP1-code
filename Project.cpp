#include<iostream>
#include <cstdlib>
//To define maximum player
#define MAX 11
using namespace std;
//Class MyGame definition
class MyGame
{
//Data member declaration
string playerName[MAX];
int playerPoint[MAX];
public:
int playerCount;
//Accept number of players and player name
void accept()
{
//Accepts number of players
cout<<"\n Enter how many players (must be less than 10): ";
cin>>playerCount;
//Loops till number of players and accept name
for(int x = 0; x < playerCount; x++)
{
cout<<"\n Enter player "<<(x + 1)<<" name: ";
cin>>playerName[x];
playerPoint[x] = 0;
}//End of loop
}//End of function

//Roll Dice for player number specified
void rollDice(int pno)
{
//For dice1 and dice2
int d1, d2;
//For choice
char ch;
//Displays the name of the player for rolling
cout<<endl<<playerName[pno]<<" rolls "<<endl;
//Loops till player score is greater than 100 or dice1 and dice2 is one
do
{
//Roll dice1
d1 = (rand()%6)+1;
//Roll dice2
d2 = (rand()%6)+1;
//Displays dice1 and dice 2 value
cout<<"\n Dice1 = "<<d1<<"\t Dice2 = "<<d2;
//Checks if Dice1 and Dice2 value is one then break
if(d1 == 1 && d2 == 1)
{
break;
}//End of if
//Otherwise add dice1 and dice2 value and add it with previous playerPoint value
else
playerPoint[pno] += (d1 + d2);
//Checks if playerPoint is greater than 100 then display the name of player won with points
if(playerPoint[pno] >= 100)
{
cout<<"\n Player "<<playerName[pno]<<" won the game: "<<playerPoint[pno];
exit(0);
}//End of if
//Accept data for holding
cout<<"\n Do you want to hold: (y / n)";
cin>>ch;
//If choice is y then break
if(ch == 'Y' || ch == 'y')
{
break;
}//End of if
//Displays the player name and current player point after each roll
cout<<"\n Player "<<playerName[pno]<<" "<<playerPoint[pno];
}while(1);
}//End of function
};//End of class

//Main function
int main()
{
//Class object created
MyGame mg;
//Accepts number of players with their name
mg.accept();
int x = 0;
//Loops till players score is greater than 100
do
{
mg.rollDice(x);
x++;
if(x == mg.playerCount)
x = 0;
}while(1);
}//End of main

