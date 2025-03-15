#include <iostream>
#include <memory>
#include <set>
#include <map>
using namespace std;

void unique_set(){
    set<unique_ptr<int>> s;

    s.insert(make_unique<int>(10));
    s.insert(make_unique<int>(20));
    s.insert(make_unique<int>(30));

    for(auto& ele : s){
        cout << *ele << " ";
    }
}

void unique_arr(){
    unique_ptr<int[]> arr = make_unique<int[]>(5);

    for(int i = 1 ; i < 5 ; i++){
        arr[i] = i * 5;
    }

    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

}

class Person{
public :
    string name;
    int age;

    Person(string n ,int a) : name(n), age(a){}

    void display(){
        cout << name << " is " << age << " years old " << endl;
    }
};

int main()
{

    map<int, unique_ptr<Person>> mp;

    mp[1] = make_unique<Person>("Alice" ,25);
    mp[2] = make_unique<Person>("Bob" ,30);
    mp[3] = make_unique<Person>("charlie" ,35);

    for(auto& pair : mp){
        cout << pair.first << "-> "  << endl;
        pair.second -> display();
    }

return 0;
}