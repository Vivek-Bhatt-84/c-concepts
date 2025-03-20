#include <bits/stdc++.h>
using namespace std;


string monthNames[] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};


int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int getDaysInMonth(int month, int year) {
    if (month == 2 && isLeapYear(year)) {
        return 29; 
    }
    return monthDays[month - 1]; 
}


int getFirstDayOfMonth(int month, int year) {
    int d = 1; 
    int y0 = year - (14 - month) / 12;
    int x = y0 + y0 / 4 - y0 / 100 + y0 / 400;
    int m0 = month + 12 * ((14 - month) / 12) - 2;
    int d0 = (d + x + (31 * m0) / 12) % 7;
    return d0; 
}


void displayCalendar(int month, int year) {
    cout << "\n   " << monthNames[month - 1] << " " << year << "\n";
    cout << " Sun Mon Tue Wed Thu Fri Sat\n";

    int firstDay = getFirstDayOfMonth(month, year);
    int daysInMonth = getDaysInMonth(month, year);

   
    for (int i = 0; i < firstDay; i++) {
        cout << "    ";
    }

    
    for (int day = 1; day <= daysInMonth; day++) {
        cout << setw(4) << day; 
        if ((firstDay + day) % 7 == 0) { 
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    int month, year;
    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    if (month < 1 || month > 12 || year < 1) {
        cout << "Invalid input! Please enter a valid month (1-12) and a positive year.\n";
        return 1;
    }

    displayCalendar(month, year);
    return 0;
}
