/**
 * Complex factorial program using tail recursion
 */

int factorial_helper(int n, int f) {

    if (n <= 1) {
        return f;
    }

    return factorial_helper(n - 1, n * f);
}

int factorial(int n) {
    return factorial_helper(n, 1);
}
}
