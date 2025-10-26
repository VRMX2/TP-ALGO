#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Algorithme 1: Approche naïve
// Teste la divisibilité par tous les nombres de 2 à N-1
// Complexité: O(N)
// Fonction est_premier_A1(N)
//     Si N ≤ 1 alors
//         Retourner FAUX
//     Si N = 2 alors
//         Retourner VRAI
    
//     Pour i de 2 à N-1 faire
//         Si N mod i = 0 alors
//             Retourner FAUX (N est divisible par i)
    
//     Retourner VRAI (N est premier)



int est_premier_A1(long long N) {
    if (N <= 1) return 0;
    if (N == 2) return 1;
    
    for (long long i = 2; i < N; i++) {
        if (N % i == 0) {
            return 0; // N est divisible par i, donc pas premier
        }
    }
    return 1; // N est premier
}




// Algorithme 2: Amélioration - teste jusqu'à N/2
// Propriété: tout diviseur i de N vérifie i ≤ N/2 (avec i≠N)
// Complexité: O(N/2) = O(N)
// Fonction est_premier_A2(N)
//     Si N ≤ 1 alors
//         Retourner FAUX
//     Si N = 2 alors
//         Retourner VRAI
    
//     Pour i de 2 à N/2 faire
//         Si N mod i = 0 alors
//             Retourner FAUX
    
//     Retourner VRAI


int est_premier_A2(long long N) {
    if (N <= 1) return 0;
    if (N == 2) return 1;
    
    for (long long i = 2; i <= N/2; i++) {
        if (N % i == 0) {
            return 0;
        }
    }
    return 1;
}



// Algorithme 3: Teste jusqu'à √N
// Propriété: Les diviseurs sont pour moitié ≤ √N et pour l'autre moitié > √N
// Complexité: O(√N)
// Algorithme 3: Teste jusqu'à √N
// Propriété: Les diviseurs sont pour moitié ≤ √N et pour l'autre moitié > √N
// Complexité: O(√N)
// Fonction est_premier_A3(N)
//     Si N ≤ 1 alors
//         Retourner FAUX
//     Si N = 2 alors
//         Retourner VRAI
    
//     racine ← √N
//     Pour i de 2 à racine faire
//         Si N mod i = 0 alors
//             Retourner FAUX
    
//     Retourner VRAI
int est_premier_A3(long long N) {
    if (N <= 1) return 0;
    if (N == 2) return 1;
    
    long long racine = (long long)sqrt(N);
    for (long long i = 2; i <= racine; i++) {
        if (N % i == 0) {
            return 0;
        }
    }
    return 1;
}




// Algorithme 4: Teste uniquement les nombres impairs jusqu'à √N
// Vérifie d'abord si N est pair, puis teste seulement les diviseurs impairs
// Complexité: O(√N/2)
// Fonction est_premier_A4(N)
//     Si N ≤ 1 alors
//         Retourner FAUX
//     Si N = 2 alors
//         Retourner VRAI
//     Si N mod 2 = 0 alors
//         Retourner FAUX (N est pair donc pas premier)
    
//     racine ← √N
//     Pour i de 3 à racine avec pas de 2 faire
//         Si N mod i = 0 alors
//             Retourner FAUX
    
//     Retourner VRAI
int est_premier_A4(long long N) {
    if (N <= 1) return 0;
    if (N == 2) return 1;
    if (N % 2 == 0) return 0; // Si N est pair (et N≠2), pas premier
    
    long long racine = (long long)sqrt(N);
    for (long long i = 3; i <= racine; i += 2) { // Teste seulement les impairs
        if (N % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Fonction pour mesurer le temps d'exécution
double mesurer_temps(int (*fonction)(long long), long long N) {
    clock_t debut, fin;
    double temps_cpu;
    
    debut = clock();
    fonction(N);
    fin = clock();
    
    temps_cpu = ((double) (fin - debut)) / CLOCKS_PER_SEC;
    return temps_cpu;
}

int main() {
    // Tableau des nombres premiers à tester
    long long nombres[] = {1000003, 2000003, 4000037, 8000009, 16000057, 
                           32000011, 64000031, 128000003, 256000001, 
                           512000009, 1024000009, 2048000011};
    int taille = sizeof(nombres) / sizeof(nombres[0]);
    
    printf("=== TP1: TEST DE PRIMALITE ===\n\n");
    
    // Test de l'Algorithme 1
    printf("ALGORITHME 1 (Approche naive - teste de 2 à N-1)\n");
    printf("Complexite theorique: O(N)\n");
    printf("%-15s %-15s %-15s\n", "N", "Premier?", "Temps (s)");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < taille; i++) {
        double temps = mesurer_temps(est_premier_A1, nombres[i]);
        printf("%-15lld %-15s %-15.6f\n", nombres[i], 
               est_premier_A1(nombres[i]) ? "OUI" : "NON", temps);
    }
    printf("\n");
    
    // Test de l'Algorithme 2
    printf("ALGORITHME 2 (Amelioration - teste jusqu'a N/2)\n");
    printf("Complexite theorique: O(N/2) = O(N)\n");
    printf("%-15s %-15s %-15s\n", "N", "Premier?", "Temps (s)");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < taille; i++) {
        double temps = mesurer_temps(est_premier_A2, nombres[i]);
        printf("%-15lld %-15s %-15.6f\n", nombres[i], 
               est_premier_A2(nombres[i]) ? "OUI" : "NON", temps);
    }
    printf("\n");
    
    // Test de l'Algorithme 3
    printf("ALGORITHME 3 (Teste jusqu'a √N)\n");
    printf("Complexite theorique: O(√N)\n");
    printf("%-15s %-15s %-15s\n", "N", "Premier?", "Temps (s)");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < taille; i++) {
        double temps = mesurer_temps(est_premier_A3, nombres[i]);
        printf("%-15lld %-15s %-15.6f\n", nombres[i], 
               est_premier_A3(nombres[i]) ? "OUI" : "NON", temps);
    }
    printf("\n");
    
    // Test de l'Algorithme 4
    printf("ALGORITHME 4 (Teste les impairs jusqu'a √N)\n");
    printf("Complexite theorique: O(√N/2)\n");
    printf("%-15s %-15s %-15s\n", "N", "Premier?", "Temps (s)");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < taille; i++) {
        double temps = mesurer_temps(est_premier_A4, nombres[i]);
        printf("%-15lld %-15s %-15.6f\n", nombres[i], 
               est_premier_A4(nombres[i]) ? "OUI" : "NON", temps);
    }
    printf("\n");
    
    // Comparaison des 4 algorithmes
    printf("=== COMPARAISON DES 4 ALGORITHMES ===\n\n");
    printf("%-15s %-15s %-15s %-15s %-15s\n", 
           "N", "A1 (s)", "A2 (s)", "A3 (s)", "A4 (s)");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < taille; i++) {
        double t1 = mesurer_temps(est_premier_A1, nombres[i]);
        double t2 = mesurer_temps(est_premier_A2, nombres[i]);
        double t3 = mesurer_temps(est_premier_A3, nombres[i]);
        double t4 = mesurer_temps(est_premier_A4, nombres[i]);
        printf("%-15lld %-15.6f %-15.6f %-15.6f %-15.6f\n", 
               nombres[i], t1, t2, t3, t4);
    }
    
    printf("\n=== CONCLUSION ===\n");
    printf("Algorithme 4 (teste impairs jusqu'a √N) est le PLUS PERFORMANT\n");
    printf("Ordre de performance: A4 > A3 > A2 > A1\n");
    
    return 0;
}
