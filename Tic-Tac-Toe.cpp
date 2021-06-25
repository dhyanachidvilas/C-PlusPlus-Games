#include<iostream>
using namespace std;

char board[9] = {' ',' ',' ',' ', ' ' ,' ',' ',' ',' '};

void showBoard();
void getPlayerX_move();
void getPlayerO_move();
int countBoard(char symbol);
char checkWinner();
void computer_vs_player();
void player_vs_player();

int main() {
    int mode ;
    cout<<" 1. Computer Vs Player"<<endl;
    cout<<" 2. Player Vs Player"<<endl;
    cout<<"Select Game Mode : ";
    cin>>mode;
    cout<<endl;
    switch(mode) {
        case 1 : 
            computer_vs_player();
            break;
        case 2 :
            player_vs_player();
            break;
        default : 
            cout<<"Invalid Mode, Try again"<<endl;
            break;
    }
    return 0;
}

void getComputerMove() {
    //srand(time(0));
    int move;
    do {
        move = rand()%10;
    }while(board[move] != ' ');
    board[move] = 'O';
}
void getPlayerX_move() {
    while(true) {
        cout<<"Select Your Position (1-9): ";
        int move ;
        cin>>move;
        move--;
        if(move < 0 || move > 8) {
            cout<<"Please Select Your Choice from (1 - 9)"<<endl;
        }
        else if (board[move] != ' '){
            cout<<"Please Select an existing Position"<<endl;
        }
        else {
            board[move] = 'X';
            break;
        }
    }
}
void getPlayerO_move() {
    while(true) {
        cout<<"Select Your Position (1-9): ";
        int move ;
        cin>>move;
        move--;
        if(move < 0 || move > 8) {
            cout<<"Please Select Your Choice from (1 - 9)"<<endl;
        }
        else if (board[move] != ' '){
            cout<<"Please Select an existing Position"<<endl;
        }
        else {
            board[move] = 'O';
            break;
        }
    }
}

void computer_vs_player() {
    string player_name ;
    cout<<"Enter Your Name: ";
    cin>>player_name;
    while(true) {
        system("cls");
        showBoard();
        if(countBoard('X') == countBoard('O')) {
            cout<<player_name<<"'s Turn. "<<endl;
            getPlayerX_move();
        }
        else {
            getComputerMove();
        }
        char winner = checkWinner();
        if(winner == 'X') {
            system("cls");
            showBoard();
            cout<<player_name<<" won the game."<<endl;
            break;
        }
        else if(winner == 'O') {
            system("cls");
            showBoard();
            cout<<" Computer won the game. "<<endl;
            break;
        }
        else if(winner == 'D') {
            //system("cls");
            cout<<" Game Draw. "<<endl;
            break;
        }
    }
}


int countBoard( char symbol ) {
    int total = 0;
    for(int i = 0 ; i < 9 ; i++) {
        if(board[i] == symbol)
            total ++;
    }
    return total;
}
char checkWinner() {
    //checking horizontal
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ') return board[0];
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ') return board[3];
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ') return board[6];
    //checking vertical
    if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ') return board[0];
    if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ') return board[1];
    if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ') return board[2];
    //checking diagonal
    if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ') return board[0];
    if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ') return board[2];

    if(countBoard('X') + countBoard('O') < 9) return 'C';
    else return 'D';
}

void showBoard() {
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[0]<<"   |   "<<board[1]<<"   | "<<board[2]<<endl;
    cout<<"------------------------"<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[3]<<"   |   "<<board[4]<<"   | "<<board[5]<<endl;
    cout<<"------------------------"<<endl;
    cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<board[6]<<"   |   "<<board[7]<<"   | "<<board[8]<<endl;
}

void player_vs_player() {
    string playerX, playerO;
    cout<<"Enter X Player Name: ";
    cin>>playerX;
    cout<<"Enter O Player Name: ";
    cin>>playerO;

    while(true) {
        system("cls");
        showBoard();
        if(countBoard('X') == countBoard('O')) {
            cout<<playerX<<"'s turn."<<endl;
            getPlayerX_move();
        }
        else {
            cout<<playerO<<"'s turn."<<endl;
            getPlayerO_move();
        }
        char winner = checkWinner();
        if(winner == 'X') {
            system("cls");
            showBoard();
            cout<<playerX<<" won the game."<<endl;
            break;
        }
        else if(winner == 'O') {
            system("cls");
            showBoard();
            cout<<playerO<<" won the game."<<endl;
            break;
        }
        else if(winner == 'D') {
            //system("cls");
            cout<<" Game Draw. "<<endl;
            break;
        }
    }
}