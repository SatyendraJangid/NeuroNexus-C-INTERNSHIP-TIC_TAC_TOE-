#include<bits/stdc++.h>
using namespace std;

//console based to do list project
unordered_map<string,bool> task_list;

//add task
void functionTwo(string task){
    if(task_list.find(task)!=task_list.end()){
        cout<<"The task is already added!!!\n";
        cout<<"Enter Another task!!!\n";
    }
    else{
        task_list[task] = false;
    }
}

void functionOne(){
    cout<<"Enter the number of tasks that you want to Add : ";

    int n;
    cin>>n;
    cout<<"Enter the tasks\n"; 
    while(n--){
        string task;
        cin>>task;
        functionTwo(task);
    }
}

//view task
void functionThree(){
    for(auto it:task_list){
        cout<<it.first<<"-------->";
        if(it.second==false)cout<<"Panding"<<endl;
        else cout<<"Completed"<<endl;
    }
}

//mark task as done
void functionFour(){
    int n;
    cout<<"Enter the no of tasks that you have completed:";
    cin>>n;
    cout<<"\n";
    cout<<"Enter the task that you want to mark as completed"<<endl;
    while(n--){
        string task;
        cin>>task;
        if(task_list.find(task)!=task_list.end()){
            task_list[task] = true;
        }
    }

    functionThree();
    
}

//remove task
void functionFive(){
    cout<<"Enter the number of tasks that you want to remove:";
    int n;
    cin>>n;
    cout<<"\n";
    while(n--){
        cout<<"Enter the task name that you want to Remove : ";
        string task;
        cin>>task;
        if(task_list.find(task)!=task_list.end()){
            task_list.erase(task);
        }
    }
    
}

void ButtonFunction(){
    cout<<"Press 1 : Add Task\n";
    cout<<"Press 2 : View Task\n";
    cout<<"Press 3 : Mark As Done\n";
    cout<<"Press 4 : Remove Task\n";
    cout<<"Press 5 : To Exit\n";
}

int main(){
    ButtonFunction();
    int input;
    cin>>input;

    while(input!=5){

    if(input==1){
        functionOne();
    }
    if(input==2){
        functionThree();
    }
    if(input==3){
        functionFour();
    }
    if(input==4){
        functionFive();
    }
    cout<<"Press key As your Requirement\n";
    cin>>input;
    }
    cout<<"You are Exit Now"<<endl;
    return 0;
}