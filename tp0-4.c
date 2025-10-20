#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// Vérifie si un nombre est premier
bool isPrime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0 && n != 2) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Génère N nombres premiers aléatoires dans une plage [min, max]
void generatePrimesInRange(int *arr, int n, int min, int max) {
    int count = 0;
    while (count < n) {
        int num = (rand() % (max - min + 1)) + min;
        if (isPrime(num)) {
            // Vérifier si le nombre est déjà pris
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

    int primes3[10], primes4[10], primes5[10], primes6[10];

    generatePrimesInRange(primes3, 10, 100, 999);
    generatePrimesInRange(primes4, 10, 1000, 9999);
    generatePrimesInRange(primes5, 10, 10000, 99999);
    generatePrimesInRange(primes6, 10, 100000, 999999);

    FILE *f = fopen("Test-2.txt", "w");
    if (f == NULL) {
        printf("Erreur lors de la création du fichier.\n");
        return 1;
    }

    fprintf(f, "Test-2 - Nombres premiers aléatoires contrôlés par nombre de chiffres\n\n");

    fprintf(f, "👉 10 nombres premiers à 3 chiffres :\n");
    for (int i = 0; i < 10; i++) fprintf(f, "%d ", primes3[i]);
    fprintf(f, "\n\n");

    fprintf(f, "👉 10 nombres premiers à 4 chiffres :\n");
    for (int i = 0; i < 10; i++) fprintf(f, "%d ", primes4[i]);
    fprintf(f, "\n\n");

    fprintf(f, "👉 10 nombres premiers à 5 chiffres :\n");
    for (int i = 0; i < 10; i++) fprintf(f, "%d ", primes5[i]);
    fprintf(f, "\n\n");

    fprintf(f, "👉 10 nombres premiers à 6 chiffres :\n");
    for (int i = 0; i < 10; i++) fprintf(f, "%d ", primes6[i]);
    fprintf(f, "\n\n");

    fclose(f);
    printf("✅ Fichier 'Test-2.txt' créé avec succès (40 nombres premiers répartis par taille).\n");

    return 0;
}
