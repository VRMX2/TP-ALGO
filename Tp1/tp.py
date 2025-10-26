import matplotlib.pyplot as plt
import numpy as np

# Données des nombres testés
N = np.array([1000003, 2000003, 4000037, 8000009, 16000057, 
              32000011, 64000031, 128000003, 256000001, 
              512000009, 1024000009, 2048000011])

# Vous devez remplacer ces valeurs par vos mesures réelles
# Temps mesurés pour chaque algorithme (en secondes)
# IMPORTANT: Remplacez ces valeurs par vos propres mesures!
T_A1 = np.array([0.001, 0.002, 0.004, 0.008, 0.016, 0.032, 0.064, 0.128, 0.256, 0.512, 1.024, 2.048])
T_A2 = np.array([0.0005, 0.001, 0.002, 0.004, 0.008, 0.016, 0.032, 0.064, 0.128, 0.256, 0.512, 1.024])
T_A3 = np.array([0.0001, 0.0001, 0.0002, 0.0003, 0.0004, 0.0006, 0.0008, 0.001, 0.0015, 0.002, 0.003, 0.004])
T_A4 = np.array([0.00005, 0.00005, 0.0001, 0.00015, 0.0002, 0.0003, 0.0004, 0.0005, 0.0007, 0.001, 0.0015, 0.002])

# Complexités théoriques (normalisées pour visualisation)
O_A1 = N  # O(N)
O_A2 = N / 2  # O(N/2)
O_A3 = np.sqrt(N)  # O(√N)
O_A4 = np.sqrt(N) / 2  # O(√N/2)

# ===== GRAPHE 1: Temps d'exécution T(N) pour tous les algorithmes =====
plt.figure(figsize=(14, 8))

plt.subplot(2, 2, 1)
plt.plot(N, T_A1, 'ro-', label='A1: Naïf (2 à N-1)', linewidth=2, markersize=8)
plt.xlabel('N (taille du nombre)', fontsize=12)
plt.ylabel('Temps T (secondes)', fontsize=12)
plt.title('Algorithme 1 - Temps d\'exécution T(N)', fontsize=14, fontweight='bold')
plt.grid(True, alpha=0.3)
plt.legend(fontsize=10)

plt.subplot(2, 2, 2)
plt.plot(N, T_A2, 'go-', label='A2: Jusqu\'à N/2', linewidth=2, markersize=8)
plt.xlabel('N (taille du nombre)', fontsize=12)
plt.ylabel('Temps T (secondes)', fontsize=12)
plt.title('Algorithme 2 - Temps d\'exécution T(N)', fontsize=14, fontweight='bold')
plt.grid(True, alpha=0.3)
plt.legend(fontsize=10)

plt.subplot(2, 2, 3)
plt.plot(N, T_A3, 'bo-', label='A3: Jusqu\'à √N', linewidth=2, markersize=8)
plt.xlabel('N (taille du nombre)', fontsize=12)
plt.ylabel('Temps T (secondes)', fontsize=12)
plt.title('Algorithme 3 - Temps d\'exécution T(N)', fontsize=14, fontweight='bold')
plt.grid(True, alpha=0.3)
plt.legend(fontsize=10)

plt.subplot(2, 2, 4)
plt.plot(N, T_A4, 'mo-', label='A4: Impairs jusqu\'à √N', linewidth=2, markersize=8)
plt.xlabel('N (taille du nombre)', fontsize=12)
plt.ylabel('Temps T (secondes)', fontsize=12)
plt.title('Algorithme 4 - Temps d\'exécution T(N)', fontsize=14, fontweight='bold')
plt.grid(True, alpha=0.3)
plt.legend(fontsize=10)

plt.tight_layout()
plt.savefig('graphe_temps_separes.png', dpi=300, bbox_inches='tight')
print("✓ Graphe 1 sauvegardé: graphe_temps_separes.png")

# ===== GRAPHE 2: Comparaison des 4 algorithmes =====
plt.figure(figsize=(12, 7))
plt.plot(N, T_A1, 'ro-', label='A1: Naïf (2 à N-1)', linewidth=2, markersize=8)
plt.plot(N, T_A2, 'go-', label='A2: Jusqu\'à N/2', linewidth=2, markersize=8)
plt.plot(N, T_A3, 'bo-', label='A3: Jusqu\'à √N', linewidth=2, markersize=8)
plt.plot(N, T_A4, 'mo-', label='A4: Impairs jusqu\'à √N', linewidth=2, markersize=8)
plt.xlabel('N (taille du nombre)', fontsize=14)
plt.ylabel('Temps T (secondes)', fontsize=14)
plt.title('Comparaison des 4 algorithmes - Temps d\'exécution', fontsize=16, fontweight='bold')
plt.legend(fontsize=12)
plt.grid(True, alpha=0.3)
plt.savefig('graphe_comparaison_temps.png', dpi=300, bbox_inches='tight')
print("✓ Graphe 2 sauvegardé: graphe_comparaison_temps.png")

# ===== GRAPHE 3: Complexités théoriques O(N) =====
plt.figure(figsize=(12, 7))
# Normalisation pour visualisation
facteur = 1e-9  # Facteur d'échelle pour rendre les courbes visibles
plt.plot(N, O_A1 * facteur, 'r--', label='O(N) - A1', linewidth=2.5)
plt.plot(N, O_A2 * facteur, 'g--', label='O(N/2) - A2', linewidth=2.5)
plt.plot(N, O_A3 * facteur, 'b--', label='O(√N) - A3', linewidth=2.5)
plt.plot(N, O_A4 * facteur, 'm--', label='O(√N/2) - A4', linewidth=2.5)
plt.xlabel('N (taille du nombre)', fontsize=14)
plt.ylabel('Complexité O(N) (normalisée)', fontsize=14)
plt.title('Complexités théoriques au pire cas', fontsize=16, fontweight='bold')
plt.legend(fontsize=12)
plt.grid(True, alpha=0.3)
plt.savefig('graphe_complexites_theoriques.png', dpi=300, bbox_inches='tight')
print("✓ Graphe 3 sauvegardé: graphe_complexites_theoriques.png")

# ===== GRAPHE 4: Comparaison A1 vs A2 =====
plt.figure(figsize=(12, 7))
plt.plot(N, T_A1, 'ro-', label='A1: Naïf (2 à N-1)', linewidth=2, markersize=10)
plt.plot(N, T_A2, 'go-', label='A2: Jusqu\'à N/2', linewidth=2, markersize=10)
plt.xlabel('N (taille du nombre)', fontsize=14)
plt.ylabel('Temps T (secondes)', fontsize=14)
plt.title('Comparaison A1 vs A2', fontsize=16, fontweight='bold')
plt.legend(fontsize=12)
plt.grid(True, alpha=0.3)
plt.savefig('graphe_A1_vs_A2.png', dpi=300, bbox_inches='tight')
print("✓ Graphe 4 sauvegardé: graphe_A1_vs_A2.png")

# ===== GRAPHE 5: Comparaison A1, A2, A3 =====
plt.figure(figsize=(12, 7))
plt.plot(N, T_A1, 'ro-', label='A1: Naïf (2 à N-1)', linewidth=2, markersize=10)
plt.plot(N, T_A2, 'go-', label='A2: Jusqu\'à N/2', linewidth=2, markersize=10)
plt.plot(N, T_A3, 'bo-', label='A3: Jusqu\'à √N', linewidth=2, markersize=10)
plt.xlabel('N (taille du nombre)', fontsize=14)
plt.ylabel('Temps T (secondes)', fontsize=14)
plt.title('Comparaison A1 vs A2 vs A3', fontsize=16, fontweight='bold')
plt.legend(fontsize=12)
plt.grid(True, alpha=0.3)
plt.savefig('graphe_A1_A2_A3.png', dpi=300, bbox_inches='tight')
print("✓ Graphe 5 sauvegardé: graphe_A1_A2_A3.png")

# ===== GRAPHE 6: Échelle logarithmique =====
plt.figure(figsize=(12, 7))
plt.semilogy(N, T_A1, 'ro-', label='A1: Naïf', linewidth=2, markersize=8)
plt.semilogy(N, T_A2, 'go-', label='A2: N/2', linewidth=2, markersize=8)
plt.semilogy(N, T_A3, 'bo-', label='A3: √N', linewidth=2, markersize=8)
plt.semilogy(N, T_A4, 'mo-', label='A4: Impairs √N', linewidth=2, markersize=8)
plt.xlabel('N (taille du nombre)', fontsize=14)
plt.ylabel('Temps T (secondes) - échelle log', fontsize=14)
plt.title('Comparaison avec échelle logarithmique', fontsize=16, fontweight='bold')
plt.legend(fontsize=12)
plt.grid(True, alpha=0.3, which='both')
plt.savefig('graphe_echelle_log.png', dpi=300, bbox_inches='tight')
print("✓ Graphe 6 sauvegardé: graphe_echelle_log.png")

print("\n" + "="*60)
print("TOUS LES GRAPHES ONT ÉTÉ GÉNÉRÉS AVEC SUCCÈS!")
print("="*60)
print("\nFichiers créés:")
print("  1. graphe_temps_separes.png")
print("  2. graphe_comparaison_temps.png")
print("  3. graphe_complexites_theoriques.png")
print("  4. graphe_A1_vs_A2.png")
print("  5. graphe_A1_A2_A3.png")
print("  6. graphe_echelle_log.png")
print("\n⚠️  N'OUBLIEZ PAS: Remplacez les valeurs T_A1, T_A2, T_A3, T_A4")
print("    par vos PROPRES MESURES obtenues avec votre programme C!")