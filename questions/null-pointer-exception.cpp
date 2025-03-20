#include<bits/stdc++.h>
using namespace std;

void checkNull(int* ptr){
    if(ptr == nullptr){
        throw runtime_error("NULL pointer exception ");
    }
    cout << "Value " << *ptr << endl;

}

int main(){
    int* ptr = nullptr;

    try{
        checkNull(ptr);

    }
    catch(exception& e){
        cout << "exception : " << e.what() << endl;
    }

return 0;
}