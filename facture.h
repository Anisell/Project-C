#include <gtk/gtk.h>

typedef struct 
{
char nom[20];
char mode[20];
char num[20];
char prix[20];
char date[20];

}Facture;

void ajouter_facture(Facture fa);
void afficher_facture(GtkWidget *liste);
void modifier_facture(Facture m);
int verifier_ref(char ref[]);
int supprimer_facture(char fac[]);
