/**macros are way to define a code that is replaced by prepossesor before 
 * the code is compiled  . Macros are often used in constants , inline code snippets  , and simple functions  
 * defined using #define
 * 
 */


#include <iostream>
#define PI 3.14159
#define SQUARE(x) ((x)*(x))
using namespace std;

int main()
{
    cout << "Value of pi : " << PI << endl;
    int res = SQUARE(5);
    cout << res << endl;

return 0;
}