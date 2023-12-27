#include<bits/stdc++.h>
using namespace std;
int main(){
    srand((unsigned int) time(NULL));
    int number = (rand() % 100) + 1;//1-100
    int guess = 0;
    do{
        cout<<"Enter the Guess Number b/w 1 to 100"<<endl;
        cin>>guess;
        if(guess>number){
            cout<<"Guess is Higher!!!"<<endl;
        }
        else if(guess<number){
            cout<<"Guess is Lower!!!"<<endl;
        }
        else{
            cout<<"!!! YOU WON !!!"<<endl;
        }
    }while(guess!=number);
    return 0;
}