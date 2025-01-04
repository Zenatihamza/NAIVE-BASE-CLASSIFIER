char messageTest[MAX_LONGUEUR_MESSAGE];
    printf("Entrez un message à analyser : ");
    fgets(messageTest, MAX_LONGUEUR_MESSAGE, stdin);
    messageTest[strcspn(messageTest, "\n")] = 0; 

    double probSpam = ((double)totalSpam / tailleDonnees) * 
                      calculerProbabilite(mots, frequencesSpam, totalSpam, messageTest);
    double probNonSpam = ((double)totalNonSpam / tailleDonnees) * 
                         calculerProbabilite(mots, frequencesNonSpam, totalNonSpam, messageTest);