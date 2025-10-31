#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Codes couleur ANSI
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Algorithme 1: Approche naive
int estPremier_A1(long long N) {
    if (N <= 1) return 0;
    if (N == 2) return 1;
    
    for (long long i = 2; i < N; i++) {
        if (N % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Algorithme 2: Amelioration - teste jusqu'a N/2
int estPremier_A2(long long N) {
    if (N <= 1) return 0;
    if (N == 2) return 1;
    
    for (long long i = 2; i <= N/2; i++) {
        if (N % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Algorithme 3: Optimisation avec racine carree
int estPremier_A3(long long N) {
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

// Algorithme 4: Optimisation avec nombres impairs
int estPremier_A4(long long N) {
    if (N <= 1) return 0;
    if (N == 2) return 1;
    if (N % 2 == 0) return 0;
    
    long long racine = (long long)sqrt(N);
    for (long long i = 3; i <= racine; i += 2) {
        if (N % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Fonction pour mesurer le temps d'execution (amelioree pour plus de precision)
double mesurer_temps(int (*fonction)(long long), long long N) {
    clock_t debut, fin;
    double temps_cpu;
    int iterations = 1;
    
    // Pour les algorithmes rapides, faire plusieurs iterations
    debut = clock();
    for (int i = 0; i < iterations; i++) {
        fonction(N);
    }
    fin = clock();
    
    temps_cpu = ((double) (fin - debut)) / CLOCKS_PER_SEC / iterations;
    
    // Si le temps est trop petit, augmenter les iterations
    if (temps_cpu < 0.001 && temps_cpu > 0) {
        iterations = 100;
        debut = clock();
        for (int i = 0; i < iterations; i++) {
            fonction(N);
        }
        fin = clock();
        temps_cpu = ((double) (fin - debut)) / CLOCKS_PER_SEC / iterations;
    }
    
    return temps_cpu;
}

void afficher_ligne(char c) {
    for (int i = 0; i < 60; i++) printf("%c", c);
    printf("\n");
}

void tester_algorithme(int (*fonction)(long long), const char* nom, const char* couleur, long long nombres[], int taille) {
    printf("\n%s%s", BOLD, couleur);
    afficher_ligne('=');
    printf("  %s\n", nom);
    afficher_ligne('=');
    printf("%s", RESET);
    
    printf("%s%-18s %-12s %-20s%s\n", CYAN, "N", "Premier?", "Temps (s)", RESET);
    afficher_ligne('-');
    
    double temps_total = 0;
    for (int i = 0; i < taille; i++) {
        double temps = mesurer_temps(fonction, nombres[i]);
        int premier = fonction(nombres[i]);
        temps_total += temps;
        
        const char* couleur_resultat = premier ? GREEN : RED;
        const char* texte_resultat = premier ? "OUI" : "NON";
        const char* couleur_temps = temps < 0.001 ? GREEN : (temps < 0.1 ? YELLOW : RED);
        
        printf("%-18lld %s%-12s%s %s%-20.6f%s\n", 
               nombres[i], 
               couleur_resultat, texte_resultat, RESET,
               couleur_temps, temps, RESET);
    }
    
    afficher_ligne('-');
    printf("%sTEMPS TOTAL: %.6f secondes%s\n", BOLD, temps_total, RESET);
}

int main() {
    long long nombres[] = {
        1000003, 2000003, 4000037, 8000009, 16000057, 
        32000011, 64000031, 128000003, 256000001, 512000009, 
        1024000009, 2048000011
    };
    int taille = sizeof(nombres) / sizeof(nombres[0]);
    
    printf("\n%s%s", BOLD, CYAN);
    afficher_ligne('=');
    printf("       TP1: TEST DE PRIMALITE - COMPARAISON D'ALGORITHMES\n");
    afficher_ligne('=');
    printf("%s\n", RESET);
    
    printf("%s[!] AVERTISSEMENT: Les algorithmes 1 et 2 peuvent prendre plusieurs minutes%s\n", YELLOW, RESET);
    printf("%s    sur les grands nombres. Patience recommandee!%s\n\n", YELLOW, RESET);
    
    // Test de l'algorithme 1
    printf("%s[*] Demarrage du test de l'algorithme 1...%s\n", MAGENTA, RESET);
    tester_algorithme(estPremier_A1, "ALGORITHME 1 (Naif - teste jusqu'a N-1)", RED, nombres, taille);
    
    // Test de l'algorithme 2
    printf("\n%s[*] Demarrage du test de l'algorithme 2...%s\n", MAGENTA, RESET);
    tester_algorithme(estPremier_A2, "ALGORITHME 2 (Optimise - teste jusqu'a N/2)", YELLOW, nombres, taille);
    
    // Test de l'algorithme 3
    printf("\n%s[*] Demarrage du test de l'algorithme 3...%s\n", MAGENTA, RESET);
    tester_algorithme(estPremier_A3, "ALGORITHME 3 (Optimise - teste jusqu'a racine(N))", GREEN, nombres, taille);
    
    // Test de l'algorithme 4
    printf("\n%s[*] Demarrage du test de l'algorithme 4...%s\n", MAGENTA, RESET);
    tester_algorithme(estPremier_A4, "ALGORITHME 4 (Tres optimise - impairs jusqu'a racine(N))", BLUE, nombres, taille);
    
    // Comparaison directe sur un nombre
    printf("\n%s%s", BOLD, CYAN);
    afficher_ligne('=');
    printf("         COMPARAISON DIRECTE SUR N = 16000057\n");
    afficher_ligne('=');
    printf("%s\n", RESET);
    
    long long N_test = 16000057;
    
    printf("%sAlgorithme 1:%s ", RED, RESET);
    double t1 = mesurer_temps(estPremier_A1, N_test);
    printf("%.6f secondes\n", t1);
    
    printf("%sAlgorithme 2:%s ", YELLOW, RESET);
    double t2 = mesurer_temps(estPremier_A2, N_test);
    printf("%.6f secondes\n", t2);
    
    printf("%sAlgorithme 3:%s ", GREEN, RESET);
    double t3 = mesurer_temps(estPremier_A3, N_test);
    printf("%.6f secondes\n", t3);
    
    printf("%sAlgorithme 4:%s ", BLUE, RESET);
    double t4 = mesurer_temps(estPremier_A4, N_test);
    printf("%.6f secondes\n", t4);
    
    // Calcul des gains de performance avec protection contre division par zero
    printf("\n%s%s", BOLD, MAGENTA);
    afficher_ligne('=');
    printf("            GAINS DE PERFORMANCE\n");
    afficher_ligne('=');
    printf("%s", RESET);
    
    if (t2 > 0.000001) {
        printf("%sA2 vs A1:%s %.2fx plus rapide\n", CYAN, RESET, t1/t2);
    } else {
        printf("%sA2 vs A1:%s %.2fx plus rapide\n", CYAN, RESET, t1/0.000001);
    }
    
    if (t3 > 0.000001) {
		printf("%sA3 vs A2:%s %.2fx plus rapide\n", CYAN, RESET, t2/t3);
    } else {
        printf("%sA3 vs A2:%s Beaucoup plus rapide (temps non mesurable)\n", CYAN, RESET);
    }
    
    if (t4 > 0.000001 && t3 > 0.000001) {
        printf("%sA4 vs A3:%s %.2fx plus rapide\n", CYAN, RESET, t3/t4);
    } else {
        printf("%sA4 vs A3:%s Temps similaires (tous deux tres rapides)\n", CYAN, RESET);
    }
    
    if (t4 > 0.000001) {
        printf("%sA4 vs A1:%s %.2fx plus rapide%s\n\n", BOLD, GREEN, t1/t4, RESET);
    } else {
        printf("%sA4 vs A1:%s Beaucoup plus rapide (facteur > 10000x)%s\n\n", BOLD, GREEN, RESET);
    }
    
    return 0;
}