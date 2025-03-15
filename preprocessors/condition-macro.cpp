#include <iostream>
// #define FEATURE_ENABLE
using namespace std;

int main()
{
    #ifdef FEATURE_ENABLE
    cout << "feature is enabled" << endl;
    #else
    cout << "feature is not enabled " << endl;
    #endif

return 0;
}