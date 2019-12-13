#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"
#include "repondre.h"


void
on_buttonpresedent_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_rec,*f_client;
fenetre_rec=lookup_widget(objet,"reclamation");

gtk_widget_destroy(fenetre_rec);
f_client=create_window7();
gtk_widget_show(f_client);
}


void
on_buttonenvoyer_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_buttonpresedent3_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1, *Window2;
GtkWidget *treeview;
window1=lookup_widget(objet_graphique,"window3");
gtk_widget_hide(window1);
Window2 = create_window4();
gtk_widget_show (Window2);
treeview=lookup_widget(Window2,"treeview1");
afficher_reclamation(treeview);
}


void
on_buttonenvoyer1_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
Reponce r;
GtkWidget *input1;
GtkWidget *Envoyer_reponce;




Envoyer_reponce=lookup_widget(objet,"window3");

input1=lookup_widget(objet,"entrymessage3");

strcpy(r.message,gtk_entry_get_text(GTK_ENTRY(input1)));

envoyer_reponce(r);
}


void
on_buttonsupprimer_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *reclamation_liste,*Window5;
reclamation_liste=lookup_widget(objet,"window4");

gtk_widget_destroy(reclamation_liste);
Window5=create_window5();
gtk_widget_show(Window5);
}

void
on_buttonretour_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *reclamation_liste,*Window7;
reclamation_liste=lookup_widget(objet,"window4");

gtk_widget_destroy(reclamation_liste);
Window7=create_window7();
gtk_widget_show(Window7);
}


void
on_buttonretour1_clicked               (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1, *Window2;
GtkWidget *treeview;
window1=lookup_widget(objet_graphique,"window5");
gtk_widget_hide(window1);
Window2 = create_window4();
gtk_widget_show (Window2);
treeview=lookup_widget(Window2,"treeview1");
afficher_reclamation(treeview);
}


void
on_buttonvalider_clicked               (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output1;
Reclamation b;
char rec[20];
input1=lookup_widget(objet_graphique,"entryCIN");
output1=lookup_widget(objet_graphique,"label29");
strcpy(rec,gtk_entry_get_text(GTK_ENTRY(input1)));
if(verifier_cin(rec)==0)
gtk_label_set_text(GTK_LABEL(output1),"Reclamation inexistante");
else
{
supprimer_reclamation(rec);
gtk_label_set_text(GTK_LABEL(output1),"Reclamation supprimé");
}
}

void
on_buttonreponder1_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

}

void
on_buttonenvoyer2_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
Reclamation r;
GtkWidget *input1, *input2, *input3, *input4;
GtkWidget *Envoyer_reclamation;




Envoyer_reclamation=lookup_widget(objet,"reclamation");

input1=lookup_widget(objet,"nom");

input2=lookup_widget(objet,"prenom");
input3=lookup_widget(objet,"cin");
input4=lookup_widget(objet,"description");




strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(input1)));

strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(r.description,gtk_entry_get_text(GTK_ENTRY(input4)));

envoyer_reclamation(r);

}


void
on_buttonafficher_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *treeview;


treeview=lookup_widget(objet,"treeview1");
afficher_reclamation(treeview);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	gchar *Nom;
	gchar *Prenom;
	gchar *CIN;

GtkWidget *Window4;
GtkWidget *Window3;
GtkTreeIter iter;

Window4=lookup_widget(treeview,"window4");

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&Nom,1,&Prenom,2,&CIN,-1);}
Window3 = create_window3();
gtk_widget_show(Window3);
gtk_widget_destroy(Window4);
}


void
on_buttonretour4_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_reponce,*f_client;
fenetre_reponce=lookup_widget(objet,"window6");

gtk_widget_destroy(fenetre_reponce);
f_client=create_window7();
gtk_widget_show(f_client);

}


void
on_buttonquitter_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_buttonajouter_rec_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *f_client,*Window1;
f_client=lookup_widget(objet,"window7");

gtk_widget_destroy(f_client);
Window1=create_reclamation();
gtk_widget_show(Window1);
}




void
on_buttonrep_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *f_client,*Window6;
f_client=lookup_widget(objet,"window7");

gtk_widget_destroy(f_client);
Window6=create_window6();
gtk_widget_show(Window6);
}




void
on_buttonafficher4_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview;


treeview=lookup_widget(objet,"treeview2");
afficher_reponce(treeview);
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *Message;
	

GtkWidget *Window6;
GtkWidget *Window8;
GtkTreeIter iter;

Window6=lookup_widget(treeview,"window6");

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&Message,-1);}
Window8 = create_window8();
gtk_widget_show(Window8);
gtk_widget_destroy(Window6);
}


void
on_buttonretour5_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_reponce,*Window8;
Window8=lookup_widget(objet,"window8");

gtk_widget_destroy(Window8);
fenetre_reponce=create_window6();
gtk_widget_show(fenetre_reponce);
}

