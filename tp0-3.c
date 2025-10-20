#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// Fonction pour tester si un nombre est premier
bool isPrime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0 && n != 2) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int primes[100];
    int count = 0;
    int lower = 1000, upper = 1000000;

    srand(time(NULL));

    while (count < 100) {
        int num = (rand() % (upper - lower + 1)) + lower;
        if (isPrime(num)) {
            // Vérifier si le nombre est déjà dans la liste
            int exists = 0;
            for (int i = 0; i < count; i++) {
                if (primes[i] == num) {
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                primes[count++] = num;
            }
        }
    }

    FILE *f = fopen("Test-1.txt", "w");
    if (f == NULL) {
        printf("Erreur lors de la création du fichier.\n");
        return 1;
    }

    fprintf(f, "Test-1 - 100 nombres premiers aléatoires dans [1000, 1000000]\n\n");
    for (int i = 0; i < 100; i++) {
        fprintf(f, "%d ", primes[i]);
        if ((i + 1) % 10 == 0) fprintf(f, "\n");
    }

    fclose(f);
    printf("✅ Fichier 'Test-1.txt' créé avec succès (100 nombres premiers aléatoires).\n");

    return 0;
}
