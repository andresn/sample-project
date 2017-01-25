#include <stdio.h>

// Tail recursive factorial function
long int factorialHelper(long int n, long int f) {
    if (n <= 1) {
        return f;
    }
    return factorialHelper(n - 1, f * n);
}

// Interface to actual factorial function
long int factorial(long int n) {
    return factorialHelper(n, 1);
}

int main() {
    printf("Factorial %ld\n", factorial(4l));
}
