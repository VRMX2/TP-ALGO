#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// Vérifie si un nombre est premier (pour long long)
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0 && n != 2) return false;
    for (long long i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Génère N nombres premiers aléatoires dans une plage [min, max]
void generatePrimesInRange(long long *arr, int n, long long min, long long max) {
    int count = 0;
    while (count < n) {
        long long num = ((long long)rand() * RAND_MAX + rand()) % (max - min + 1) + min;
        if (isPrime(num)) {
            int exists = 0;
            for (int i = 0; i < count; i++) {
                if (arr[i] == num) {
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                arr[count++] = num;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    long long primes3[10], primes6[10], primes9[10], primes12[10];

    printf("⏳ Génération des nombres premiers... cela peut prendre un peu de temps...\n");

    generatePrimesInRange(primes3, 10, 100, 999);
    generatePrimesInRange(primes6, 10, 100000, 999999);
    generatePrimesInRange(primes9, 10, 100000000LL, 999999999LL);
    generatePrimesInRange(primes12, 10, 100000000000LL, 999999999999LL);

    FILE *f = fopen("Test-3.txt", "w");
    if (f == NULL) {
        printf("Erreur lors de la création du fichier.\n");
        return 1;
    }

    fprintf(f, "Test-3 - Nombres premiers structurés (3, 6, 9, et 12 chiffres)\n\n");

    fprintf(f, "👉 10 nombres premiers à 3 chiffres :\n");
    for (int i = 0; i < 10; i++) fprintf(f, "%lld ", primes3[i]);
    fprintf(f, "\n\n");

    fprintf(f, "👉 10 nombres premiers à 6 chiffres :\n");
    for (int i = 0; i < 10; i++) fprintf(f, "%lld ", primes6[i]);
    fprintf(f, "\n\n");

    fprintf(f, "👉 10 nombres premiers à 9 chiffres :\n");
    for (int i = 0; i < 10; i++) fprintf(f, "%lld ", primes9[i]);
    fprintf(f, "\n\n");

    fprintf(f, "👉 10 nombres premiers à 12 chiffres :\n");
    for (int i = 0; i < 10; i++) fprintf(f, "%lld ", primes12[i]);
    fprintf(f, "\n\n");

    fclose(f);
    printf("✅ Fichier 'Test-3.txt' créé avec succès (40 nombres premiers structurés).\n");

    return 0;
}
