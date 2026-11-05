#include <iostream>
using namespace std;

// Calculate Fibonacci number using recursion
int fib(int num) {
    if (num == 0 || num == 1)
        return num;

    return fib(num - 1) + fib(num - 2);
}

// Display Fibonacci series using recursion
void recursive(int n) {
    cout << "Recursive\n";

    for (int i = 0; i < n; i++) {
        cout << fib(i) << " ";
    }
    cout << endl;
}

// Display Fibonacci series using iteration
void iterative(int n) {
    int first = 0, second = 1;

    cout << "Non Recursive\n";

    if (n >= 1)
        cout << first << " ";

    if (n >= 2)
        cout << second << " ";

    for (int i = 2; i < n; i++) {
        int next = first + second;
        cout << next << " ";

        first = second;
        second = next;
    }

    cout << endl;
}

int main() {
    int n = 10;

    recursive(n);
    iterative(n);

    return 0;
}
