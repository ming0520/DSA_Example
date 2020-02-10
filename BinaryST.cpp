/*
 * BinaryST.cpp
 *
 *  Created on: 13 May, 2019
 *      Author: User
 */
#include <iostream>
using namespace std;

class BST{
    class Node{
        public:
            int Data;
            Node *Left, *Right;

            Node(int value){  //constructor
                Data = value;
                Left = 0;
                Right = 0;
            }
    };

    Node *myRoot;

    BST(void){  //constructor
        myRoot = 0;
    }

    bool Empty(void){
        return myRoot == 0;
    }

    bool Search(int item){
        Node *locPtr = myRoot;
        bool found = false;

        for(;;){  //an infinite loop
            if(found || locPtr==0)  //0 means null here
                break;  //break when found is true or reached end of tree

            if(item < locPtr->Data)
                locPtr = locPtr->Left;
            else if(locPtr->Data < item)
                locPtr = locPtr->Right;
            else
                found = true;
        }

        return found;
    }

    /*1. find the leaf (new parent)
     *2. add the node to left/right
     *
     *Scenario for insert:
     *1. Empty tree
     *2. Tree with existing value
     *3. Tree without existing value*/

    void Insert(int item){
        Node *locPtr = myRoot;  //search pointer
        Node *parent =0;  //pointer to parent of current node
        bool found = false;  //indicates if item already in BST

        while(!found && locPtr !=0){
            parent = locPtr;
            if(item < locPtr->Data)  //descend left
                locPtr = locPtr->Left;
            else if(locPtr->Data < item)  //descend right
                locPtr = locPtr->Right;
            else
                found = true;  //item found
        }

        if(!found){  //if !found is true then it'll run
            locPtr = new Node(item);
            if(parent==0)  //means empty tree
                myRoot = locPtr;
            else if(item < parent->Data)  //insert to left of parent
                parent->Left = locPtr;
            else
                parent->Right = locPtr;  //insert to right of parent
        }
        else
            cout<<"Item already in the tree"<<endl;
    }

    /*Scenario for delete:
    *1. Empty tree
    *2. Tree without existing value
    *3. Tree with existing value - delete leaf
    *4. Tree with existing value - delete node with 1 child
    *5. Tree with existing value - delete node with 2 children ... leaf/1 child
    *>>>take the smallest value of the right hand side to replace the deleted node
    *>>>take the smallest value of the RHS to replace the deleted node and its only child
    *   replace its place */

    void Remove(int item){
        bool found;  //signals if item is found
        Node *x;  //points to node containing
        Node *parent;  //points to parent of x and xSucc
        //Search2(item, found, x, parent);  //to align the pointers to their destination

        x = myRoot;
        parent = 0;  //parent pointer set to null
        found = false;

        while(!found && x!=0){  //if locPtr is null means empty tree, loop breaks
            if(item < x->Data){  //descend left
                parent = x;
                x = x->Left;
            }
            else if(x->Data < item){  //descend right
                parent = x;
                x = x->Right;
            }
            else
                found = true;  //item found
        }

        if(!found){
            cout<<"Item not in the BST"<<endl;
            return;
        }
        //else
        if(x->Left !=0 && x->Right !=0){  //node has 2 children
            //find x's inorder successor and its parent
            Node *xSucc = x->Right;
            parent = x;
            while(xSucc->Left!=0){  //descend left
                parent = xSucc;
                xSucc = xSucc->Left;
            }

            //Move contents of xSucc to x and change x
            //to point to successor, which will be removed
            x->Data = xSucc->Data;
            x = xSucc;
        }

        //Now proceed with case where node has 0 or 1 child or 2 children
        Node *subtree = x->Left;
        if(subtree==0)  //0 means null here
            subtree = x->Right;

        if(parent==0)  //root being removed
            myRoot = subtree;
        else if(parent->Left == x)  //left child of parent
            parent->Left = subtree;
        else                        //right child of parent
            parent->Right = subtree;

        delete x;
    }

    /*Search2(item, found, x, parent);  //to align the pointers to their destination
     *
     * void Search2(int &item, bool &found, Node *locPtr, Node *parent){
        locPtr = myRoot;
        parent = 0;  //parent pointer set to null
        found = false;

        while(!found && locPtr!=0){  //if locPtr is null means empty tree, loop breaks
            if(item < locPtr->Data){  //descend left
                parent = locPtr;
                locPtr = locPtr->Left;
            }
            else if(locPtr->Data < item){  //descend right
                parent = locPtr;
                locPtr = locPtr->Right;
            }
            else
                found = true;  //item found
        }
    }*/

};

