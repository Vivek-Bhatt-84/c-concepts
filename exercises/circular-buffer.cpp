#include <iostream>
#include <memory>
#include <vector>

using namespace std;
template <typename T>
class CircularBuffer{
    T buffer_cap;
    T size;
    T front;
    T back;
    vector<shared_ptr<T>> buffer;
public:

    CircularBuffer(T cap) : buffer_cap(cap) , size(0) , front(0) , back(0),buffer(cap){}

    void push(shared_ptr<T> item ){
        if(size == buffer_cap){
            cout << "Buffer full , can't store anything " << endl;
            front = (front + 1) % buffer_cap;
        }
        else{
            size++;
        }
        buffer[back] = item;
        back = (back + 1) % buffer_cap;
    }

    shared_ptr<T> pop(){
        if(size == 0){
            cout << "Buffer empty " << endl;
            return nullptr;
        }
        shared_ptr<T> ret_val = buffer[front];
        front = (front + 1) % buffer_cap;
        size-- ;
        return ret_val;
    }

    bool isEmpty(){ 
        return size == 0;
    }

    bool isFull(){
        return size == buffer_cap;
    }

    T sizeb(){
        return size;
    }

    shared_ptr<T> peekFront(){
        if(size == 0){
            cout << "BUffer empty " << endl;
            return nullptr;
        }
         shared_ptr<T> tmp = buffer[front];
        return tmp;
    }
    shared_ptr<T> peekBack(){
        if(size == 0){
            cout << "BUffer empty " << endl;
            return nullptr;
        }
         shared_ptr<T> tmp = buffer[back];
        return tmp;
    }
};

int main()
{

    CircularBuffer<int> cb(3);

    cb.push(make_shared<int>(3));
    cb.push(make_shared<int>(2));
    cb.push(make_shared<int>(1));

    cout << *cb.pop() << endl; 
    cout << *cb.pop() << endl; 

    if(cb.isEmpty()){
        cout << "buffer full " << endl;
    }
    else{
        cout << "not full" << endl;
    }

    cout << cb.sizeb() << endl;

    cout << *cb.peekBack() << endl;
    cout << *cb.peekFront() << endl;

return 0;
}