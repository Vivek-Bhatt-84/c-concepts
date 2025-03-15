// C program to demonstrate the working of #pragma startup
// and #pragma exit

#include <iostream>
using namespace std;

void func1();
void func2();


#pragma startup func1
#pragma exit func2

void func1() { printf("Inside func1()\n"); }

void func2() { printf("Inside func2()\n"); }

int main()
{
	cout << "Inside main/n";

	return 0;
}
