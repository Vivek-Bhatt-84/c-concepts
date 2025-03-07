// #include <iostream>
// using namespace std;

// double calculateTotal(double price , double taxRate){
//     return price + (price * taxRate);
// }
// double discountedPrice(double price , double discountRate){
//     return price - (price * discountRate);
// }

// int main()
// {

//     double price = 100;
//     double taxRate = 0.1;
//     double discountRate = 0.2;

//     cout << "Total : " << calculateTotal(price , taxRate) << endl;
//     cout << "Discounted price : " << discountedPrice(price , discountRate) << endl;

// return 0;
// }




#include <iostream>
using namespace std;

double calcPercentage(double price , double rate){
    return price * rate;
}

double calculateTotal(double price , double taxRate){
    return price + calcPercentage(price,taxRate);
}
double discountedPrice(double price , double discountRate){
    return price - calcPercentage(price ,discountRate );
}

int main()
{

    double price = 100;
    double taxRate = 0.1;
    double discountRate = 0.2;

    cout << "Total : " << calculateTotal(price , taxRate) << endl;
    cout << "Discounted price : " << discountedPrice(price , discountRate) << endl;

return 0;
}