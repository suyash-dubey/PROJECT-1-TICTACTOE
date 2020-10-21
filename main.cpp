#include<iostream>
using namespace std;
class Players
{
    string str1,str2,str3,str4;
    char ar[3][3]={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
    int i,j,turn=1,flag=0,flag2=1;
    char x,place='a';
public:
    void getData()
    {
      cout<<"ENTER A NAME FOR PLAYER 'X': ";
	    getline(cin,str1);
	    cout<<"ENTER A NAME FOR PLAYER 'O': ";
	    getline(cin,str2);
	    getData2();
    }
    void getData2()
    {
			cout<<"WHO PLAYS FIRST? "<<"\n"<<str1<<" or "<<str2<<" :";
	    getline(cin,str3);
	    checkData();
	    grid();
	    turnCounter();
    }
    void checkData()
    {
		    if(str3==str1){
					cout<<str1<<" WILL MOVE FIRST!"<<"\n";
		      str4=str2;
				}
		    else if(str3==str2){
						cout<<str2<<" WILL MOVE FIRST!"<<"\n";
		        str4=str1;
				}
	    else{
	        cout<<str3<<" IS NOT A REGISTERED USER!";
	        getData2();
	    }
		}
    void grid(){
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                cout<<ar[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    void turn1()
    {
        if(turn%2==0){
					cout<<"PLAYER OF CURRENT TURN: "<<str4<<"\n";
        	x='O';
        }
        else if(turn%2!=0){
					cout<<"PLAYER OF CURRENT TURN: "<<str3<<"\n";
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
						    case 'a':{	ar[0][0]=x; Display(); Result(); break; }
						    case 'b':{	ar[0][1]=x; Display(); Result(); break; }
						    case 'c':{	ar[0][2]=x; Display(); Result(); break; }
						    case 'd':{	ar[1][0]=x; Display(); Result(); break; }
						    case 'e':{	ar[1][1]=x; Display(); Result(); break; }
						    case 'f':{	ar[1][2]=x; Display(); Result(); break; }
						    case 'g':{	ar[2][0]=x; Display(); Result(); break; }
						    case 'h':{	ar[2][1]=x; Display(); Result(); break; }
						    case 'i':{	ar[2][2]=x; Display(); Result(); break; }
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
                cout<<ar[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void Result(){
        if(ar[0][0]==ar[1][0]&&ar[1][0]==ar[2][0]){
					cout<<"WINNER IS:"<<ar[1][0];
        	flag2=0;
        }

        else if(ar[0][1]==ar[1][1]&&ar[1][1]==ar[2][1]){
            cout<<"WINNER IS:"<<ar[1][1];
            flag2=0;
        }

        else if(ar[0][2]==ar[1][2]&&ar[1][2]==ar[2][2]){
            cout<<"WINNER IS:"<<ar[1][2];
            flag2=0;
        }

        else if(ar[0][0]==ar[0][1]&&ar[0][1]==ar[0][2]){
            cout<<"WINNER IS:"<<ar[0][1];
            flag2=0;
        }

        else if(ar[1][0]==ar[1][1]&&ar[1][1]==ar[1][2]){
            cout<<"WINNER IS:"<<ar[0][1];
            flag2=0;
        }

        else if(ar[2][0]==ar[2][1]&&ar[2][1]==ar[2][2]){
            cout<<"WINNER IS:"<<ar[2][1];
            flag2=0;
        }

        else if(ar[0][2]==ar[1][1]&&ar[1][1]==ar[2][0]){
            cout<<"WINNER IS:"<<ar[2][0];
            flag2=0;
        }

        else if(ar[0][0]==ar[1][1]&&ar[1][1]==ar[2][2]){
            cout<<"WINNER IS:"<<ar[2][0];
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
    st.getData();

}
