#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MOTS 100
#define MAX_LONGUEUR_MESSAGE 256

typedef struct {
    char contenu[MAX_LONGUEUR_MESSAGE];
    int estSpam; } Email;


void calculerFrequences(char mots[MAX_MOTS][MAX_LONGUEUR_MESSAGE], int *frequences, Email *donnees, int taille, int estSpam) {
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

double calculerProbabilite(char mots[MAX_MOTS][MAX_LONGUEUR_MESSAGE], int *frequences, int totalClasse, char *message) {
    double probabilite = 1.0;

    for (int i = 0; i < MAX_MOTS; i++) {
        if (strstr(message, mots[i]) != NULL) {
            probabilite *= ((double)frequences[i] + 1) / (totalClasse + MAX_MOTS); // Lissage de Laplace
        }
    }
    return probabilite;
}

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


    int frequencesSpam[MAX_MOTS], frequencesNonSpam[MAX_MOTS];
    calculerFrequences(mots, frequencesSpam, donnees, tailleDonnees, 1); 
    calculerFrequences(mots, frequencesNonSpam, donnees, tailleDonnees, 0);

    int totalSpam = 0, totalNonSpam = 0;
    for (int i = 0; i < tailleDonnees; i++) {
        if (donnees[i].estSpam == 1) totalSpam++;
        else totalNonSpam++;
    }
    char messageTest[MAX_LONGUEUR_MESSAGE];
    printf("Entrez un message à analyser : ");
    fgets(messageTest, MAX_LONGUEUR_MESSAGE, stdin);
    messageTest[strcspn(messageTest, "\n")] = 0; 
  
    double probSpam = ((double)totalSpam / tailleDonnees) * 
                      calculerProbabilite(mots, frequencesSpam, totalSpam, messageTest);
    double probNonSpam = ((double)totalNonSpam / tailleDonnees) * 
                         calculerProbabilite(mots, frequencesNonSpam, totalNonSpam, messageTest);

    if (probSpam > probNonSpam) {
        printf("Le message est classé comme SPAM.\n");
    } else {
        printf("Le message est classé comme NON-SPAM.\n");
    }

    return 0;
}