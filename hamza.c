void calculerFrequences(char mots[MAX_MOTS][MAX_LONGUEUR_MESSAGE], int frequences, Emaildonnees, int taille, int estSpam) {
    for (int i = 0; i < MAX_MOTS; i++) {
        frequences[i] = 0;
    }

    for (int i = 0; i < taille; i++) {
        if (donnees[i].estSpam == estSpam) {
            for (int j = 0; j < MAX_MOTS; j++) {
                if (strstr(donnees[i].contenu, mots[j]) != NULL) {
                    frequences[j]++;
                }
            }
        }
    }
}