#include <iostream>
using namespace std;

#define CAPACITY 10

class ArrayStack{
    private:
    int myTop;
    int myArray[CAPACITY];

    public:
    ArrayStack(){
        myTop = -1;
    }

    bool Empty(void){
        return (myTop == -1);
    }

    void Push(int item){
        if(myTop == (CAPACITY - 1)){
            cerr << "Full Stack" << endl;
        }
        else{
            myTop++;
            myArray[myTop] = item;
        }
    }

    void Pop(){
        if(Empty()){
            cerr << "Empty Stack" << endl;
        }
        else{
            myTop--;
        }
    }

    void Display(void){
        if(Empty()){
            cerr << "Empty Stack" << endl;
        }
        else{
            for(int i = myTop; i >= 0; i--){
                cout << myArray[i] << endl;
            }
        }
        
    }

    int Top(){
        return (myArray[myTop]);
    }
};

void br(){
    cout << "======" << endl;
}

int main (void){
    ArrayStack as;
    as.Display();
    br();
    for(int i = 0; i < 11; i++)
        as.Push(i);
    as.Display();
    br();
    as.Pop();
    as.Display(); 
    cout << "Top: " << as.Top() << endl;   
}