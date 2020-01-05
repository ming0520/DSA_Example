#include <iostream>

#define CAPACITY 10

using namespace std;

class ArrayQueue{
    private:
    int myArray[CAPACITY];
    int myFront,myBack;

    public:
    ArrayQueue(){
        myFront = myBack = 0;
    }

    bool Empty(){
        return(myBack == myFront);
    }

    void Enqueue(int item){
        int newBack = (myBack + 1) % CAPACITY;
        if(newBack == myFront){
            cerr << "Full Queue" << endl;
        }
        else{
            myArray[myBack] = item;
            myBack = newBack;
        }
    }

    void Dequeue(void){
        if(Empty()){
            cerr << "Empty Queue" << endl;
        }
        else{
            myFront = (myFront + 1) % CAPACITY;
        }
    }

    void Display(void){
        if(Empty()){
            cerr << "Empty Queue" << endl;
        }
        else{
            for(int i = myFront; i != myBack; i = (i+1) % CAPACITY ){
                cout << myArray[i] << endl;
            }
        }
    }

    int Front(void){
        return (myArray[myFront]);
    }
};

void br(void){
    cout << "======" << endl;
}

int main (void){
    ArrayQueue aq;
    aq.Display();
    br();
    for(int i = 0; i < 11; i++){
        aq.Enqueue(i);
    }
    aq.Display();
    br();
    for(int i = 0; i < 3; i++){
        aq.Dequeue();
    }
    aq.Display();
    br();
    cout << "Front: " << aq.Front() << endl;
}