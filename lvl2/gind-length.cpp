#include <iostream>

int findLength(const char str[]) {
    int count = 0;
    while (str[count] != '\0') {  // Iterate until null character
        count++;
    }
    return count;
}

int main() {
    char str[] = "Hello, World!";
    std::cout << "Length of the string: " << findLength(str) << std::endl;
    return 0;
}
