#include <iostream>

int main() {
    std::cout << "Hello, world!\n";
    
    int y{};
    std::cout << "Please enter a number: ";
    std::cin >> y;

    std::cout << "The input is: " << y << '\n';
    return 0;
}
