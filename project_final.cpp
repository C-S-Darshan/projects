#include<iostream>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include<stdio.h> 
#include<string.h> 
#include <iomanip>
using namespace std;

struct score{
	int winCount;
	char name[20];
};

class tictactoe{	
protected:
	int position;
	int j,k; 
	char player1[20];
	char player2[20];	
	char arr[9];
	int exit,d;	
	int a;
public:
	tictactoe(){
		arr[0]='1';
		arr[1]='2';
		arr[2]='3';
		arr[3]='4';
		arr[4]='5';
		arr[5]='6';
		arr[6]='7';
		arr[7]='8';
		arr[8]='9';
		a=9;
	}	
	void r1(){
		cout<<"\t\t   |   |   \n";
		cout<<"\t\t-"<<arr[0]<<"-|-"<<arr[1]<<"-|-"<<arr[2]<<"-\n";
		cout<<"\t\t___|___|___\n";
		cout<<"\t\t   |   |   \n";
		cout<<"\t\t "<<arr[3]<<" | "<<arr[4]<<" | "<<arr[5]<<" \n";
		cout<<"\t\t___|___|___\n";
		cout<<"\t\t   |   |   \n";
		cout<<"\t\t "<<arr[6]<<" | "<<arr[7]<<" | "<<arr[8]<<" \n";
		cout<<"\t\t   |   |   \n";
	}

	void r2(){
		cout<<"\t\t   |   |   \n";
		cout<<"\t\t "<<arr[0]<<" | "<<arr[1]<<" | "<<arr[2]<<" \n";
		cout<<"\t\t___|___|___\n";
		cout<<"\t\t   |   |   \n";
		cout<<"\t\t-"<<arr[3]<<"-|-"<<arr[4]<<"-|-"<<arr[5]<<"-\n";
		cout<<"\t\t___|___|___\n";
		cout<<"\t\t   |   |   \n";
		cout<<"\t\t "<<arr[6]<<" | "<<arr[7]<<" | "<<arr[8]<<" \n";
		cout<<"\t\t   |   |   \n";
	}

	void r3(){
		cout<<"\t\t   |   |   \n";
		cout<<"\t\t "<<arr[0]<<" | "<<arr[1]<<" | "<<arr[2]<<" \n";
		cout<<"\t\t___|___|___\n";
		cout<<"\t\t   |   |   \n";
		cout<<"\t\t "<<arr[3]<<" | "<<arr[4]<<" | "<<arr[5]<<" \n";
		cout<<"\t\t___|___|___\n";
		cout<<"\t\t   |   |   \n";
		cout<<"\t\t-"<<arr[6]<<"-|-"<<arr[7]<<"-|-"<<arr[8]<<"-\n";
		cout<<"\t\t   |   |   \n";
	}

	void c1(){
		cout<<"\t\t | |   |   \n";
		cout<<"\t\t "<<arr[0]<<" | "<<arr[1]<<" | "<<arr[2]<<" \n";
		cout<<"\t\t_|_|___|___\n";
		cout<<"\t\t | |   |   \n";
		cout<<"\t\t "<<arr[3]<<" | "<<arr[4]<<" | "<<arr[5]<<" \n";
		cout<<"\t\t_|_|___|___\n";
		cout<<"\t\t | |   |   \n";
		cout<<"\t\t "<<arr[6]<<" | "<<arr[7]<<" | "<<arr[8]<<" \n";
		cout<<"\t\t | |   |   \n";
	}

	void c2(){
		cout<<"\t\t   | | |   \n";
		cout<<"\t\t "<<arr[0]<<" | "<<arr[1]<<" | "<<arr[2]<<" \n";
		cout<<"\t\t___|_|_|___\n";
		cout<<"\t\t   | | |   \n";
		cout<<"\t\t "<<arr[3]<<" | "<<arr[4]<<" | "<<arr[5]<<" \n";
		cout<<"\t\t___|_|_|___\n";
		cout<<"\t\t   | | |   \n";
		cout<<"\t\t "<<arr[6]<<" | "<<arr[7]<<" | "<<arr[8]<<" \n";
		cout<<"\t\t   | | |   \n";
	}

	void c3(){
		cout<<"\t\t   |   | | \n";
		cout<<"\t\t "<<arr[0]<<" | "<<arr[1]<<" | "<<arr[2]<<" \n";
		cout<<"\t\t___|___|_|_\n";
		cout<<"\t\t   |   | | \n";
		cout<<"\t\t "<<arr[3]<<" | "<<arr[4]<<" | "<<arr[5]<<" \n";
		cout<<"\t\t___|___|_|_\n";
		cout<<"\t\t   |   | | \n";
		cout<<"\t\t "<<arr[6]<<" | "<<arr[7]<<" | "<<arr[8]<<" \n";
		cout<<"\t\t   |   | | \n";
	}

	void d1(){
		cout<<"\t\t\\  |   |   \n";
		cout<<"\t\t "<<arr[0]<<" | "<<arr[1]<<" | "<<arr[2]<<" \n";
		cout<<"\t\t__\\|___|___\n";
		cout<<"\t\t   |\\  |   \n";
		cout<<"\t\t "<<arr[3]<<" | "<<arr[4]<<" | "<<arr[5]<<" \n";
		cout<<"\t\t___|__\\|___\n";
		cout<<"\t\t   |   |\\  \n";
		cout<<"\t\t "<<arr[6]<<" | "<<arr[7]<<" | "<<arr[8]<<" \n";
		cout<<"\t\t   |   |  \\ \n";
	}

	void d2(){
		cout<<"\t\t   |   |  /\n";
		cout<<"\t\t "<<arr[0]<<" | "<<arr[1]<<" | "<<arr[2]<<" \n";
		cout<<"\t\t___|___|/__\n";
		cout<<"\t\t   |  /|   \n";
		cout<<"\t\t "<<arr[3]<<" | "<<arr[4]<<" | "<<arr[5]<<" \n";
		cout<<"\t\t___|/__|___\n";
		cout<<"\t\t  /|   |   \n";
		cout<<"\t\t "<<arr[6]<<" | "<<arr[7]<<" | "<<arr[8]<<" \n";
		cout<<"\t\t/  |   |   \n";
	}

	//the function winner decides who won the game by comparing values of each element

	int winner(){

		if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == 'X')
			return 1;
		else if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == 'O')
			return 2;
		else if (arr[3] == arr[4] && arr[4] == arr[5] && arr[5] == 'X')
			return 3;
		else if (arr[3] == arr[4] && arr[4] == arr[5] && arr[5] == 'O')
			return 4;
		else if (arr[6] == arr[7] && arr[7] == arr[8] && arr[8] == 'X')
			return 5;
		else if (arr[6] == arr[7] && arr[7] == arr[8] && arr[8] == 'O')
			return 6;
		else if (arr[0] == arr[3] && arr[3] == arr[6] && arr[6] == 'X')
			return 7;
		else if (arr[0] == arr[3] && arr[3] == arr[6] && arr[6] == 'O')
			return 8;
		else if (arr[1] == arr[4] && arr[4] == arr[7] && arr[7] == 'X')
			return 9;
		else if (arr[1] == arr[4] && arr[4] == arr[7] && arr[7] == 'O')
			return 10;
		else if (arr[2] == arr[5] && arr[5] == arr[8] && arr[8] == 'X')
			return 11;
		else if (arr[2] == arr[5] && arr[5] == arr[8] && arr[8] == 'O')
			return 12;
		else if (arr[0] == arr[4] && arr[4] == arr[8] && arr[8] == 'X')
			return 13;
		else if (arr[0] == arr[4] && arr[4] == arr[8] && arr[8] == 'O')
			return 14;
		else if (arr[2] == arr[4] && arr[4] == arr[6] && arr[6] == 'X')
			return 15;
		else if (arr[2] == arr[4] && arr[4] == arr[6] && arr[6] == 'O')
			return 16;
		else
			return 0;
	}

	//the function gamestat decides when the game should terminate usually this happens when someone wins the game

	int gamestat(){

		if (arr[0] == arr[1] && arr[1] == arr[2])
			return 1;
		else if (arr[3] == arr[4] && arr[4] == arr[5])
			return 1;
		else if (arr[6] == arr[7] && arr[7] == arr[8])
			return 1;
		else if (arr[0] == arr[3] && arr[3] == arr[6])
			return 1;
		else if (arr[1] == arr[4] && arr[4] == arr[7])
			return 1;
		else if (arr[2] == arr[5] && arr[5] == arr[8])
			return 1;
		else if (arr[0] == arr[4] && arr[4] == arr[8])
			return 1;
		else if (arr[2] == arr[4] && arr[4] == arr[6])
			return 1;
		else if (arr[0] != '1' && arr[1] != '2' && arr[2] != '3' && arr[3] != '4' && arr[4] != '5' && arr[5] != '6' && arr[6] != '7' && arr[7] != '8' && arr[8] != '9')
			return 0;
		else
			return -1;
	}

	int ai(){
		if(arr[0]==arr[1]&&arr[2]=='3')
			return 3;
		else if(arr[0]==arr[2]&&arr[1]=='2')
			return 2;
		else if(arr[1]==arr[2]&&arr[0]=='1')
			return 1;
		else if(arr[3]==arr[4]&&arr[5]=='6')
			return 6;
		else if(arr[3]==arr[5]&&arr[4]=='5')
			return 5;
		else if(arr[4]==arr[5]&&arr[3]=='4')
			return 4;
		else if(arr[6]==arr[7]&&arr[8]=='9')
			return 9;
		else if(arr[6]==arr[8]&&arr[7]=='8')
			return 8;
		else if(arr[7]==arr[8]&&arr[6]=='7')
			return 7;
		else if(arr[0]==arr[3]&&arr[6]=='7')
			return 7;
		else if(arr[0]==arr[6]&&arr[3]=='4')
			return 4;
		else if(arr[3]==arr[6]&&arr[0]=='1')
			return 1;
		else if(arr[1]==arr[4]&&arr[7]=='8')
			return 8;
		else if(arr[1]==arr[7]&&arr[4]=='5')
			return 5;
		else if(arr[4]==arr[7]&&arr[1]=='2')
			return 2;
		else if(arr[2]==arr[5]&&arr[8]=='9')
			return 9;
		else if(arr[2]==arr[8]&&arr[5]=='6')
			return 6;
		else if(arr[5]==arr[8]&&arr[2]=='3')
			return 3;
		else if(arr[0]==arr[4]&&arr[8]=='9')
			return 9;
		else if(arr[0]==arr[8]&&arr[4]=='5')
			return 5;
		else if(arr[4]==arr[8]&&arr[0]=='1')
			return 1;
		else if(arr[2]==arr[4]&&arr[6]=='7')
			return 7;
		else if(arr[2]==arr[6]&&arr[4]=='5')
			return 5;
		else if(arr[4]==arr[6]&&arr[2]=='3')
			return 3;
		else 
			return rand()%a;
	}

	//the display function is used to display the grid whenever required

	void display(){

		cout<<"\t\t   |   |   \n";
		cout<<"\t\t "<<arr[0]<<" | "<<arr[1]<<" | "<<arr[2]<<" \n";
		cout<<"\t\t___|___|___\n";
		cout<<"\t\t   |   |   \n";
		cout<<"\t\t "<<arr[3]<<" | "<<arr[4]<<" | "<<arr[5]<<" \n";
		cout<<"\t\t___|___|___\n";
		cout<<"\t\t   |   |   \n";
		cout<<"\t\t "<<arr[6]<<" | "<<arr[7]<<" | "<<arr[8]<<" \n";
		cout<<"\t\t   |   |   \n";
	}

	//the function refresh is used to re-declare the array elements to ensure proper functioning
	void refresh(){
		arr[0]='1';
		arr[1]='2';
		arr[2]='3';
		arr[3]='4';
		arr[4]='5';
		arr[5]='6';
		arr[6]='7';
		arr[7]='8';
		arr[8]='9';
	}

	void UpdateScore(const char *name) 
	{ 
		int pos, found = 0;
		fstream fs; 
		fs.open("score.dat", ios::in | ios::binary | ios::out); 

		if (fs.is_open())
		{
			while (!fs.eof()) 
			{ 
				pos = fs.tellg(); 
				score player;
				fs.read((char*)&player, sizeof(score)); 

				if (fs) 
				{ 
					if (0 == strcmp(player.name,name)) 
					{ 
						found = 1; 
						++player.winCount;
						fs.seekp(pos); 
						fs.write((char*)&player, sizeof(score)); 
						break; 
					} 
				} 
			} 
			fs.close(); 
		}

		if (found == 0) 
		{
			score player;
			strcpy(player.name, name);
			player.winCount = 1;
			fs.open("score.dat", ios::binary | ios::app); 
			fs.write((char*)&player, sizeof(score)); 
			fs.close(); 
		}
	} 

	void DisplayScore()
	{
		fstream fs; 
		fs.open("score.dat", ios::in | ios::binary); 
		if (fs.is_open())
		{
			cout<<"\t\t\t\tLeaderboard\n";
			cout<<"\t+-------------------------------+-----------------------+\n";
			cout<<"\t|\t\tName\t\t|\t  Score\t\t|\n";
			cout<<"\t+-------------------------------+-----------------------+\n";

			while (!fs.eof()) 
			{ 
				score player;
				fs.read((char*)&player, sizeof(score)); 

				if (fs) 
				{ 
					cout<<"\t|"<<setw(19);
					cout<<player.name;
					cout<<"\t\t|\t";
					cout<<setw(5);
					cout<<player.winCount<<setw(12)<<'|'<<endl;
				} 
			} 
			fs.close(); 
			cout<<"\t+-------------------------------+-----------------------+\n";
		}
	}
};
class singleplayer : public tictactoe{		
public:	
	void playervsbot(){
		refresh();		
		system("cls");

		cout<<"\t\t\t\tTIC TAC TOE\n\n\n\n";

		cout<<"Instructions\n";
		cout<<"By default the symbol for player 1 is \"X\"\n";
		cout<<"By default the symbol for player 2 is \"O\"\n";
		cout<<"To place the respective symbols the players have to wait for their turn\n";
		cout<<"To place their symbol on the cross the player must enter the corresponding number\n\n\n";

		display();

		fflush(stdin);

		cout<<"Enter player\'s name\n";
		gets(player1);

        replay:

		system("cls");
		refresh();

		cout<<player1<<"\'s symbol is \'X\'\n";
		cout<<"Computer\'s symbol is \'O\'\n";

		display ();

		for(int i=0;i<9;i++){
			if(i%2==0){
				cout<<player1<<"\'s turn ";
				cin>>position;
				cin.clear();
				cin.ignore(1000,'\n');
				if (position == 1 && arr[0] == '1')
					arr[0] = 'X';
				else if (position == 2 && arr[1] == '2')
					arr[1] = 'X';
				else if (position == 3 && arr[2] == '3')
					arr[2] = 'X';
				else if (position == 4 && arr[3] == '4')
					arr[3] = 'X';
				else if (position == 5 && arr[4] == '5')
					arr[4] = 'X';
				else if (position == 6 && arr[5] == '6')
					arr[5] = 'X';
				else if (position == 7 && arr[6] == '7')
					arr[6] = 'X';
				else if (position == 8 && arr[7] == '8')
					arr[7] = 'X';
				else if (position == 9 && arr[8] == '9')
					arr[8] = 'X';
				else{
					cout<<"Invalid move \n";
					cout<<"please try again\n";
					i--;}
			}

			else if(i%2==1){
				cout<<"Computer\'s turn\n";
				position = ai();
				if (position == 1 && arr[0] == '1')
					arr[0] = 'O';
				else if (position == 2 && arr[1] == '2')
					arr[1] = 'O';
				else if (position == 3 && arr[2] == '3')
					arr[2] = 'O';
				else if (position == 4 && arr[3] == '4')
					arr[3] = 'O';
				else if (position == 5 && arr[4] == '5')
					arr[4] = 'O';
				else if (position == 6 && arr[5] == '6')
					arr[5] = 'O';
				else if (position == 7 && arr[6] == '7')
					arr[6] = 'O';
				else if (position == 8 && arr[7] == '8')
					arr[7] = 'O';
				else if (position == 9 && arr[8] == '9')
					arr[8] = 'O';
				else{
					i--;}
			}
			display();

			j=gamestat();
			if(j==1)
				i=9;	
		}	
		system("cls");
		cout<<"\n\n";

		k=winner();
		char *winnerName;

		switch(k){
		case 1:r1();
			cout<<player1<<" wins!!!!\n";
			break;
		case 2:r1();
			cout<<"Computer wins!!!!\n";
			break;
		case 3:r2();
			cout<<player1<<" wins!!!!\n";
			break;
		case 4:r2();
			cout<<"Computer wins!!!!\n";
			break;
		case 5:r3();
			cout<<player1<<" wins!!!!\n";
			break;
		case 6:r3();
			cout<<"Computer wins!!!!\n";
			break;
		case 7:c1();
			cout<<player1<<" wins!!!!\n";
			break;
		case 8:c1();
			cout<<"Computer wins!!!!\n";
			break;
		case 9:c2();
			cout<<player1<<" wins!!!!\n";
			break;
		case 10:c2();
			cout<<"Computer wins!!!!\n";
			break;
		case 11:c3();
			cout<<player1<<" wins!!!!\n";
			break;
		case 12:c3();
			cout<<"Computer wins!!!!\n";
			break;
		case 13:d1();
			cout<<player1<<" wins!!!!\n";
			break;
		case 14:d1();
			cout<<"Computer wins!!!!\n";
			break;
		case 15:d2();
			cout<<player1<<" wins!!!!\n";
			break;
		case 16:d2();
			cout<<"Computer wins!!!!\n";
			break;
		case 0:display ();
			cout<<"Draw match!!!!\n";
			break;
		default:cout<<"?????";        
		}

		if(k!=0)
		{
			if( k%2==0)
			{
				UpdateScore("Computer");
			}
			else 
			{
				UpdateScore(player1);
			}
		}

		cout<<"do you want to play again??\n";
        mid:
		cout<<"press 1 to play again, press 2 to exit\n";
		fflush(stdin);
		cin>>exit;
		fflush(stdin);
		if(exit==1){                          //bug fixed when int is used...
			goto replay;
		}
		else if(exit==2){
			cout<<"Do you want to check scores before leaving??\n";
			cout<<"press 1 to display the leaderboard else any other integer\n";
			cin>>d;
			if(d==1){
			system("cls");
			DisplayScore();
			}
			cout<<endl;
			cout<<"Thank you, hope you enjoyed\n";
		}
		else{
			cout<<"please enter only valid input\n";
			system("pause");
			system("cls");
			goto mid;
		}	   
	}
};

class twoplayers: public tictactoe{
public:
	void playervsplayer(){
		refresh();	    
		system("cls");

		cout<<"\t\t\t\tTIC TAC TOE\n\n\n\n";

		cout<<"Instructions\n";
		cout<<"By default the symbol for player 1 is \"X\"\n";
		cout<<"By default the symbol for player 2 is \"O\"\n";
		cout<<"To place the respective symbols the players have to wait for thier turn\n";
		cout<<"To place their symbol on the cross the player must enter the coresponding number\n\n\n";

		display();

		fflush(stdin);

		cout<<"Enter player 1\'s name\n";
		gets(player1);

		cout<<"Enter player 2\'s name\n";
		gets(player2);

        again:

		system("cls");
		refresh();		   
		cout<<player1<<"\'s symbol is \'X\'\n";
		cout<<player2<<"\'s symbol is \'O\'\n";

		display ();

		for(int i=0;i<9;i++){
			if(i%2==0){
				cout<<player1<<"\'s turn ";
				cin>>position;
				cin.clear();
				cin.ignore(1000,'\n');
				if (position == 1 && arr[0] == '1')
					arr[0] = 'X';
				else if (position == 2 && arr[1] == '2')
					arr[1] = 'X';
				else if (position == 3 && arr[2] == '3')
					arr[2] = 'X';
				else if (position == 4 && arr[3] == '4')
					arr[3] = 'X';
				else if (position == 5 && arr[4] == '5')
					arr[4] = 'X';
				else if (position == 6 && arr[5] == '6')
					arr[5] = 'X';
				else if (position == 7 && arr[6] == '7')
					arr[6] = 'X';
				else if (position == 8 && arr[7] == '8')
					arr[7] = 'X';
				else if (position == 9 && arr[8] == '9')
					arr[8] = 'X';
				else{
					cout<<"Invalid move ";
					cout<<"position alraedy occupyed by other player";
					i--;}
			}

			else if(i%2==1){
				cout<<player2<<"\'s turn ";
				cin>>position;
				cin.clear();
				cin.ignore(1000,'\n');
				if (position == 1 && arr[0] == '1')
					arr[0] = 'O';
				else if (position == 2 && arr[1] == '2')
					arr[1] = 'O';
				else if (position == 3 && arr[2] == '3')
					arr[2] = 'O';
				else if (position == 4 && arr[3] == '4')
					arr[3] = 'O';
				else if (position == 5 && arr[4] == '5')
					arr[4] = 'O';
				else if (position == 6 && arr[5] == '6')
					arr[5] = 'O';
				else if (position == 7 && arr[6] == '7')
					arr[6] = 'O';
				else if (position == 8 && arr[7] == '8')
					arr[7] = 'O';
				else if (position == 9 && arr[8] == '9')
					arr[8] = 'O';
				else{
					cout<<"Invalid move \n";
					cout<<"position already occupyed by other player\n";
					i--;}
			}
			display();

			j=gamestat();
			if(j==1)
				i=9;
		}
		system("cls");
		cout<<"\n\n";

		k=winner();
		switch(k){
		case 1:r1();
			cout<<player1<<" wins!!!!\n";
			break;
		case 2:r1();
			cout<<player2<<" wins!!!!\n";
			break;
		case 3:r2();
			cout<<player1<<" wins!!!!\n";
			break;
		case 4:r2();
			cout<<player2<<" wins!!!!\n";
			break;
		case 5:r3();
			cout<<player1<<" wins!!!!\n";
			break;
		case 6:r3();
			cout<<player2<<" wins!!!!\n";
			break;
		case 7:c1();
			cout<<player1<<" wins!!!!\n";
			break;
		case 8:c1();
			cout<<player2<<" wins!!!!\n";
			break;
		case 9:c2();
			cout<<player1<<" wins!!!!\n";
			break;
		case 10:c2();
			cout<<player2<<" wins!!!!\n";
			break;
		case 11:c3();
			cout<<player1<<" wins!!!!\n";
			break;
		case 12:c3();
			cout<<player2<<" wins!!!!\n";
			break;
		case 13:d1();
			cout<<player1<<" wins!!!!\n";
			break;
		case 14:d1();
			cout<<player2<<" wins!!!!\n";
			break;
		case 15:d2();
			cout<<player1<<" wins!!!!\n";
			break;
		case 16:d2();
			cout<<player2<<" wins!!!!\n";
			break;
		case 0:display ();
			cout<<"Draw match!!!!\n";
			break;
		default:cout<<"?????";        
		}

		if(k!=0)
		{
			if( k%2==0)
			{
				UpdateScore(player2);
			}
			else 
			{
				UpdateScore(player1);
			}
		}

		cout<<"do you want to play again??\n";
        there:
		cout<<"press 1 to play again, press 2 to exit\n";
		fflush(stdin);
		cin>>exit;
		if(exit==1){                           
			goto again;
		}
		else if(exit==2){
			cout<<"Do you want to check scores before leaving??\n";
			cout<<"press 1 to display the leaderboard else any other integer\n";
			cin>>d;
			if(d==1){
			system("cls");
			DisplayScore();
			}
			cout<<endl;
			cout<<"Thank you, hope you enjoyed\n";
		}
		else{
			cout<<"please enter only valid input\n";
			system("pause");
			system("cls");
			goto there;
		}	  
	}
};
int main(){
	int choice;	

    begining:
	cout<<"\t\t\t\tTIC TAC TOE\n\n\n\n";
	cout<<"press 1 for single player\n";
	cout<<"press 2 for 2 players\n";
	cin>>choice;
	if(choice==1){		
		singleplayer ob;
		ob.playervsbot();

	}
	else if(choice==2){	
		twoplayers ob2;
		ob2.playervsplayer();

	}
	else{
		cout<<"press 1 or 2 only!!!\n";
		system("pause");
		system("cls");
		goto begining;
	}

	return 0;
}
