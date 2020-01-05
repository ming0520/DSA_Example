#include <iostream>
using namespace std;

class LinkedList{
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
	Node *First;
	
	LinkedList(){
		First = 0;
	}
	
	bool Empty(){
		return (First == 0);
	}
	
	void Insert(int item){
		Node *ptr = new Node(item);
		ptr->Next = First;
		First = ptr;
	}
	
	void Remove(void){
		if(Empty()){
			cerr << "Empty List!" << endl;
		}
		else{
			Node *ptr = First;
			First = First->Next;
			delete ptr;
		}
	}
	
	void Display(void){
		if(Empty()){
			cerr << "Empty List!" << endl;
		}
		else{
			for(Node *ptr = First; ptr != 0; ptr = ptr->Next){
				cout << ptr->Data << endl;
			}
		}
	}
};

int main (void){
	LinkedList list;
	for(int i = 0; i < 5; i++){
		list.Insert(i);
	}
	
	list.Display();
	list.Remove();
	list.Display();
	return 0;
}
