#include <stdio.h>
#include <string.h>
#include "facture.h"
#include <gtk/gtk.h>

enum
{
client,
paiement,
numfa,
Prix,
Date,
COLUMNS
};

void ajouter_facture(Facture fa)
{
FILE *f;
f=fopen("facture.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s\n",fa.nom,fa.mode,fa.num,fa.prix,fa.date);
fclose(f);
}
}

void afficher_facture(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[30];
char mode[30];
char num[30];
char prix[30];
char date[30];
store=NULL;

FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",client,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("mode",renderer,"text",paiement,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("num",renderer,"text",numfa,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("prix",renderer,"text",Prix,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",Date,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(5,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("facture.txt","r");
if(f==NULL)
{return;}
else
{
f=fopen("facture.txt","a+");
while(fscanf(f,"%s %s %s %s %s\n",nom,mode,num,prix,date)!=EOF)
{
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,client,nom,paiement,mode,numfa,num,Prix,prix,Date,date,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
}
int verifier_ref(char ref[])
{Facture m;
FILE *f;
int test = 0 ; 
f=fopen("facture.txt","r");
if(f!=NULL) { 
while(fscanf(f,"%s %s %s %s %s\n",m.nom,m.mode,m.num,m.prix,m.date)!=EOF) 
{ 
if((strcmp(m.num,ref)==0))
test=1 ;
 } }
fclose(f);
 
return test;
}

void modifier_facture(Facture m)
{
Facture a ;
FILE *f;
FILE *f2;
f=fopen("facture.txt","r");
f2=fopen("fac_tmp.txt","a+"); 
if (f!=NULL)
{
if (f2!=NULL)

{ 
     while (fscanf(f,"%s %s %s %s %s\n",a.nom,a.mode,a.num,a.prix,a.date)!=EOF)
    { 
	if (strcmp(a.num,m.num)==0)
{    fprintf(f2,"%s %s %s %s %s\n",m.nom,m.mode,m.num,m.prix,m.date);
}
	else 	
{	    fprintf(f2,"%s %s %s %s %s\n",a.nom,a.mode,a.num,a.prix,a.date);
     }

}}
fclose(f2);
fclose(f);
remove("facture.txt");
rename("fac_tmp.txt","facture.txt");

}
}
int supprimer_facture(char fac[])
{
FILE *f,*f1;
Facture r;
 
f=fopen("facture.txt","r"); 
f1=fopen("tmp.txt","w");
 if ((f!=NULL) && (f1!=NULL))
{
while(fscanf(f,"%s %s %s %s %s\n",r.nom,r.mode,r.num,r.prix,r.date)!=EOF) 
{
if(strcmp(fac,r.num)!=0)
{
fprintf(f1,"%s %s %s %s %s\n",r.nom,r.mode,r.num,r.prix,r.date);
}}
fclose(f) ; 
fclose(f1);}
 
f=fopen("facture.txt","w"); 
f1=fopen("tmp.txt","r");
if ((f!=NULL) && (f1!=NULL))
{
while(fscanf(f1,"%s %s %s %s %s\n",r.nom,r.mode,r.num,r.prix,r.date)!=EOF) 
{
if(strcmp(fac,r.num)!=0)
{
fprintf(f,"%s %s %s %s %s\n",r.nom,r.mode,r.num,r.prix,r.date);
}}
fclose(f) ; 
fclose(f1);
}}
 

