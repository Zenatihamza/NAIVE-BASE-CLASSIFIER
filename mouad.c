#define MAX_MOTS 100
#define MAX_LONGUEUR_MESSAGE 256
typedef struct {
    char contenu[MAX_LONGUEUR_MESSAGE];
    int estSpam; } Email;