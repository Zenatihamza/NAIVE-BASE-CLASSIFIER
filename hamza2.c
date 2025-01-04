int frequencesSpam[MAX_MOTS], frequencesNonSpam[MAX_MOTS];
    calculerFrequences(mots, frequencesSpam, donnees, tailleDonnees, 1); 
    calculerFrequences(mots, frequencesNonSpam, donnees, tailleDonnees, 0);

    int totalSpam = 0, totalNonSpam = 0;
    for (int i = 0; i < tailleDonnees; i++) {
        if (donnees[i].estSpam == 1) totalSpam++;
        else totalNonSpam++;
    }