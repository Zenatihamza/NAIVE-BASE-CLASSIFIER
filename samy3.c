int main() {
       Email donnees[] = {
        {"Achetez maintenant, offre limitée", 1},
        {"Gagnez un prix incroyable", 1},
        {"Ne manquez pas cette opportunité", 1},
        {"Bonjour, comment ça va ?", 0},
        {"Ceci est un email personnel", 0},
        {"Merci pour votre réponse", 0}
    };
    int tailleDonnees = sizeof(donnees) / sizeof(donnees[0]);

    char mots[MAX_MOTS][MAX_LONGUEUR_MESSAGE] = {
        "achetez", "gagnez", "offre", "prix", "opportunité", "merci", "bonjour"
    };
