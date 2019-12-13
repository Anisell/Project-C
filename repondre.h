#include <gtk/gtk.h>
typedef struct
{
char message[100];
}Reponce;

void envoyer_reponce(Reponce r);
void afficher_reponce(GtkWidget *liste);
