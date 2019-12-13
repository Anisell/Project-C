#include <stdio.h>
#include <string.h>
#include "repondre.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum 
{
MESSAGE,
CLOUMNS
};

void envoyer_reponce(Reponce r)
{

FILE *f;
f=fopen("repondre.txt","a+");
	if(f!=NULL)
	{
	fprintf(f,"%s\n",r.message);
fclose(f);
	}
}
void afficher_reponce(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter	iter;
GtkListStore *store;

char message[30];

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("message", renderer, "text",MESSAGE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	

store=gtk_list_store_new (1, G_TYPE_STRING);
f=fopen("repondre.txt", "r");
if(f==NULL)
{
return;
}
else
{ f = fopen("repondre.txt","a+");
	while(fscanf(f,"%s\n",message)!=EOF)
	{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,MESSAGE,message, -1);
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
}
}
}
