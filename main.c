#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#define NMAX 40


    GtkBuilder *builder;//fichier gtk
    /*Menu principal*/
      //window:
    GtkWidget *window;
      //buutons:
    GtkWidget *butt1;
    GtkWidget *butt2;
    GtkWidget *butt3;
    GtkWidget *butt4;


    /*Location*/
      //window:
    GtkWidget *a;
      //butons:
    GtkWidget *a1;
    GtkWidget *a2;
    GtkWidget *a3;
    GtkWidget *a4;
    GtkWidget *a5;
    GtkWidget *a6;

    /*gestion voiture*/
       //window:
    GtkWidget *b;
      //butons:
    GtkWidget *b1;
    GtkWidget *b2;
    GtkWidget *b3;
    GtkWidget *b4;
    GtkWidget *b5;

    /*gestion client*/
       //window:
    GtkWidget *c;
      //butons:
    GtkWidget *c1;
    GtkWidget *c2;
    GtkWidget *c3;
    GtkWidget *c4;
    GtkWidget *c5;


typedef struct client//pour le type client,
	{
		int idclient;
		char nom[20];
		char prenom[20];
		int cin;
		char adresse [15];
		int telephone;
}client;

typedef struct voiture  //pour le type voiture,
	{	int idvoiture;
		char marque[15];
		char nomvoiture[15];
		char couleur[7];
		int nbplaces;
		int prixjour;
		int Enlocation;
}voiture;



//pour le type contrat,
typedef struct date{
	int jour;
	int mois;
	int annee;
}date;

typedef struct contratLocation
 {
 	float numContrat;
 	int idVoiture;
 	int idClient;
 	date debut;
 	date fin;
 	int cout;
 }contrat;


void quitte(){
    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_destroy(window);
}




 	void rta(){
menu_principal();
gtk_widget_destroy(a);
}
void rtb(){
menu_principal();
gtk_widget_destroy(b);
}
void rtc(){
menu_principal();
gtk_widget_destroy(c);
}


 void Visualisercontrat()//1ere fonction,
 {
     gtk_widget_destroy(a);
     float num;
     contrat C;
    voiture V;
 	int i,n;
 	FILE *p=NULL;
 	p=fopen("contrat","r");
 	if(p==NULL){
 	printf("il n'y a pas contrat a visualiser\n");
 	printf("si vous voulez ajouter contrat saisir 1\nsi vous voulez sortier 0\n");
 	scanf("%d",&n);
 	 if(n==1)
        {
            system("cls");
           Ajoutervoiture(V);
        }
        else if(n==0)


        exit(0);

 	}
 	else
 	{
 		printf("entrer le numero de contra qui vous voulez visualiser\n");
 		scanf("%f",&num);

   while(!feof(p))
 	{
 	   fscanf(p,  "%f\t %d\t %d\t %d\t %d\t %d\n",&C.numContrat,&C.idVoiture,&C.idClient,&C.debut.jour,&C.fin.jour,&C.cout);
 	  if(C.numContrat==num)
 	  {      i++;
       printf("---les information de contrat  sont:---\n%f\t %d\t %d\t %d\t %d\t %d\n",C.numContrat,C.idVoiture,C.idClient,C.debut.jour,C.fin.jour,C.cout);
       }
 	}
 		 if(i==0)
 		 printf("ce contrat n'exist pas\n");
 		 printf("\n entrer 0 un de ces nombres ces vous voulez sortie  :\n");
        scanf("%d",&n);
       if(n==1)

        exit(0);

 	}

 	}
 	void louervoiture()//2eme fonction,
{
    int id;
    voiture V;
    gtk_widget_destroy(a);
client  per;

	contrat C;
	FILE *p1=NULL;
	FILE *p2=NULL;
	FILE *p3=NULL;


	int duree;
	int Cout;
	int nbr=0;
    p1=fopen("clients","r");
if(p1==NULL)
	printf("erreur\n");
 else
 {
   printf("entrer l id de ce nouveau client:\n");scanf("%d",&id);

 while(fscanf(p1,"%d\t %s\t %s\t %d\t %s\t %d\t",&per.idclient,per.nom,per.prenom,&per.cin,per.adresse,&per.telephone)!=NULL)
	{
	if(per.idclient==id){
   		printf("ce client exist \n");
	   	nbr++;}
	}

		if(nbr==0){
			printf("ce client n exist pas \n");
			printf("enter ces propre informations :\n");
			 Ajouterclient(per);}
 fclose(p1);
 }
			 system("cls");//puor changer le systeme,
 p2=fopen("voitures","r");
if(p2==NULL)
	printf("erreur\n");
 else{
 	  p3=fopen("contrat","a");

  if(p3==NULL)
    	printf("erreur\n");
  else
	{
	printf("la liste des voitures qui ne sont pas en location :\n");
	while(!feof(p2)	)
	{fscanf(p2,"%d\t %s\t %s\t %s\t %d\t %d\t%d\t",&V.idvoiture,V.marque,V.nomvoiture,&V.couleur,&V.nbplaces,&V.prixjour,&V.Enlocation);
		if(V.Enlocation!=1)
        printf("%d %s %s %s %d %d %d \n",V.idvoiture,V.marque,V.nomvoiture,V.couleur,V.nbplaces,V.prixjour,V.Enlocation);
		}

		printf("entrer l id de la voiture qui vous avez choisi a partir de la liste afficher :\n");
    	scanf("%d",&id);
		printf("___changer la variable en location de cette voiture 0 =>1---\n");
		modifiervoiture(V, id);
		system("cls");
  printf("*********criee le contrat*********\n");
	printf("numero de contrat:\n");
    	scanf("%f",&C.numContrat);
	printf("id de la voiture:\n");
		scanf("%d",&C.idVoiture);
    printf("---------entrer votre id:---------\n");
    	scanf("%d",&C.idClient);
	printf("------enter la date de jour de debut de location:--------\n");
    	scanf("%d",&C.debut.jour);
    printf("----entre la date de jour fin de location:--------\n");
    	scanf("%d",&C.fin.jour);
       printf("la date de jour de debut est:%d est la date de jour fin est:%d\n",C.debut.jour,C.fin.jour);
        duree=C.fin.jour-C.debut.jour;
        Cout=V.prixjour*abs(duree);
        printf("le cout est:%d\n",Cout);
    printf("-------entrer le prix de location :------------\n");
        scanf("%d",&C.cout);

    fprintf(p3,"%f\t %d\t %d\t %d\t %d\t %d\n",C.numContrat,C.idVoiture,C.idClient,C.debut.jour,C.fin.jour,C.cout);
		fclose(p3);
fclose(p2);

}
}
}
void supprimercontrat()//la 3eme fonction,
{
    gtk_widget_destroy(a);
    float num;
    contrat C;
        voiture V;
		FILE *p1=NULL;
		FILE *p2=NULL;
p1=fopen("contrat","r");
if(p1==NULL)
	printf("---------erreur!!!!!!!!!!!!!!!!!1\n");
 else
 {
		p2=fopen("jdid.txt","w");
 if(p2==NULL)
   printf("----------erreur!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
 else
  {
  	printf("--------entrer le numero de contrat qui vous vouler supprimer:---------\n");
		scanf("%f",&num);

	while(!feof(p1))
   {
   	fscanf(p1,  "%f\t %d\t %d\t %d\t  %d\t %d\n",&C.numContrat,&C.idVoiture,&C.idClient,&C.debut.jour,&C.fin.jour,&C.cout);
  if(C.numContrat!=num)
    fprintf(p2,  "%f\t %d\t %d\t %d\t  %d\t %d\n",C.numContrat,C.idVoiture,C.idClient,C.debut.jour,C.fin.jour,C.cout);
   	}
   	fclose(p2);
   	fclose(p1);
   	}}
   	remove("contrat");
    rename("jdid.txt","contrat");

}
void modifiercontrat()//la 5eme fonction,
{
    float num;
    contrat C;
    gtk_widget_destroy(a);
		voiture V;
		FILE *p1=NULL;
		FILE *p2=NULL;
		p1=fopen("contrat","r");
		if(p1==NULL)
	printf("erreur\n");
 else
 {
		p2=fopen("jdid.txt","w");
 if(p2==NULL)
   printf("erreur\n");
 else
  {
  	printf("--------entrer le numero de contrat qui vous voulex modifier:---------\n");
		scanf("%f",&num);

	while(!feof(p1))
   {
   	fscanf(p1,  "%f\t %d\t %d\t %d\t  %d\t %d\n",&C.numContrat,&C.idVoiture,&C.idClient,&C.debut.jour,&C.fin.jour,&C.cout);

  if(C.numContrat!=num)

     fprintf(p2,  "%f\t %d\t %d\t %d\t  %d\t %d\n",C.numContrat,C.idVoiture,C.idClient,C.debut.jour,C.fin.jour,C.cout);
     else

	{ printf("-------entrer les nouveau information qui qui vous voulez modifier dans votre contrat------------\n");

      printf("-------entre la date fin de location:---------\n");
        scanf("%d",&C.fin.jour);
      printf("entrer le prix de location :\n");
    	scanf("%d",&C.cout);

	 fprintf(p2,  "%f\t %d\t %d\t %d\t  %d\t %d\n",C.numContrat,C.idVoiture,C.idClient,C.debut.jour,C.fin.jour,C.cout);
      }
      }
		fclose(p1);
		fclose(p2);
	}
	}
	remove("contrat");
    rename("jdid.txt","contrat");

}
void retournervoiture()//4eme fonction,
{
    float num;
    int id;
    voiture V;
    gtk_widget_destroy(a);
		contrat C;
	printf("Retourner la voiture qui vous avez louee.\n\n");
	printf("___changer la voriable en location de cette voiture 1 =>0---\n");
	modifiervoiture();

    printf("\n---Suppretion de contrat de location de la voiture retourner---\n");
	supprimercontrat ();
	printf("..............Votre contrat est supprimer merci de votre visite.............\n");
}

void listedesvoitures()//1 ere fonction,
{
    int rt;
    gtk_widget_destroy(b);

	voiture V;
	FILE*p1=NULL;
	char A[NMAX]="";
	p1=fopen("voitures","r");
  if(p1==NULL)
	printf("le fichier n'exist pas\n");
 else
 {
   printf("-----les information enregistrer dans le fichier voitures sont:-----\n");
        while(fgets(A, NMAX, p1)!=NULL)
        {
        	printf("%s",A);
        }
        fclose(p1);

   }
   printf("\nentrer 1 pour reuteur :");
scanf("%d",&rt);
if(rt==1) gestion_voiture();

}

void Ajoutervoiture( )//2eme fonction
{
    gtk_widget_destroy(b);
    voiture  V;

	FILE* p1=NULL;
	p1=fopen("voitures","a");
	if(1==NULL)
{
	printf("le fichier n'exist pas ");
}
else
{

printf("_______________entrer les info de voiture que vous voulez ajouter :___________________\n");
			printf("   idvoiture:     ");
			scanf("%d",&V.idvoiture);

			printf("    marque:   ");
			scanf("%s",V.marque);

			printf("    nomvoiture:    ");
			scanf("%s",V.nomvoiture);

			printf("    couleur:   ");
		    scanf("%s",V.couleur);

			printf("    nbplaces:    ");
			scanf("%d",&V.nbplaces);

			printf("    prixjour:    ");
			scanf("%d",&V.prixjour);

			printf("    Enlocation:    ");
			scanf("%d",&V.Enlocation);
  fprintf(p1,  "%d\t %s\t %s\t %s\t %d\t %d\t %d\n",V.idvoiture,V.marque,V.nomvoiture,V.couleur,V.nbplaces,V.prixjour,V.Enlocation);

 fclose(p1);
}
gestion_voiture();
}
void modifiervoiture()//3eme fonction
 {
         gtk_widget_destroy(b);
     int id;
     voiture V;
    FILE *p1=NULL;
	FILE *p2=NULL;

    p1=fopen("voitures","r");
if(p1==NULL)
	printf("erreur\n");
 else
 {
		p2=fopen("jdid.txt","w");
 if(p2==NULL)
   printf("erreur\n");
 else
  {printf("entrer l id de cette voiture:\n");
  	scanf("%d",&id);

	while(!feof(p1))
	{
	fscanf(p1,"%d\t %s\t %s\t %s\t %d\t %d\t %d\n",&V.idvoiture,V.marque,V.nomvoiture,V.couleur,&V.nbplaces,&V.prixjour,&V.Enlocation);
    if(V.idvoiture!=id)
     fprintf(p2,  "%d\t %s\t %s\t %s\t %d\t %d\t %d\n",V.idvoiture,V.marque,V.nomvoiture,V.couleur,V.nbplaces,V.prixjour,V.Enlocation);
	else{

		printf("   idvoiture:     ");
			scanf("%d",&V.idvoiture);

			printf("    marque:   ");
			scanf("%s",&V.marque);

			printf("    nomvoiture:    ");
			scanf("%s",V.nomvoiture);

			printf("    couleur:   ");
		    scanf("%s",V.couleur);

			printf("    nbplaces:    ");
			scanf("%d",&V.nbplaces);

			printf("    prixjour:    ");
			scanf("%d",&V.prixjour);

			printf("    Enlocation:    ");
			scanf("%d",&V.Enlocation);
   fprintf(p2,  "%d\t %s\t %s\t %s\t %d\t %d\t %d\n",V.idvoiture,V.marque,V.nomvoiture,V.couleur,V.nbplaces,V.prixjour,V.Enlocation);}
  }
	fclose(p1);

	fclose(p2);
 }

 }

remove("voitures");
rename("jdid.txt","voitures");
 }
void supprimervoiture()//la 4eme fonction,
    {
            gtk_widget_destroy(b);
    int id;
    voiture V;
	FILE *p1=NULL;
	FILE *p2=NULL;

    p1=fopen("voitures","r");
if(p1==NULL)
	printf("erreur\n");
 else
 {
		p2=fopen("jdid.txt","w");
 if(p2==NULL)
   printf("erreur\n");
 else
  {
  	printf("entrer l id de la voiture qui vous voulez supprimer:\n");
   scanf("%d",&id);


	while(!feof(p1))
   {
	fscanf(p1,"%d\t %s\t %s\t %s\t %d\t %d\t%d\t",&V.idvoiture,V.marque,V.nomvoiture,V.couleur,&V.nbplaces,&V.prixjour,&V.Enlocation);
    if(V.idvoiture!=id)
    fprintf(p2,  "%d\t %s\t %s\t %s\t %d\t %d\t %d\n",V.idvoiture,V.marque,V.nomvoiture,V.couleur,V.nbplaces,V.prixjour,V.Enlocation);
     }
	fclose(p1);

	fclose(p2);
 }

 }

remove("voitures");
rename("jdid.txt","voitures");

}

void listedesclient()//la premier fonction,
{
     gtk_widget_destroy(c);
	client per;
	FILE*p1=NULL;
	char A[NMAX]="";
	p1=fopen("clients","r");
 if(p1==NULL)
	printf("le fichier n'exist pas\n");
 else
 {
   printf("les information enregistrer dans le fichier clients sont:\n");
        while(fgets(A, NMAX, p1)!=NULL)
        {
        	printf("%s",A);
        }
        fclose(p1);

   }

}
void Ajouterclient()//la 2eme fonction,
{
    client pers;
    gtk_widget_destroy(c);
	client per;
	FILE* p1=NULL;
	p1=fopen("clients","a");
	if(1==NULL)
{
	printf("le fichier n'exist pas");
}
else
{

printf("__entrer les info de client que vous voulez ajouter :__\n");
	    printf("\n----idclient:---\n");
        scanf("%d",&per.idclient);

       	printf("\n----nom:---\n");scanf("%s",per.nom);

        printf("\n---- prenom:---\n");scanf(" %s",per.prenom);

	    printf("\n----cin:---\n");scanf("%d",&per.cin);

        printf("\n----adresse:---\n");scanf("%s",per.adresse);

        printf("\n----telephone:---\n"); scanf("%d\n",&per.telephone);
  fprintf(p1,  "%d\t %s\t %s\t %d\t %s\t %d\n",per.idclient,per.nom,per.prenom,per.cin,per.adresse,per.telephone);

 fclose(p1);
}
}
//2eme fonction :Permet d ajouter un nouveau client au autres qui sont deja enregestrer dans le fichier"clients",on saisie les informations de cette client puis on les ajoutent dans le fichier"clients".


void modifierclient()//3 eme fonction,
 {
     int id;
     client per;
     gtk_widget_destroy(c);
    FILE *p1=NULL;
	FILE *p2=NULL;

    p1=fopen("clients","r");
if(p1==NULL)
	printf("erreur\n");
 else
 {
		p2=fopen("jdid.txt","w");
 if(p2==NULL)
   printf("erreur\n");
 else
  {
  	printf("entrer l id de client qui vous voulez modifier:\n");
   scanf("%d",&id);


	while(!feof(p1))

	{
		fscanf(p1,"%d\t %s\t %s\t %d\t %s\t %d\t",&per.idclient,per.nom,per.prenom,&per.cin,per.adresse,&per.telephone);

        if(per.idclient==id)
		{
		printf("les nouveau information sont :\n");

          printf("\n---idclient:---\n");
              scanf("%d",&per.idclient);

              printf("\n---nom:---\n");
              scanf("%s",per.nom);

              printf("\n---prenom:---\n");
              scanf("%s",per.prenom);

              printf("\n---cin:---\n");
              scanf("%d",&per.cin);

               printf("\n---adresse:---\n");
               scanf("%s",per.adresse);

               printf("\n---telephone:---\n");
               scanf("%d",&per.telephone);


		fprintf(p2,  "%d\t %s\t %s\t %d\t %s\t %d\n",per.idclient,per.nom,per.prenom,per.cin,per.adresse,per.telephone);}
		else
		{
			fprintf(p2,  "%d\t %s\t %s\t %d\t %s\t %d\n",per.idclient,per.nom,per.prenom,per.cin,per.adresse,per.telephone);

		}

	   }
	fclose(p1);

	fclose(p2);
 }

 }

remove("clients");
rename("jdid.txt","clients");

    }

void supprimerclient()//la 4eme fonction,
    {
        int id;
        client per;
        gtk_widget_destroy(c);

	FILE *p1=NULL;
	FILE *p2=NULL;

    p1=fopen("clients","r");
if(p1==NULL)
	printf("erreur\n");
 else
 {
		p2=fopen("jdid.txt","w");
 if(p2==NULL)
   printf("erreur\n");
 else
  {
  	printf("entrer l id de client qui vous voulez supprimer:\n");
   scanf("%d",&id);


	while(!feof(p1))

	{
	fscanf(p1,"%d\t %s\t %s\t %d\t %s\t %d\t",&per.idclient,per.nom,per.prenom,&per.cin,per.adresse,&per.telephone);
    if(per.idclient!=id)

	fprintf(p2,  "%d\t %s\t %s\t %d\t %s\t %d\n",per.idclient,per.nom,per.prenom,per.cin,per.adresse,per.telephone);
	   }
	fclose(p1);

	fclose(p2);
 }

 }

remove("clients");
rename("jdid.txt","clients");

}

void ocation(){
    builder=gtk_builder_new_from_file("MINP.glade");

    /*********************************location*********************************/
       //window:
    a=gtk_builder_get_object(builder,"a");
       //buttons
    a1=gtk_builder_get_object(builder,"a1");
    g_signal_connect (a1, "clicked", G_CALLBACK (Visualisercontrat), NULL);
    a2=gtk_builder_get_object(builder,"a2");
    g_signal_connect (a2, "clicked", G_CALLBACK (louervoiture), NULL);
     a3=gtk_builder_get_object(builder,"a3");
    g_signal_connect (a3, "clicked", G_CALLBACK (retournervoiture), NULL);
     a4=gtk_builder_get_object(builder,"a4");
    g_signal_connect (a4, "clicked", G_CALLBACK (modifiercontrat), NULL);
     a5=gtk_builder_get_object(builder,"a5");
    g_signal_connect (a5, "clicked", G_CALLBACK (supprimercontrat), NULL);
     a6=gtk_builder_get_object(builder,"a6");
    g_signal_connect (a6, "clicked", G_CALLBACK (rta), NULL);
    gtk_widget_destroy(window);
    gtk_widget_show_all(a);

}
void gestion_voiture(){
    builder=gtk_builder_new_from_file("MINP.glade");


       /*********************************gestion cvoiture*********************************/
       //window:
    b=gtk_builder_get_object(builder,"b");
       //buttons
    b1=gtk_builder_get_object(builder,"b1");
    g_signal_connect (b1, "clicked", G_CALLBACK (listedesvoitures), NULL);
    b2=gtk_builder_get_object(builder,"b2");
    g_signal_connect (b2, "clicked", G_CALLBACK (Ajoutervoiture), NULL);
    b3=gtk_builder_get_object(builder,"b3");
    g_signal_connect (b3, "clicked", G_CALLBACK (modifiervoiture), NULL);
    b4=gtk_builder_get_object(builder,"b4");
    g_signal_connect (b4, "clicked", G_CALLBACK (supprimervoiture), NULL);
    b5=gtk_builder_get_object(builder,"b5");
    g_signal_connect (b5, "clicked", G_CALLBACK (rtb), NULL);
    gtk_widget_show_all(b);
    gtk_widget_destroy(window);

}

void gestion_client(){
    builder=gtk_builder_new_from_file("MINP.glade");

    /*********************************gestion client*********************************/
       //window:
    c=gtk_builder_get_object(builder,"c");
       //buttons
    c1=gtk_builder_get_object(builder,"c1");
    g_signal_connect (c1, "clicked", G_CALLBACK (listedesclient), NULL);
    c2=gtk_builder_get_object(builder,"c2");
    g_signal_connect (c2, "clicked", G_CALLBACK (Ajouterclient), NULL);
    c3=gtk_builder_get_object(builder,"c3");
    g_signal_connect (c3, "clicked", G_CALLBACK (modifierclient), NULL);
    c4=gtk_builder_get_object(builder,"c4");
    g_signal_connect (c4, "clicked", G_CALLBACK (supprimerclient), NULL);
    c5=gtk_builder_get_object(builder,"c5");
    g_signal_connect (c5, "clicked", G_CALLBACK (rtc), NULL);
    gtk_widget_show_all(c);
    gtk_widget_destroy(window);
}
   void menu_principal(){
builder=gtk_builder_new_from_file("MINP.glade");

    /*********************************menu principal*********************************/
       //window:
    window=gtk_builder_get_object(builder,"window");
       //buttons
    butt1=gtk_builder_get_object(builder,"butt1");
    g_signal_connect (butt1, "clicked", G_CALLBACK (ocation), NULL);
    butt2=gtk_builder_get_object(builder,"butt2");
    g_signal_connect (butt2, "clicked", G_CALLBACK (gestion_voiture), NULL);
     butt3=gtk_builder_get_object(builder,"butt3");
    g_signal_connect (butt3, "clicked", G_CALLBACK (gestion_client), NULL);
     butt4=gtk_builder_get_object(builder,"butt4");
    g_signal_connect (butt4, "clicked", G_CALLBACK (quitte), NULL);
    gtk_widget_show_all(window);

}
int main(int argc, char **argv)
{

gtk_init(&argc,&argv);



  /*________le fichier glade________*/
    builder=gtk_builder_new_from_file("MINP.glade");


    menu_principal();
 gtk_main();
        return 0;
}
