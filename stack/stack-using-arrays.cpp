#include<bits/stdc++.h>
using namespace std;

class Stack{
    private :
    int *a;
    int top ;
    int cap;

    public:
    Stack(int cp){
        top = -1;
        cap = cp;
        a = new int[cp];
    }
    ~Stack(){
        delete[] a;
    }

    void push(int ele){
        if(top >= cap - 1){
            cout << "stack full " << endl;
            return;
        }

        a[++top] = ele;
    }
    
    int pop(){
        if(top < 0){
            cout << "can't pop" << endl;
            return -1;
        }
        return a[top--];
    }

    bool isEmpty(){
        return top < 0;
    }

    int peek(){
        if(top < 0){
            cout << "stack empty"<<endl;
            return -1;
        }
        return a[top];
    }
};

int main(){
    Stack s(5); 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " popped from stack\n"; 

    cout << "Top element is: " << s.peek() << endl; 

    cout << "Elements present in stack: "; 
    while (!s.isEmpty()) { 
        cout << s.peek() << " "; 
        s.pop(); 
    } 


return 0;
}