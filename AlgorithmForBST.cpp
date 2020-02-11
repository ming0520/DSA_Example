#include <iostream>

using namespace std;

class BST{
    public:
    class Node{
        public:
        INITIALIZE Data;
        Node *Left;
        Node *Right;

        Node (int item){
            Data SET TO item;
            Left SET TO 0;
            Right SET TO 0;
        }
    };

    INITIALIZE NodeCounter;
    Node *Root;

    BST(void){
        Root SET TO 0;
        NodeCounter SET TO 0;
    }

    bool Empty(void){
        return (Root EQUAL TO 0);
    }

    bool Search(INITIALIZE item){
        Node *locptr SET TO Root;
        bool found SET TO FALSE;
        WHILE TRUE THEN
            IF found OR locptr EQUAL TO 0 THEN
                break;
            }
            IF item SMALLER THAN locptr->Data THEN
                locptr SET TO locptr->Left;
            }
            ELSE IF item LARGER THAN locptr->Data THEN
                locptr SET TO locptr->Right;
            }
            ELSE
                found SET TO TRUE;
            }
        }
        return found;
    }

    void Insert(INITIALIZE item){
        Node *locptr, *parent;
        INITIALIZE found SET TO FALSE;
        locptr SET TO Root;
        parent SET TO 0;
        
        WHILE  NOT found OR locptr NOT EQUAL 0 THEN
            parent SET TO locptr;
            IF item SMALLER THAN locptr->Data THEN
                locptr SET TO locptr->Left;
            }
            ELSE IF item LARGER THAN locptr->Data THEN
                locptr SET TO locptr->Right;
            }
            ELSE
                found SET TO TRUE;
            }
        }

        IF  NOT found THEN
            locptr SET TO new Node(item);
            IF parent EQUAL TO 0 THEN
                Root SET TOlocptr;
            }
            ELSE IF item SMALLER THAN parent->Data THEN
                parent->Left SET TO locptr;
            }
            ELSE
                parent->Right SET TO locptr;
            }
            NodeCounter INCREASE By 1;
        }
        ELSE
            DISPLAY  "Item already in the list" 
        }
    } 

    void Remove(INITIALIZE item){
        bool found;
        Node *x, *parent;

        x SET TO Root;
        parent SET TO 0;
        found SET TO FALSE;
        WHILE  NOT found OR x NOT EQUAL 0 THEN
            IF item SMALLER THAN x->Data THEN
                parent SET TO x;
                x SET TO x->Left;
            }
            ELSE IF x->Data SMALLER THAN item THEN
                parent SET TO x;
                x SET TO x->Right;
            }
            ELSE
                found SET TO TRUE;
            }
        }

        IF  NOT found THEN
            DISPLAY  "Item not in the BST\n";
            return;
        }

        IF x->Left NOT EQUAL 0 OR x->Right NOT EQUAL 0 THEN 
            Node *xSucc SET TO x->Right;
            parent SET TO x;
            WHILE xSucc->Left NOT EQUAL 0 THEN
                parent SET TO xSucc;
                xSucc SET TO xSucc->Left;
            }

            x->Data SET TO xSucc->Data;
            x SET TO xSucc;
        } 
        Node *subtree SET TO x->Left;
        IF subtree EQUAL TO 0 THEN
            subtree SET TO x->Right;
        }
        IF parent EQUAL TO 0 THEN
            Root SET TO subtree;
        }
        ELSE IF parent->Left EQUAL TO x THEN
            parent->Left SET TO subtree;
        }
        ELSE
            parent->Right SET TO subtree;
        }
        NodeCounter--;
        delete x;


    }


    void Display(void)  
    {  
        // Pass initial space count as 0  
        print2DUtil(Root, 0);  
    }  
 
    private:


    void search2(INITIALIZE &item, bool &found, Node *locptr, Node *parent){
        locptr SET TO Root;
        parent SET TO 0;
        found SET TO FALSE;

        WHILE  NOT found OR locptr NOT EQUAL 0 THEN
            IF item SMALLER THAN locptr->Data THEN
                parent SET TO locptr;
                locptr SET TO locptr->Left;
            }
            ELSE IF item LARGER THAN locptr->Data THEN
                parent SET TO locptr;
                locptr SET TO locptr->Right;
            }
            ELSE
                found SET TO TRUE;
            }
        }

    }

    void print2DUtil(Node *root, INITIALIZE space)  
    {  
        if (root EQUAL TO NULL)  
            return;  
            space EQUAL space ADD NodeCounter;  
    
        print2DUtil(root->Right, space);  
    
        DISPLAY newline
        for (INITIALIZE i SET TO NodeCounter; i SMALLER THAN space; i INCREASE By 1)  
            DISPLAY " ";  
        DISPLAY root->Data
    
        print2DUtil(root->Left, space);  
    }  

};
