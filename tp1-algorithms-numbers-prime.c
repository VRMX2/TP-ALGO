#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime1(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPrime2(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPrime3(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}


int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("\nResults for n = %d\n", n);
    printf("-----------------------------\n");
    printf("Algorithm 1 : %s\n", isPrime1(n) ? "Prime" : "Not Prime");
    printf("Algorithm 2 : %s\n", isPrime2(n) ? "Prime" : "Not Prime");
    printf("Algorithm 3 : %s\n", isPrime3(n) ? "Prime" : "Not Prime");

    printf("-----------------------------\n");
    printf("Program executed successfully.\n");

    return 0;
}
