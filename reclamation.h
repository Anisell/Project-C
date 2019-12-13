#include <gtk/gtk.h>

typedef struct
{
char nom[20];
char prenom[20];
char cin[20];
char description[30];

}Reclamation;

void envoyer_reclamation(Reclamation r);
void afficher_reclamation(GtkWidget *liste);
int supprimer_reclamation(char rec[]);
int verifier_cin(char cin[]);
