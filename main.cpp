#include<iostream>
using namespace std;
class Players
{
    string player1, player2;
		int choice;
    char board[3][3]={{'a','b','c'},
											{'d','e','f'},
											{'g','h','i'}};
    int i,j,turn;
    char x,place;
		bool draw = false;
		bool visited[9] = {false};
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
				turn = 1;
			}
			else{
				cout << "Player 2 Selected." << endl;
				turn = 2;
			}
			showTurn();
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

    void showTurn()
    {
        if(turn == 1){
					cout<<"PLAYER OF CURRENT TURN: "<<player1<<"\n";
        	x='X';
        }
        else if(turn == 2){
					cout<<"PLAYER OF CURRENT TURN: "<<player2<<"\n";
        	x='O';
				}
		}

    void getUserChoice(){
        cout<<"ENTER THE NUMBER YOU WANT TO OCCUPY: ";
        cin>>place;
				if(visited[place-97]){
					cout << "Please enter a Valid place" << endl;
					restartUserChoice();
				}else{
					visited[place-97] = true;
				}
    }
		void restartUserChoice(){
			getUserChoice();
		}

    void turnCounter(){
			getUserChoice();

        for(int step = 1; step < 10; step++){
					bool chk = true;
						switch(place){
						    case 'a':{	board[0][0]=x; display(); Result(); break; }
						    case 'b':{	board[0][1]=x; display(); Result(); break; }
						    case 'c':{	board[0][2]=x; display(); Result(); break; }
						    case 'd':{	board[1][0]=x; display(); Result(); break; }
						    case 'e':{	board[1][1]=x; display(); Result(); break; }
						    case 'f':{	board[1][2]=x; display(); Result(); break; }
						    case 'g':{	board[2][0]=x; display(); Result(); break; }
						    case 'h':{	board[2][1]=x; display(); Result(); break; }
						    case 'i':{	board[2][2]=x; display(); Result(); break; }
						    default: {cout<<"PLEASE ENTER VALID NUMBER SPACE: "; step--; chk = false; }
							}
							if(step == 9){
								isDraw();
							}
							if(chk){
							if(turn == 1)
								turn = 2;
							else
								turn = 1;
							}
								showTurn();
								getUserChoice();
						}
			        display();

		}
    void display()
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
        	exit(0);
        }

        else if(board[0][1]==board[1][1]&&board[1][1]==board[2][1]){
            cout<<"WINNER IS:"<<board[1][1];
            exit(0);
        }

        else if(board[0][2]==board[1][2]&&board[1][2]==board[2][2]){
            cout<<"WINNER IS:"<<board[1][2];
            exit(0);
        }

        else if(board[0][0]==board[0][1]&&board[0][1]==board[0][2]){
            cout<<"WINNER IS:"<<board[0][1];
            exit(0);
        }

        else if(board[1][0]==board[1][1]&&board[1][1]==board[1][2]){
            cout<<"WINNER IS:"<<board[0][1];
            exit(0);
        }

        else if(board[2][0]==board[2][1]&&board[2][1]==board[2][2]){
            cout<<"WINNER IS:"<<board[2][1];
            exit(0);
        }

        else if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]){
            cout<<"WINNER IS:"<<board[2][0];
            exit(0);
        }

        else if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]){
            cout<<"WINNER IS:"<<board[2][0];
            exit(0);
        }

        else{
            draw=1;
			 }
    }

    void isDraw(){
        if(draw==1){
            cout<<"*******MATCH DRAW**********";
						exit(0);
					}
    }
};

int main()
{
    Players st;
    st.gameInit();

}
