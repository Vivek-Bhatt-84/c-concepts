#include <iostream>
#include <cstring>
using namespace std;

class MyString{
char* data;

public : 
    MyString(const char* str){
        data = new char[strlen(str) + 1];
        strcpy(data ,str);
    }

    MyString(MyString)
};

int main()
{

return 0;
}