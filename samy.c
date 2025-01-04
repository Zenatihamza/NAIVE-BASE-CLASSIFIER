double calculerProbabilite(char mots[MAX_MOTS][MAX_LONGUEUR_MESSAGE], int *frequences, int totalClasse, char *message) {
    double probabilite = 1.0;

    for (int i = 0; i < MAX_MOTS; i++) {
        if (strstr(message, mots[i]) != NULL) {
            probabilite *= ((double)frequences[i] + 1) / (totalClasse + MAX_MOTS); // Lissage de Laplace
        }
    }
    return probabilite;
}


