#include <iostream>

using namespace std;

class BST{
    
    class Node{
        public:
        int Data;
        Node *Left;
        Node *Right;

        Node (int item){
            Data = item;
            Left = 0;
            Right = 0;
        }
    };

    public:
    Node *Root;

    
    BST(void){
        Root = 0;
    }

    bool Empty(void){
        return (Root == 0);
    }

    bool Search(int item){
        Node *locptr = Root;
        bool found = false;
        while(true){
            if(found || locptr == 0){
                break;
            }
            if(item < locptr->Data){
                locptr = locptr->Left;
            }
            else if(item > locptr->Data){
                locptr = locptr->Right;
            }
            else{
                found = true;
            }
        }
        return found;
    }

    void Insert(int item){
        Node *locptr, *parrent;
        bool found = false;
        locptr = Root;
        parrent = 0;
        
        while(!found || locptr != 0){
            parrent = locptr;
            if(item < locptr->Data){
                locptr = locptr->Left;
            }
            else if(item > locptr->Data){
                locptr = locptr->Right;
            }
            else{
                found = true;
            }
        }

        if(!found){
            locptr = new Node(item);
            if(parrent == 0){
                Root =locptr;
            }
            else if(item < parrent->Data){
                parrent->Left = locptr;
            }
            else{
                parrent->Right = locptr;
            }
        }
        else{
            cout << "Item already in the list" << endl;
        }
    }   
};

int main(void){
    
}
