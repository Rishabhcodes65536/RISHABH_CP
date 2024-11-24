#include <iostream>

void generateBrainfuckProgram(int a, int b) {
    std::cout << "[-]" << std::endl;
    
    // Add 'a' to the first cell
    for (int i = 0; i < a; ++i) {
        std::cout << "+";
    }
    std::cout << ">" << std::endl;
    
    // Add 'b' to the second cell
    for (int i = 0; i < b; ++i) {
        std::cout << "+";
    }
    std::cout << std::endl;
    
    // Move to the first cell and start addition
    std::cout << "<[->+<]>" << std::endl;
    
    // Move to the second cell and clean it
    std::cout << "[-<+>]" << std::endl;
    
    // Output the result
    std::cout << "." << std::endl;
}

int main() {
    int a, b;
    std::cout << "Enter two numbers to add: ";
    std::cin >> a >> b;
    std::cout << "Brainfuck program to add " << a << " and " << b << ":\n";
    generateBrainfuckProgram(a, b);
    return 0;
}
