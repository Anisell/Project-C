#include <stdio.h>
#include <string.h>
#include "reclamation.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{
	NOM,
	PRENOM,
	CIN,
	DESCRIPTION,
	COLUMNS
};

void envoyer_reclamation(Reclamation r)
{

FILE *f;
f=fopen("reclamation.txt","a+");
	if(f!=NULL)
	{
	fprintf(f,"%s %s %s %s \n",r.nom,r.prenom,r.cin,r.description);
fclose(f);
	}
}

void afficher_reclamation(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter	iter;
GtkListStore *store;

char nom[30];
char prenom[30];
char cin[30];
char description[30];

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",PRENOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",CIN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("description", renderer, "text",DESCRIPTION, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	

store=gtk_list_store_new (4, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("reclamation.txt", "r");
if(f==NULL)
{
return;
}
else
{ f = fopen("reclamation.txt","a+");
	while(fscanf(f,"%s %s %s %s \n",nom,prenom,cin,description)!=EOF)
	{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,NOM,nom,PRENOM,prenom,CIN, cin,DESCRIPTION, description, -1);
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
}
}
}
int verifier_cin(char cin[])
{Reclamation m;
FILE *f;
int test = 0 ; 
f=fopen("reclamation.txt","r");
if(f!=NULL) { 
while(fscanf(f,"%s %s %s %s\n",m.nom,m.prenom,m.cin,m.description)!=EOF) 
{ 
if((strcmp(m.cin,cin)==0))
test=1 ;
 } }
fclose(f);
 
return test;
}
int supprimer_reclamation(char rec[])
{
FILE *f,*f1;
Reclamation a;
 
f=fopen("reclamation.txt","r"); 
f1=fopen("tmp.txt","w");
 if ((f!=NULL) && (f1!=NULL))
{
while(fscanf(f,"%s %s %s %s \n",a.nom,a.prenom,a.cin,a.description)!=EOF) 
{
if(strcmp(rec,a.cin)!=0)
{
fprintf(f1,"%s %s %s %s \n",a.nom,a.prenom,a.cin,a.description);
}}
fclose(f) ; 
fclose(f1);}
 
f=fopen("reclamation.txt","w"); 
f1=fopen("tmp.txt","r");
if ((f!=NULL) && (f1!=NULL))
{
while(fscanf(f1,"%s %s %s %s \n",a.nom,a.prenom,a.cin,a.description)!=EOF) 
{
if(strcmp(rec,a.cin)!=0)
{
fprintf(f,"%s %s %s %s \n",a.nom,a.prenom,a.cin,a.description);
}}
fclose(f) ; 
fclose(f1);
}}
 

