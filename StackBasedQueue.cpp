#include <iostream>
#include <cstdlib> //atoi
using namespace std;

class LinkedStack{
    class Node{
        public:
        int Data;
        Node *Next;

        Node(int item){
            Data = item;
            Next = 0;
        }
    };
    public:
    Node *myTop;

    LinkedStack(){
        myTop = 0;
    }

    void Push(int item){
        Node *ptr = new Node(item);
        ptr->Next = myTop;
        myTop = ptr;
    }

    void Pop(){
        if(Empty()){
            cerr << "Empty Stack" << endl;
        }
        else{
            Node *ptr = myTop;
        myTop = myTop->Next;
        delete ptr;
        }
    }

    bool Empty(){
        return(myTop == 0);
    }

    int Top(){
        return(myTop->Data);
    }

    int countNode(){
        int nodeCount = 0;
        if(Empty()){
            return nodeCount;
        }
        for(Node *ptr = myTop; ptr != 0; ptr = ptr->Next){
            nodeCount++;
        }
        return nodeCount;
    }

    void Display(void){
        if(Empty()){
            cerr << "Empty Stack" << endl;
        }
        else{
            for(Node *ptr = myTop; ptr != 0; ptr = ptr->Next){
                cout << ptr->Data << endl;
            }
        }
    }
};

class StackBasedQueue{
    private:
    LinkedStack s1, s2;

    public:

    void Enqueue(int item){
        s1.Push(item);
    }

    bool QEmpty(void){
        return (s1.Empty() && s2.Empty());
    }

    void Dequeue(void){
        if(QEmpty()){
            cerr << "Empty Queue" << endl;
        }
        else{
            if(s2.Empty()){
                Transfer();
                s2.Pop();
            }
            else{
                s2.Pop();
            }
        }
    }

    void Transfer(void){
        if(QEmpty()){
            cerr << "Empty Queue" << endl;
        }
        else{
            while(!s1.Empty()){
                s2.Push(s1.Top());
                s1.Pop();
            }
        }
    }

    void Display(void){
        if(QEmpty()){
            cerr << "Empty Queue" << endl;
        }
        else{
            Transfer();
            s2.Display();
        }
    }

};

class User{
    private:

    StackBasedQueue SBQ;

    bool isNumber(string str){
        for(int i = 0; i < str.length(); i++){
            if(isdigit(str[i]) == false)
                return false;
        }
        return true;
    }



    public:

    void BackToMain(){
        system("pause");
        system("cls");
        MainMenu();
    }

    void MainMenu(){
        system("cls");
        system("color 07");
        bool isChoice = false;
        string choice;
        cout << "===================== Main Menu =====================" << endl;
        cout << "1. Enqueue an item" << endl;
        cout << "2. Dequeue an item" << endl;
        cout << "3. Display queue" << endl;
        cout << "4. Exit" << endl;
        cout << "=====================================================" << endl;

        while(!isChoice){
            cout << "Enter your choice: " ;
            cin >> choice;

            switch(atoi(choice.c_str())){
                case 1:
                    EnqueueMenu();
                    break;
                case 2:
                    DequeueMenu();
                    break;
                case 3:
                    DisplayMenu();
                case 4:
                    exit(0);
                default:
                    cout << "Invalid choice, please try again!" << endl;
                    isChoice = false;
            }
        }
    }

    void EnqueueMenu(){
        string input;
        int item = 0;
        system("cls");
        cout << "====================== Enqueue ======================" << endl;
        cout << "Enter an integer: " ;
        cin >> input;

        while(!isNumber(input)){
            cout << "Enter an valid integer: ";
            cin >> input;
        }

        item = atoi(input.c_str());
        SBQ.Enqueue(item);
        system("color 0a");
        cout << "Enqueue successfull!" << endl;
        BackToMain();    
    }

    void DequeueMenu(){
        system("cls");
        if(SBQ.QEmpty()){
            system("color 04");
        }
        else{
            system("color 0a");
            cout << "Dequeue successfull!" << endl;
        }
        SBQ.Dequeue();
        
        BackToMain();
    }

    void DisplayMenu(){
        system("cls");
        if(SBQ.QEmpty()){
            system("color 04");
        }
        else{
            cout << "Display successfull!" << endl;
        }
        SBQ.Display();
        BackToMain();
    }

};

int main (void){
    User usr;
    usr.MainMenu();
    return 0;
}