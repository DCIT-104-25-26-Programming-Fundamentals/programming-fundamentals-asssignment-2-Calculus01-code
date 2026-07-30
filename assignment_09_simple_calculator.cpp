// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void displayMenu();
void add();
void subtract();
void multiply();
void divide();
void modulus();
void exponentiation();

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
            cout << endl;
            continue;
        }

        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: modulus(); break;
            case 6: exponentiation(); break;
            case 7: cout << "Goodbye!" << endl; break;
            default: cout << "Invalid choice. Please select an option from 1-7." << endl; break;
        }
        cout << endl;
    } while (choice != 7);

    return 0;
}

void displayMenu() {
    cout << "============================" << endl;
    cout << "      SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

void add() {
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << fixed << setprecision(2);
    cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
}

void subtract() {
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << fixed << setprecision(2);
    cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
}

void multiply() {
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << fixed << setprecision(2);
    cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
}

void divide() {
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    if (num2 == 0) {
        cout << "Error: Cannot divide by zero." << endl;
    } else {
        cout << fixed << setprecision(2);
        cout << "Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
    }
}

void modulus() {
    int num1, num2;
    cout << "Enter first number (integer): ";
    cin >> num1;
    cout << "Enter second number (integer): ";
    cin >> num2;
    if (num2 == 0) {
        cout << "Error: Cannot divide by zero." << endl;
    } else {
        cout << "Result: " << num1 << " % " << num2 << " = " << (num1 % num2) << endl;
    }
}

void exponentiation() {
    double base, exp;
    cout << "Enter the base number: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exp;
    cout << fixed << setprecision(2);
    cout << "Result: " << base << " ^ " << exp << " = " << pow(base, exp) << endl;
}
