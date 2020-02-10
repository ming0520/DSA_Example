#include <iostream>

using namespace std;

class BST{
    public:
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

    int NodeCounter;
    Node *Root;
//============================================================================
// Purpose       : Construct a BST object.
// Precondition  : None.
// Postcondition : An empty BST has been constructed.
//============================================================================
    BST(void){
        Root = 0;
        NodeCounter = 0;
    }
//============================================================================
// Purpose       : Check if BST is empty.
// Precondition  : None.
// Postcondition : Returns true if BST is empty and false otherwise.
//============================================================================
    bool Empty(void){
        return (Root == 0);
    }

//============================================================================
// Purpose       : Search the BST for item.
// Precondition  : None.
// Postcondition : Returns true if item found, and false otherwise.
//============================================================================
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
//============================================================================
// Purpose       : Insert item into BST.
// Precondition  : None.
// Postcondition : BST has been modified with item inserted at proper 
//                 position to maintain BST property. 
//============================================================================
    void Insert(int item){
        Node *locptr, *parent;
        bool found = false;
        locptr = Root;
        parent = 0;
        
        while(!found && locptr != 0){
            parent = locptr;
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
            if(parent == 0){
                Root =locptr;
            }
            else if(item < parent->Data){
                parent->Left = locptr;
            }
            else{
                parent->Right = locptr;
            }
            NodeCounter++;
        }
        else{
            cout << "Item already in the list" << endl;
        }
    } 
//============================================================================
// Purpose       : Find Min value in non empty BST
// Precondition  : None
// Postcondition : Return address of min value in BST
//============================================================================
    Node *minValueNode(){
        Node *current = Root;
        while(current && current->Left != 0){
            current = current->Left;
        }

        return current;
    }    
//============================================================================
// Purpose       : Remove item from BST.
// Precondition  : None.
// Postcondition : BST has been modified with item removed (if present);
//                 BST property is maintained.
// Note          : remove uses auxiliary function search2() to locate the node
//                 containing item and its parent.
//============================================================================
/* Scenario for delete
    1. Empty tree
    2. Node to be deleted is leaf
    3. Node to be deleted has only one child
    3. Node to be deleted has only two child
*/    
    void Remove(int item){
        bool found;
        Node *x, *parent;
        //search2(item,found,x,parent);
        x = Root;
        parent = 0;
        found = false;
        while(!found && x != 0){
            if(item < x->Data){
                parent = x;
                x = x->Left;
            }
            else if(x->Data < item){
                parent = x;
                x = x->Right;
            }
            else{
                found = true;
            }
        }

        if(!found){
            cout << "Item not in the BST\n";
            return;
        }

        if(x->Left != 0 && x->Right != 0){ //Node has two child
            Node *xSucc = x->Right;
            parent = x;
            while(xSucc->Left != 0){ //decend left = find smallest
                parent = xSucc;
                xSucc = xSucc->Left;
            }

            //move contens of xSucc to x and change xSucc
            //to point of successor, which will be removed.
            x->Data = xSucc->Data;
            x = xSucc;
        } // end if node has two child

        // Now proceed with case where node has 0 or 2 child
        Node *subtree = x->Left;
        if(subtree == 0){
            subtree = x->Right;
        }
        if(parent == 0){
            Root = subtree;
        }
        else if(parent->Left == x){
            parent->Left = subtree;
        }
        else{
            parent->Right = subtree;
        }
        NodeCounter--;
        delete x;


    }

    //============================================================================
    // Purpose       :
    // Precondition  :
    // Postcondition :
    //============================================================================
    void print2D(void)  
    {  
        // Pass initial space count as 0  
        print2DUtil(Root, 0);  
    }  

//============================================================================
// Purpose       : Inorder traversal of BST.
// Precondition  : ostream out is open.
// Postcondition : BST has been inorder traversed and values in nodes 
//                 have been output to out.
// Note          : inorder uses private auxiliary function inorderAux().
//============================================================================    

    void Inorder(void){
        
    }

//============================================================================
// Purpose       : Graphic output of BST.
// Precondition  : ostream out is open.
// Postcondition : Graphical representation of BST has been output to out.
// Note          : inorder uses private auxiliary function graphAux().
//============================================================================       
    void Graph(void){

    }
    



    private:
  //============================================================================
  // Purpose       : Locate a node containing item and its parent.
  // Precondition  : None.
  // Postcondition : locptr points to node containing item or is
  //                 null if not found, and parent points to its parent
  //============================================================================

    void search2(int &item, bool &found, Node *locptr, Node *parent){
        locptr = Root;
        parent = 0;
        found = false;

        while(!found && locptr != 0){
            if(item < locptr->Data){
                parent = locptr;
                locptr = locptr->Left;
            }
            else if(item > locptr->Data){
                parent = locptr;
                locptr = locptr->Right;
            }
            else{
                found = true;
            }
        }

    }
    //============================================================================
    // Purpose       : Function to print binary tree in 2D  
    // Precondition  : None
    // Postcondition : None
    //============================================================================
    void print2DUtil(Node *root, int space)  
    {  
        // Base case  
        if (root == NULL)  
            return;  
    
        // Increase distance between levels  
        space += NodeCounter;  
    
        // Process right child first  
        print2DUtil(root->Right, space);  
    
        // Print current node after space  
        // count  
        cout<<endl;  
        for (int i = NodeCounter; i < space; i++)  
            cout<<" ";  
        cout<<root->Data<<"\n";  
    
        // Process left child  
        print2DUtil(root->Left, space);  
    }  
    //============================================================================
    // Purpose       : Inorder traversal auxiliary function.
    // Precondition  : ostream out is open; subtreePtr points to a subtree of 
    //                 this BST.
    // Postcondition : Subtree of this BST with subtreePtr as root has been 
    //                 output to out.
    //============================================================================

    void inorderAux(Node subtreePtr){

    }
    
    //============================================================================
    // Purpose       : Graph auxiliary function.
    // Precondition  : ostream out is open; subtreePtr points to a subtree 
    //                 of this BST.
    // Postcondition : Graphical representation of subtree of this 
    //                 BST with subtreePtr as root has been output to out, 
    //                 indented indent spaces.
    //============================================================================

    void graphAux(int indent, Node subtreeRoot){

    }
};

int main(void){
    cout << "Creating BST..." << endl;
    BST bst1;
    bst1.Insert(30);
    bst1.Insert(20);
    bst1.Insert(10);
    bst1.Insert(50);
    bst1.Insert(90);
    bst1.Insert(85);
    cout << "30, 20, 10, 50, 90, 85 inserted!" << endl;
    bst1.Remove(85);
    cout << "85 removed" << endl;
    if(bst1.Search(85) == true){
        cout << "85 is in the list" << endl;
    }
    else{
        cout << "85 is not in the list" << endl;
    }
    bst1.print2D();
}
