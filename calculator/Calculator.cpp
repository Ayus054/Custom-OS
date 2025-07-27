#include <iostream>
using namespace std;

class Calculator {
public:
    static int add(int a, int b) {
        return a + b;
    }

    static int subtract(int a, int b) {
        return a - b;
    }

    static int multiply(int a, int b) {
        return a * b;
    }

    static double divide(int a, int b) {
        if (b == 0) {
            cerr << "Error: Division by zero!" << endl;
            return 0;
        }
        return (double)a / b;
    }
};

// Example usage
/*int main() {
    cout << "Add: " << Calculator::add(5, 3) << endl;
    cout << "Subtract: " << Calculator::subtract(5, 3) << endl;
    cout << "Multiply: " << Calculator::multiply(5, 3) << endl;
    cout << "Divide: " << Calculator::divide(5, 3) << endl;
    return 0;
}*/