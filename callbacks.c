#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include"voyage.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include"personnereserve.h"


void
on_button100_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window81;
	GtkWidget *window9;
	window81=lookup_widget(objet,"window81");	
	window9 = create_window9();
	gtk_widget_destroy(window81);
	gtk_widget_show(window9);
}


void
on_button101_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
Vorganise V;
GtkWidget *treeview2;
GtkWidget *window81;

//window2=lookup_widget(objet,"window2");	
		//window1= create_window1();
		//gtk_widget_destroy(window1);
gtk_widget_show(window81);
treeview2=lookup_widget(objet,"treeview2");
afficher_Vorganisee(treeview2);
}


void
on_button102_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window81;
	GtkWidget *window10;
	window81=lookup_widget(objet,"window81");	
	window10 = create_window10();
	gtk_widget_destroy(window81);
	gtk_widget_show(window10);
}


void
on_button103_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window12;
	GtkWidget *window8;
	window8=lookup_widget(objet,"window8");	
	window12 = create_window12();
	gtk_widget_destroy(window8);
	gtk_widget_show(window12);
}


void
on_button104_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
Vorganise V;
//GtkWidget *entry1;
	GtkWidget *entry100;
	GtkWidget *entry101;
	GtkWidget *entry130;
        GtkWidget *entry102;
	GtkWidget *entry103;
        GtkWidget *entry131;

	GtkWidget *window9;
  	//GtkWidget *window9;

	window9=lookup_widget(objet,"window9");	
	entry100=lookup_widget(objet, "entry100");
	entry101=lookup_widget(objet, "entry101");
	entry130=lookup_widget(objet, "entry130");
	entry102=lookup_widget(objet, "entry102");
        entry103=lookup_widget(objet, "entry103");
        entry131=lookup_widget(objet, "entry131");
	

	strcpy(V.destination,gtk_entry_get_text(GTK_ENTRY(entry100)));
	strcpy(V.date_aller,gtk_entry_get_text(GTK_ENTRY(entry101)));
	strcpy(V.date_retour,gtk_entry_get_text(GTK_ENTRY(entry130)));
	strcpy(V.prix,gtk_entry_get_text(GTK_ENTRY(entry102)));
	strcpy(V.hebergement,gtk_entry_get_text(GTK_ENTRY(entry103)));
	strcpy(V.reference,gtk_entry_get_text(GTK_ENTRY(entry131)));
        
ajouter_Vorganise(V);
}


void
on_button105_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window81;
	GtkWidget *window9;
	window9=lookup_widget(objet,"window9");	
	window81 = create_window81();
	gtk_widget_destroy(window9);
	gtk_widget_show(window81);
}


void
on_button106_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window81;
	GtkWidget *window10;
	window10=lookup_widget(objet,"window10");	
	window81 = create_window81();
	gtk_widget_destroy(window10);
	gtk_widget_show(window81);
}


void
on_button107_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
//GtkWidget *window11;
	//GtkWidget *window10;
	//window10=lookup_widget(objet,"window10");	
	//window11 = create_window11();
	//gtk_widget_destroy(window10);
	//gtk_widget_show(window11);
char REF[20];
int test;
Vorganise V;
GtkWidget *entry104,*entry105,*entry106,*entry150,*entry107,*entry108,*entry151;
GtkWidget *window5,*window11;
GtkWidget *output;
window11=create_window11();
entry104=lookup_widget(objet,"entry104");
entry105=lookup_widget(window11,"entry105");
entry106=lookup_widget(window11,"entry106");
entry150=lookup_widget(window11,"entry150");
entry107=lookup_widget(window11,"entry107");
entry108=lookup_widget(window11,"entry108");
entry151=lookup_widget(window11,"entry151");


output= lookup_widget(objet,"label108");
strcpy(REF,gtk_entry_get_text(GTK_ENTRY(entry104)));
if (verifier_ref(REF)==0)
gtk_label_set_text(GTK_LABEL(output),"ref n'existe pas");
else
{
FILE *f2;
f2=fopen("voyage.txt","r"); 
if (f2!=NULL)
{while (fscanf(f2,"%s %s %s %s %s %s %s \n",V.destination,V.date_aller,V.date_retour,V.prix,V.hebergement,V.reference)!=EOF)
{if (strcmp(V.reference,REF)==0) 
{ gtk_widget_show(window11);
gtk_entry_set_text(GTK_ENTRY(entry105),V.destination) ;
gtk_entry_set_text(GTK_ENTRY(entry106),V.date_aller) ;
gtk_entry_set_text(GTK_ENTRY(entry150),V.date_retour) ;
gtk_entry_set_text(GTK_ENTRY(entry107),V.prix) ;
gtk_entry_set_text(GTK_ENTRY(entry108),V.hebergement) ;
gtk_entry_set_text(GTK_ENTRY(entry151),V.reference) ;

break ;}}
}
fclose(f2);
}		
}
void
on_button108_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
Vorganise v;
GtkWidget *entry105,*entry106,*entry150,*entry107,*entry108,*entry151;
GtkWidget *output;
entry105=lookup_widget(objet,"entry105");
entry106=lookup_widget(objet,"entry106");
entry150=lookup_widget(objet,"entry150");
entry107=lookup_widget(objet,"entry107");
entry108=lookup_widget(objet,"entry108");
entry151=lookup_widget(objet,"entry151");
//entry16=lookup_widget(objet,"entry16");
output=lookup_widget(objet,"label114");
strcpy(v.destination,gtk_entry_get_text(GTK_ENTRY(entry105)));
strcpy(v.date_aller,gtk_entry_get_text(GTK_ENTRY(entry106)));
strcpy(v.date_retour,gtk_entry_get_text(GTK_ENTRY(entry150)));
strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(entry107)));
strcpy(v.hebergement,gtk_entry_get_text(GTK_ENTRY(entry108)));
strcpy(v.reference,gtk_entry_get_text(GTK_ENTRY(entry151)));

modifier_Vorganise(v);
gtk_label_set_text(GTK_LABEL(output),"modifié avec succés") ;

}
void
on_button109_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window12;
	GtkWidget *window10;
	window12=lookup_widget(objet,"window12");	
	window10 = create_window10();
	gtk_widget_destroy(window12);
	gtk_widget_show(window10);

}

void
on_button110_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *entry20;
GtkWidget *output17;
Vorganise V;
char refer[20];
entry20=lookup_widget(objet,"entry109");
output17=lookup_widget(objet,"label117");
strcpy(refer,gtk_entry_get_text(GTK_ENTRY(entry20)));
if(verifier_ref(refer)==0)
gtk_label_set_text(GTK_LABEL(output17),"ref inexistante");
else
{
supprimer_Vorganise(refer);
gtk_label_set_text(GTK_LABEL(output17),"agent supprimé");
}
}

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	gchar *destination;
	gchar *date_aller;
	gchar *date_retour;
        gchar *prix;
        gchar *hebergement;
        gchar  *reference;
GtkWidget *Window14;
GtkWidget *Window13;
GtkTreeIter iter;

Window13=lookup_widget(treeview,"window13");

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&destination,1,&date_aller,2,&date_retour,3,&prix,4,&hebergement,5,&reference,-1);}
Window14 = create_window14();
gtk_widget_show(Window14);
gtk_widget_destroy(Window13);

}


void
on_button111_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *treeview;
window1=lookup_widget(objet,"window13");
//gtk_widget_hide(window1);
//Window2 = create_window14();
//gtk_widget_show (Window2);
treeview=lookup_widget(objet,"treeview3");
afficher_Vorganisee(treeview);
}


void
on_button112_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button113_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data)
{
Personneresv P;
//GtkWidget *entry1;
	GtkWidget *entry152;
	GtkWidget *entry153;
	GtkWidget *entry154;
        GtkWidget *entry155;
	GtkWidget *entry156;
        

	GtkWidget *window14;
  	//GtkWidget *window9;

	window14=lookup_widget(objet,"window14");	
	entry152=lookup_widget(objet, "entry152");
	entry153=lookup_widget(objet, "entry153");
	entry154=lookup_widget(objet, "entry154");
	entry155=lookup_widget(objet, "entry155");
        entry156=lookup_widget(objet, "entry156");
        
	

	strcpy(P.nom,gtk_entry_get_text(GTK_ENTRY(entry152)));
	strcpy(P.prenom,gtk_entry_get_text(GTK_ENTRY(entry153)));
	strcpy(P.cin,gtk_entry_get_text(GTK_ENTRY(entry154)));
	strcpy(P.mail,gtk_entry_get_text(GTK_ENTRY(entry155)));
	strcpy(P.reference,gtk_entry_get_text(GTK_ENTRY(entry156)));
	
        
ajouter_Personneresv(P);
}


void
on_button114_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data)
{
Personneresv P;
GtkWidget *treeview2;
GtkWidget *window15;

//window2=lookup_widget(objet,"window2");	
		//window1= create_window1();
		//gtk_widget_destroy(window1);
gtk_widget_show(window15);
treeview2=lookup_widget(objet,"treeview4");
afficher_Personneresv(treeview2);
}


void
on_button115_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window15;
	GtkWidget *window16;
	window15=lookup_widget(objet,"window15");	
	window16 = create_window16();
	gtk_widget_destroy(window15);
	gtk_widget_show(window16);
}


void
on_button116_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *window15;
	GtkWidget *window18;
	window15=lookup_widget(objet,"window15");	
	window18 = create_window18();
	gtk_widget_destroy(window15);
	gtk_widget_show(window18);
}


void
on_button117_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data)
{

}


void
on_button118_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data)
{
char ID[20];
int test;
Personneresv P;
GtkWidget *entry157,*entry158,*entry159,*entry160,*entry161,*entry162;
GtkWidget *window5,*window17;
GtkWidget *output;
window17=create_window17();
entry157=lookup_widget(objet,"entry157");
entry158=lookup_widget(window17,"entry158");
entry159=lookup_widget(window17,"entry159");
entry160=lookup_widget(window17,"entry160");
entry161=lookup_widget(window17,"entry161");
entry162=lookup_widget(window17,"entry162");



output= lookup_widget(objet,"label162");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(entry157)));
if (verifier_id(ID)==0)
gtk_label_set_text(GTK_LABEL(output),"personne n'existe pas");
else
{
FILE *f2;
f2=fopen("personner.txt","r"); 
if (f2!=NULL)
{while (fscanf(f2,"%s %s %s %s %s  \n",P.nom,P.prenom,P.cin,P.mail,P.reference)!=EOF)
{if (strcmp(P.cin,ID)==0) 
{ gtk_widget_show(window17);
gtk_entry_set_text(GTK_ENTRY(entry158),P.nom) ;
gtk_entry_set_text(GTK_ENTRY(entry159),P.prenom) ;
gtk_entry_set_text(GTK_ENTRY(entry160),P.cin) ;
gtk_entry_set_text(GTK_ENTRY(entry161),P.mail) ;
gtk_entry_set_text(GTK_ENTRY(entry162),P.reference) ;


break ;}}
}
fclose(f2);
}		
}


void
on_button119_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data)
{
Personneresv p;
GtkWidget *entry158,*entry159,*entry160,*entry161,*entry162;
GtkWidget *output;
entry158=lookup_widget(objet,"entry158");
entry159=lookup_widget(objet,"entry159");
entry160=lookup_widget(objet,"entry160");
entry161=lookup_widget(objet,"entry161");
entry162=lookup_widget(objet,"entry162");

//entry16=lookup_widget(objet,"entry16");
output=lookup_widget(objet,"label169");
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(entry158)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(entry159)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(entry160)));
strcpy(p.mail,gtk_entry_get_text(GTK_ENTRY(entry161)));
strcpy(p.reference,gtk_entry_get_text(GTK_ENTRY(entry162)));

modifier_Personneresv(p);
gtk_label_set_text(GTK_LABEL(output),"modifié avec succés") ;


}


void
on_button120_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry20;
GtkWidget *output17;
Personneresv P;
char ciin[20];
entry20=lookup_widget(objet,"entry163");
output17=lookup_widget(objet,"label172");
strcpy(ciin,gtk_entry_get_text(GTK_ENTRY(entry20)));
if(verifier_id(ciin)==0)
gtk_label_set_text(GTK_LABEL(output17),"personne inexistante");
else
{
supprimer_Personneresv(ciin);
gtk_label_set_text(GTK_LABEL(output17),"personne supprimé");
}
}


void
on_button121_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window15;
	GtkWidget *window18;
	window18=lookup_widget(objet,"window18");	
	window15 = create_window15();
	gtk_widget_destroy(window18);
	gtk_widget_show(window15);
}

