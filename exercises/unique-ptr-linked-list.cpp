#include <iostream>
#include <memory>
using namespace std;

class Node{
public:
    int data;
    unique_ptr<Node> next;

    Node(int data) : data(data) , next(nullptr){}
};

class LinkedList{
    unique_ptr<Node> head ; 

public:
    LinkedList() : head(nullptr){}

    void insertAtStart(int val){
        auto newNode = make_unique<Node>(val);
        newNode -> next = move(head);
        head = move(newNode);
    }

    void deleteFromBegin(){
        if(head){
            head = move(head -> next);
        }
        else{
            cout << "List is empty " << endl;
        }
    }

    void traverse(){
        Node* curr = head.get();
        while(curr){
            cout << curr -> data << " " ;
            curr = curr -> next.get();
        }
        cout << endl;
    }

    void insertAtEnd(int val){
        if(!head){
            insertAtStart(val);
            return;
        }

        Node* curr = head.get();
        while(curr -> next){
            curr = curr -> next.get();
        }
        curr -> next = make_unique<Node>(val);
    }
};

int main()
{
    LinkedList l;
    l.insertAtStart(2);
    l.insertAtStart(3);
    l.insertAtEnd(10);
    l.insertAtEnd(20);

    l.traverse();

    l.deleteFromBegin();
    l.traverse();
return 0;
}