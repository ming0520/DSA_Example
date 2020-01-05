#include <iostream>
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

    int Top(){
        return(myTop->Data);
    }
};

int main(void){
    LinkedStack ls;
    ls.Display();
    cout << "=========" << endl;
    for(int i = 0; i < 5; i++){
        ls.Push(i);
    }
    cout << "=========" << endl;
    ls.Display();
    ls.Pop();
    cout << "=========" << endl;
    ls.Display();
    cout << "Top: " << ls.Top() << endl;
    return 0;
    
}