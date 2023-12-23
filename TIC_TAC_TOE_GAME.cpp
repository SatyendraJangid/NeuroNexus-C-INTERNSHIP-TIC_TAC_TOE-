#include<bits/stdc++.h>
using namespace std;

int row,col;
string name1,name2;
char token = 'X';
bool t = false;;
string wantPlayAgain = "yes";
vector<vector<char>> grid = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void functionOne(){

    cout<<"   |   |   \n";
    cout<<grid[0][0]<<"  | "<<grid[0][1]<<" |  "<<grid[0][2]<<"\n";
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<grid[1][0]<<"  | "<<grid[1][1]<<" |  "<<grid[1][2]<<"\n";
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<grid[2][0]<<"  | "<<grid[2][1]<<" |  "<<grid[2][2]<<"\n";
    cout<<"   |   |   \n";

}

void functionTwo(){
    int digit;
    if(token=='X'){
        cout<<name1<<" Please Enter:";
        cin>>digit;
    }
    if(token=='O'){
        cout<<name2<<" Please Enter:";
        cin>>digit;
    }

    if(digit==1){
        row = 0;
        col = 0;
    }

    else if(digit==2){
        row = 0;
        col = 1;
    }

    else if(digit==3){
        row = 0;
        col = 2;
    }

    else if(digit==4){
        row = 1;
        col = 0;
    }

    else if(digit==5){
        row = 1;
        col = 1;
    }

    else if(digit==6){
        row = 1;
        col = 2;
    }

    else if(digit==7){
        row = 2;
        col = 0;
    }

    else if(digit==8){
        row = 2;
        col = 1;
    }

    else if(digit==9){
        row = 2;
        col = 2;
    }

    else{
        cout<<"Please Enter Valid Digit!!!";
    }

    if(token=='X' && grid[row][col]!='X' && grid[row][col]!='O'){
        grid[row][col]='X';
        token = 'O';
    }
    else if(token=='O' && grid[row][col]!='X' && grid[row][col]!='O'){
        grid[row][col]='O';
        token = 'X';
    }
    else{
        cout<<"There is no Empty Space!!!";
        functionTwo();
    }
    
}

bool functionThree(){

    bool flag = true;
    for(int i = 0;i<3;i++){
        if((grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2])||
            (grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i])){
                return true;
            }
    }

    if((grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2])||
        (grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0])){
            return true;
        }

    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(grid[i][j]!='X' && grid[i][j]!='O'){
                return false;
            }
        }
    }

    t = true;
    return false;

}

void functionFinal(){

    while(!functionThree()){
            functionOne();
            functionTwo();
            functionThree();
        }

        if(t==false && token=='O'){
            cout<<name1<<" is Winner!!!";
        }
        else if(t==false && token=='X'){
            cout<<name2<<" is winner!!!";
        }
        else if(t==true){
            cout<<"Game is TIE!!!";
        }

        cout<<" **PLAY AGAIN**\n ";
        cin>>wantPlayAgain;
        if(wantPlayAgain=="yes"){
            grid = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
            cout<<"NEW GAME STARTED\n";
            cout<<"    PLAY NOW     \n";
            functionFinal();
        }

}


int main(){
    
    cout<<"Enter the Name of first player:\n";
    getline(cin,name1);

    cout<<"Enter the Name of second player:\n";
    getline(cin,name2);

    cout<<name1<<"is player1 so he/she will paly first!\n";
    cout<<name2<<"is player2 so he/she will paly second!\n";

    
    functionFinal();

    return 0;
}