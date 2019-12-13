#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "facture.h"


void
on_buttonretour_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_facture,*afficher_facture;
afficher_facture=lookup_widget(objet,"affiche_facture");

gtk_widget_destroy(afficher_facture);
ajouter_facture=create_ajoute_facture();
gtk_widget_show(ajouter_facture);

}


void
on_buttonmodifier_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *afficher_facture,*fenetre_num;
afficher_facture=lookup_widget(objet,"affiche_facture");

gtk_widget_destroy(afficher_facture);
fenetre_num=create_window1();
gtk_widget_show(fenetre_num);
}


void
on_buttonretour2_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*modifier_facture;
GtkWidget *treeview;
modifier_facture=lookup_widget(objet,"modife_facture");

gtk_widget_destroy(modifier_facture);
fenetre_afficher=create_affiche_facture();
gtk_widget_show(fenetre_afficher);
treeview=lookup_widget(fenetre_afficher,"treeview1");
afficher_facture(treeview);

}


void
on_buttonvalider_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Facture v;
GtkWidget *input1,*input2,*input3,*input4,*input5;
GtkWidget *output;
input1=lookup_widget(objet_graphique,"entry6");
input2=lookup_widget(objet_graphique,"entry7");
input3=lookup_widget(objet_graphique,"entry8");
input4=lookup_widget(objet_graphique,"entry9");
input5=lookup_widget(objet_graphique,"entry10");

output=lookup_widget(objet_graphique,"label32");
strcpy(v.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(v.mode,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.num,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(v.date,gtk_entry_get_text(GTK_ENTRY(input5)));

modifier_facture(v);
gtk_label_set_text(GTK_LABEL(output),"modifié avec succés") ;
}


void
on_buttonrefuser_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{

}


void
on_buttonconfirmer_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{

}


void
on_buttonajouter_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
Facture fa;
GtkWidget *input1, *input2, *input3, *input4, *input5;
GtkWidget *ajoute_facture;



ajoute_facture=lookup_widget(objet,"ajoute_facture");

input1=lookup_widget(objet,"nom");

input2=lookup_widget(objet,"mode");
input3=lookup_widget(objet,"num");
input4=lookup_widget(objet,"prix");
input5=lookup_widget(objet,"date");



strcpy(fa.nom,gtk_entry_get_text(GTK_ENTRY(input1)));

strcpy(fa.mode,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(fa.num,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(fa.prix,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(fa.date,gtk_entry_get_text(GTK_ENTRY(input5)));

ajouter_facture(fa);
}


void
on_buttonafficher_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_facture;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
ajouter_facture=lookup_widget(objet,"ajoute_facture");

fenetre_afficher=create_affiche_facture();
gtk_widget_show(fenetre_afficher);
gtk_widget_hide(ajouter_facture);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_facture(treeview1);
}


void
on_buttonconfirmer1_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char refe[20];
int test;
Facture v;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6;
GtkWidget *window1,*window2;
GtkWidget *output;

window2=create_modife_facture();
input1=lookup_widget(objet_graphique,"entry_num");
input2=lookup_widget(window2,"entry6");
input3=lookup_widget(window2,"entry7");
input4=lookup_widget(window2,"entry8");
input5=lookup_widget(window2,"entry9");
input6=lookup_widget(window2,"entry10");

output= lookup_widget(objet_graphique,"label31");
strcpy(refe,gtk_entry_get_text(GTK_ENTRY(input1)));
if (verifier_ref(refe)==0)
gtk_label_set_text(GTK_LABEL(output),"Fatcure inexistante");
else
{
FILE *f2;
f2=fopen("facture.txt","r"); 
if (f2!=NULL)
{while (fscanf(f2,"%s %s %s %s %s\n",v.nom,v.mode,v.num,v.prix,v.date)!=EOF)
{if (strcmp(v.num,refe)==0) 
{ gtk_widget_show(window2);
gtk_entry_set_text(GTK_ENTRY(input2),v.nom) ;
gtk_entry_set_text(GTK_ENTRY(input3),v.mode) ;
gtk_entry_set_text(GTK_ENTRY(input4),v.num) ;
gtk_entry_set_text(GTK_ENTRY(input5),v.prix) ;
gtk_entry_set_text(GTK_ENTRY(input6),v.date) ;

window1=lookup_widget(objet_graphique,"window1");
gtk_widget_destroy(window1);
break ;}}
}
fclose(f2);
}
}


void
on_buttonsupprimer_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *afficher_facture,*fenetre_nums;
afficher_facture=lookup_widget(objet,"affiche_facture");

gtk_widget_destroy(afficher_facture);
fenetre_nums=create_window2();
gtk_widget_show(fenetre_nums);
}


void
on_buttoncomfirmer2_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output1;
Facture b;
char refer[20];
input1=lookup_widget(objet_graphique,"entrynum");
output1=lookup_widget(objet_graphique,"label35");
strcpy(refer,gtk_entry_get_text(GTK_ENTRY(input1)));
if(verifier_ref(refer)==0)
gtk_label_set_text(GTK_LABEL(output1),"facture inexistante");
else
{
supprimer_facture(refer);
gtk_label_set_text(GTK_LABEL(output1),"facture supprimé");
}
}


void
on_buttonretour3_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1, *Window2;
GtkWidget *treeview;
window1=lookup_widget(objet_graphique,"window2");
gtk_widget_hide(window1);
Window2 = create_affiche_facture();
gtk_widget_show (Window2);
treeview=lookup_widget(Window2,"treeview1");
afficher_facture(treeview);

}



