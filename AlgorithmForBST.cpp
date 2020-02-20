#include <iostream>

using namespace std

class BST{
    public:
    class Node{
        public:
        INITIALIZE Data
        Node *Left
        Node *Right

        Node (int item){
            Data SET TO item
            Left SET TO 0
            Right SET TO 0
        }
    }

    INITIALIZE NodeCounter
    Node *Root

    BST(void){
        Root SET TO 0
        NodeCounter SET TO 0
    }

    bool Empty(void){
        IF Root EQUAL TO 0
            RETURN TRUE
        ELSE
            RETURN FALSE
        END IF    
    }

    bool Search(INITIALIZE item){
        Node *locptr SET TO Root
        INITIALIZE found SET TO FALSE
        WHILE TRUE THEN
            IF found OR locptr EQUAL TO 0 THEN
                break
            END IF    
            IF item SMALLER THAN locptr->Data THEN
                locptr SET TO locptr->Left
            
            ELSE IF item LARGER THAN locptr->Data THEN
                locptr SET TO locptr->Right
            
            ELSE
                found SET TO TRUE
            END IF    
            
        END WHILE
        RETURN found
    }

    void Insert(INITIALIZE item){
        Node *locptr, *parent
        INITIALIZE found SET TO FALSE
        locptr SET TO Root
        parent SET TO 0
        
        WHILE  NOT found OR locptr NOT EQUAL 0 THEN
            parent SET TO locptr
            IF item SMALLER THAN locptr->Data THEN
                locptr SET TO locptr->Left
            ELSE IF item LARGER THAN locptr->Data THEN
                locptr SET TO locptr->Right
            ELSE
                found SET TO TRUE
            END IF    
        END WHILE

        IF  NOT found THEN
            locptr SET TO new Node(item)
            IF parent EQUAL TO 0 THEN
                Root SET TO locptr
            ELSE IF item SMALLER THAN parent->Data THEN
                parent->Left SET TO locptr
            ELSE
                parent->Right SET TO locptr
            END IF    
            NodeCounter INCREASE By 1
        ELSE
            DISPLAY  "Item already in the list" 
        END IF
    } 

    void Remove(INITIALIZE item){
        bool found
        Node *x, *parent

        x SET TO Root
        parent SET TO 0
        found SET TO FALSE
        WHILE  NOT found OR x NOT EQUAL 0 THEN
            IF item SMALLER THAN x->Data THEN
                parent SET TO x
                x SET TO x->Left
            ELSE IF x->Data SMALLER THAN item THEN
                parent SET TO x
                x SET TO x->Right
            ELSE
                found SET TO TRUE
            END IF    
        END WHILE

        IF  NOT found THEN
            DISPLAY  "Item not in the BST\n"
            RETURN
        END IF

        IF x->Left NOT EQUAL 0 OR x->Right NOT EQUAL 0 THEN 
            Node *xSucc SET TO x->Right
            parent SET TO x
            WHILE xSucc->Left NOT EQUAL 0 THEN
                parent SET TO xSucc
                xSucc SET TO xSucc->Left
            END WHILE
            x->Data SET TO xSucc->Data
            x SET TO xSucc
        END IF

        Node *subtree SET TO x->Left
        IF subtree EQUAL TO 0 THEN
            subtree SET TO x->Right
        END IF

        IF parent EQUAL TO 0 THEN
            Root SET TO subtree
        ELSE IF parent->Left EQUAL TO x THEN
            parent->Left SET TO subtree

        ELSE
            parent->Right SET TO subtree
        END IF    
        NodeCounter DECREASE BY 1
        DELETE x


    }


    void Display(void)  
    {  
        // Pass initial space count as 0  
        print2DUtil(Root, 0)  
    }  
 
    private:

    void print2DUtil(Node *root, INITIALIZE space)  
    {  
        IF root EQUAL TO NULL THEN
            RETURN  
            space EQUAL space ADD NodeCounter
        END IF      
    
        print2DUtil(root->Right, space)  
    
        DISPLAY newline
        INITIALIZE i SET TO NodeCounter
        WHILE i SMALLER THAN space THEN
            DISPLAY " "
            i INCREASE By 1
        END WHILE      
        DISPLAY root->Data
    
        print2DUtil(root->Left, space)  
    }  

}
