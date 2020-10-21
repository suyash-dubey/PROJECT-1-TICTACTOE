#include<iostream>
using namespace std;
class Players
{
    string player1, player2;
		int choice;
    char board[3][3]={{'a','b','c'},
											{'d','e','f'},
											{'g','h','i'}};
    int i,j,turn,flag=0,flag2=1;
    char x,place;

public:
    void gameInit(){
      cout<<"ENTER A NAME FOR PLAYER 'X': ";
	    getline(cin,player1);
	    cout<<"ENTER A NAME FOR PLAYER 'O': ";
	    getline(cin,player2);
	    startGame();
    }

		void startGame(){
			cout<<"WHO PLAYS FIRST? "<<"\n"<<"1."<<player1<<" or "<<"2. "<<player2<<" (Enter 1 or 2) : ";
			cin >> choice;
			(choice == 1 || choice == 2) ? printBoard() : restart();
			if(choice == 1){
				cout << "Player 1 Selected. " << endl;
			}
			else{
				cout << "Player 2 Selected." << endl;
			}
	    turnCounter();
    }

		void restart(){
			cout << "\nPlease Enter Correct Choice !!" << endl;
			startGame();
		}

    void printBoard(){
				cout << "\nTic-tac-toe, noughts and crosses, or Xs and Os, is a game for two players,\n"
				 				 "X and O, who take turns marking the spaces in a 3×3 grid represented via a-i Below.\n"
								 "The player who succeeds in placing three of their marks in a horizontal, vertical,\n"
								 "or diagonal row is the winner." << endl << endl;

        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    void turn1()
    {
        if(turn%2==0){
					cout<<"PLAYER OF CURRENT TURN: "<<player2<<"\n";
        	x='O';
        }
        else if(turn%2!=0){
					cout<<"PLAYER OF CURRENT TURN: "<<player1<<"\n";
        x='X';
				}
		}

    void disp(){
        cout<<"ENTER THE NUMBER YOU WANT TO OCCUPY: ";
        cin>>place;
    }

    void turnCounter(){
        for(turn=1; turn<11; turn++){
					if(flag2!=0){
						switch(place){
						    case 'a':{	board[0][0]=x; Display(); Result(); break; }
						    case 'b':{	board[0][1]=x; Display(); Result(); break; }
						    case 'c':{	board[0][2]=x; Display(); Result(); break; }
						    case 'd':{	board[1][0]=x; Display(); Result(); break; }
						    case 'e':{	board[1][1]=x; Display(); Result(); break; }
						    case 'f':{	board[1][2]=x; Display(); Result(); break; }
						    case 'g':{	board[2][0]=x; Display(); Result(); break; }
						    case 'h':{	board[2][1]=x; Display(); Result(); break; }
						    case 'i':{	board[2][2]=x; Display(); Result(); break; }
						    default: {cout<<"PLEASE ENTER VALID NUMBER SPACE: "; turn=turn-1; }
							}
				    while(turn<10){
							if(flag2!=0){
								turn1();
				    	  disp();
							}
				    	break;
						}
				    while(turn==10){
				        Display();
				        Result();
				        Result2();
				        break;
				    }
    			}
				}
		}
    void Display()
    {
         for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void Result(){
        if(board[0][0]==board[1][0]&&board[1][0]==board[2][0]){
					cout<<"WINNER IS:"<<board[1][0];
        	flag2=0;
        }

        else if(board[0][1]==board[1][1]&&board[1][1]==board[2][1]){
            cout<<"WINNER IS:"<<board[1][1];
            flag2=0;
        }

        else if(board[0][2]==board[1][2]&&board[1][2]==board[2][2]){
            cout<<"WINNER IS:"<<board[1][2];
            flag2=0;
        }

        else if(board[0][0]==board[0][1]&&board[0][1]==board[0][2]){
            cout<<"WINNER IS:"<<board[0][1];
            flag2=0;
        }

        else if(board[1][0]==board[1][1]&&board[1][1]==board[1][2]){
            cout<<"WINNER IS:"<<board[0][1];
            flag2=0;
        }

        else if(board[2][0]==board[2][1]&&board[2][1]==board[2][2]){
            cout<<"WINNER IS:"<<board[2][1];
            flag2=0;
        }

        else if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]){
            cout<<"WINNER IS:"<<board[2][0];
            flag2=0;
        }

        else if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]){
            cout<<"WINNER IS:"<<board[2][0];
            flag2=0;
        }

        else{
            flag=1;
			 }
    }

    void Result2(){
        if(flag==1)
            cout<<"*******MATCH DRAW**********";
    }
};

int main()
{
    Players st;
    st.gameInit();

}
