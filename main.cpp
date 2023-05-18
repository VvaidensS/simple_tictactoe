#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

//Array for the board
char board[10] = {'o','1','2','3','4','5','6','7','8','9'};

char checkwinner()
{
    //satır
    if(board[1]==board[2] && board[2]==board[3])
        return 1;
    else if(board[4]==board[5] && board[5]==board[6])
        return 1;
    else if(board[7]==board[8] && board[8]==board[9])
        return 1;
    //çapraz
    else if(board[1]==board[5] && board[5]==board[9])
        return 1;
    else if(board[3]==board[5] && board[5]==board[7])
        return 1;
    //sütun
    else if(board[1]==board[4] && board[4]==board[7])
        return 1;
    else if(board[2]==board[5] && board[5]==board[8])
        return 1;
    else if(board[3]==board[6] && board[6]==board[9])
        return 1;
    else if(board[1]!='1' && board[2]!='2' && board[3] != '3'
            && board[4] !='4' && board[5] !='5' && board[6] != '6'
            && board[7] != '7' && board[8] !='8' && board[9] !='9')
        return 0;
    else
        return -1;            

}

void display_board(){
    system("cls");
    //Rander Game Board LAYOUT
    cout<<"PLAYER - 1 [X] PLAYER - 2 [O]"<<endl;
    cout<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[1]<<"  |  "<<board[2]<<"  |  "<<board[3]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[4]<<"  |  "<<board[5]<<"  |  "<<board[6]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[7]<<"  |  "<<board[8]<<"  |  "<<board[9]<<endl;
    cout<<"     |     |     "<<endl;
}

void resetBoard(){
    char boardtype = '0';
    for (int i=0; i<=10;i++){
        board[i] = boardtype;
        boardtype++;     
    }
}

void resetGame(){
    bool tekraroyna = true;
    resetBoard();
}

void GameSetup(){
    int player = 1, i, choise;
    char mark;
    do
    {
        display_board();
        
        player=(player%2)?1:2;
        cout <<"Player "<<player<<", Enter the number: ";
        cin>>choise;

        mark = (player == 1) ? 'X' : 'O';
        
        if(choise == 1 && board[1]=='1'){
            board[1] = mark;
        }
        else if(choise == 2 && board[2]=='2'){
            board[2] = mark;
        }
        else if(choise == 3 && board[3]=='3'){
            board[3] = mark;
        }
        else if(choise == 4 && board[4]=='4'){
            board[4] = mark;
        }
        else if(choise == 5 && board[5]=='5'){
            board[5] = mark;
        }
        else if(choise == 6 && board[6]=='6'){
            board[6] = mark;
        }
        else if(choise == 7 && board[7]=='7'){
            board[7] = mark;
        }
        else if(choise == 8 && board[8]=='8'){
            board[8] = mark;
        }
        else if(choise == 9 && board[9]=='9'){
            board[9] = mark;
        }
        
        else
        {
            cout<<"Invalid Move"<<endl;
            player--;
            cin.ignore();
            cin.get();
        }
        
        i = checkwinner();
        player++;
    
    }
    while(i == -1);
    display_board();
    if(i == 1){
        cout<<"Congratulations player "<<--player<<" Wins";

    }
    else{
        cout<<"Game Draw"<<endl;
    }
    char choice;
    cout << "Yeniden oynamak ister misiniz? (E/H): ";
    cin >> choice;

    if(choice == 'E'){
        resetBoard();
        GameSetup();
    }
    else if(choice == 'H'){
        cout<<"Oyun Bitti";
    }
    cin.ignore();
    cin.get();

}


int main(){
    GameSetup();
}



