#include <iostream>
using namespace std;

class LinkedQueue{
    class Node{
        public:
        int Data;
        Node *Next;

        Node(int item){
            Data = item;
            Next = 0;
        }
    };
    Node *myFront, *myBack;
    public:
    LinkedQueue(){
        myFront = myBack = 0;
    }

    bool Empty(){
        return (myFront == 0);
    }

    void Enqueue(int item){
        Node *ptr = new Node(item);
        if(Empty()){
        	myFront = myBack = ptr;
		}
		else{
			myBack->Next = ptr;
        	myBack = ptr;
		}
    }

    void Dequeue(void){
        if(Empty()){
            cerr << "Empty Queue" << endl;
        }
        else{
            Node* ptr = myFront;
            myFront = myFront->Next;
            delete ptr;

            if(myFront == 0){
                myBack == 0;
            }
        }
    }

    void Display(void){
        if(Empty()){
            cerr << "Empty Queue" << endl;
        }
        else{
            for(Node *ptr = myFront; ptr != 0; ptr = ptr->Next){
                cout << ptr->Data << endl;
            }
        }
    }

    int Front(){
        return(myFront->Data);
    }
};

void br(){
    cout << "======" << endl;
}

int main (void){
    LinkedQueue lq;
    lq.Display();
    br();
    for(int i = 0; i < 5; i++){
        lq.Enqueue(i);
    }
    lq.Display();
    br();
    for(int i = 0; i < 3; i++){
        lq.Dequeue();
    }
    lq.Display();
    br();

    cout << "Front: " << lq.Front() << endl;
}
