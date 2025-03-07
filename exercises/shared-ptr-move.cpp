#include <iostream>
using namespace std;

class Shared_ptr{
    int* ptr;
    int* ref_cnt;

    void release(){
        if(ref_cnt){
            (*ref_cnt)--;
            if(*(ref_cnt) == 0){
                delete ptr;
                delete ref_cnt;
            }
        }
        cout << "memory freed" << endl;
    }
public:
    Shared_ptr(int* p = nullptr) : ptr(p) , ref_cnt(p ? new int(1) : nullptr) {}

    Shared_ptr(const Shared_ptr& obj){
        ptr = obj.ptr;
        ref_cnt = obj.ref_cnt;
        if(ref_cnt){
            (*ref_cnt)++;
        }
        cout << "copy conste" << endl;
    }



    int& operator*(){
        return *ptr;
    }
    
    int* operator->(){
        return ptr;
    }

    Shared_ptr& operator=(const Shared_ptr& obj){
        if(this != &obj){
            release();
            ptr = obj.ptr;
            ref_cnt = obj.ref_cnt;
            (*ref_cnt)++;
        }
        return *this;
    }

    int use_cnt(){
        return *ref_cnt;
    }

    ~Shared_ptr(){
        release();
    }

    Shared_ptr( Shared_ptr&& obj){
        ptr = obj.ptr;
        ref_cnt = obj.ref_cnt;
        obj.ptr = nullptr;
        obj.ref_cnt = nullptr;
    }

    Shared_ptr& operator=( Shared_ptr&& obj){
        if(this != &obj){
            release();
            ptr = obj.ptr;
            ref_cnt = obj.ref_cnt;
            obj.ptr = nullptr;
            obj.ref_cnt = nullptr;
        }
        return *this;
    }

   


};

int main()
{
    // Shared_ptr ptr1(new int(10));
    // std::cout << "ptr1 use_count: " << ptr1.use_cnt() << std::endl;

    // {
    //     Shared_ptr ptr2 = ptr1; // Copy constructor
    //     std::cout << "ptr1 use_count after copy: " << ptr1.use_cnt() << std::endl;
    //     std::cout << "ptr2 use_count after copy: " << ptr2.use_cnt() << std::endl;
    // } // ptr2 goes out of scope and is destructed

    // std::cout << "ptr1 use_count after ptr2 destruction: " << ptr1.use_cnt() << std::endl;

    // Shared_ptr p3 = new int(40);
    // Shared_ptr p4 = new int(50);

    // p3.operator=(p4);
    // cout << p3.use_cnt() << endl;

    Shared_ptr sp1(new int(10));  // Create a shared pointer with an integer
    cout << "Reference count after creation: " << sp1.use_cnt() << endl;

    Shared_ptr sp2 = sp1;  // Copy construction
    cout << "Reference count after copy: " << sp1.use_cnt() << endl;

    Shared_ptr sp3 = std::move(sp1);  // Move construction
    cout << "Reference count after move: " << sp3.use_cnt() << endl;

    Shared_ptr sp4;
    sp4 = std::move(sp2);  // Move assignment
    cout << "Reference count after move assignment: " << sp4.use_cnt() << endl;

return 0;
}