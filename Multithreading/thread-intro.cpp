// in every application there is default thread called main thread . Inside this we can create other threads
// A thread is also known as lightweight process . Idead is to achieve parallesim by dividing a process into multiple threads .
// example 
//(a.) a browser has  multiple tabs that can be different threads
// (b.) ms word can be using different threads  one thread to format text and another  thread to process inputs (spell character).


/****
 * different ways to create threads 
 * 1. function pointers 
 * 2. Lambda function 
 * 3. functors 
 * 4. member functions
 * 5. static member functions
 * 
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>



using namespace std;
using namespace std :: chrono;
typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;


void findEven(ull start , ull end){
    for(ull i = start ; i <= end ; i++){
        if((i & 1) == 0){
            evenSum += 1;
        }
    }
}

void findOdd(ull start , ull end){
    for(ull i = start ; i <= end ; i++ ){
        if((i & 1) == 1){
            oddSum ++;
        }
    }
}


int main(){

   ull start = 0 , end = 1900000000;

   auto startTime = high_resolution_clock::now();

   thread t1(findEven , start ,end);
   thread t2(findOdd ,start ,end);

   t1.join();
   t2.join();

//    findEven(start,end);
//    findOdd(start,end);

   auto stopTime = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stopTime - startTime);

   cout << "OddSum : " << oddSum << endl;
   cout << "EvenSum : " << evenSum << endl;

   cout << duration.count()/1000000 << endl;

    return 0;
}