#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "structures.h"


#endif // HEADER_H_INCLUDED
//#define clrscr() printf("\e[1;1H\e[2J");

//##############################################################################################################################################

void menu_principal() {
	system("CLS");
	int nb_membres=0;

	int nb_elements_menu = 6, i;
	char elements_menu[8][30] = {"Ajouter un membre", "Modifier un membre", "afficher liste des membres", "Recherche par numero", "Supprimer","Deconnexion"};
	int choix;
        printf("QUE VOULEZ VOUS FAIRE \n\n");
	for (i=0; i<nb_elements_menu; i++) {
		printf("%d. %s\n", i+1, elements_menu[i]);
	}

	do {
		scanf("%d", &choix);
		getc(stdin); // Consumer le retour a la ligne
	} while (choix > nb_elements_menu);

	switch(choix) {
		case 1:
			ajouter_membre_menu();
			menu_principal();

			break;
		case 2:
			//modifier_membre_menu();
					printf("modifier  un membre\n");
			break;
		case 3:
			//liste_membre_menu();
                    system('CLS');
					nb_membres=membre_compter();

					printf("%d\n",nb_membres);


					menu_principal();
			break;
		case 4:
		    //recherche_id_membre_menu();
		    recherche_id_membre_menu();

			break;


		case 5:
			//supprimer_membre_menu();
					//membrel=membre_lire_ligne(2);

			break;
        case 6:
			//supprimer_membre_menu();
                    printf("~~~~~~~~~~~~~~~~~~~DECONNEXION ~~~~~~~~~~~~~~~~~~~\n");
					authentification();
			break;

	}
}



//###################################################################################################################################################


//  Fonction athentification qui permet a l'utilisateur d'avoir acces au menu principal
void authentification (){
            char login[50];
            char mdp[50];
            char ch;
            int i=0;

            printf("---------------------------ASSOCIATION ANCIENS ETUDIANTS ESP ----------------------------------\n\n") ;

            printf("------------------------------------ AUTHENTIFIER VOUS --------------------------------------------\n\n\n") ;

            printf("Entrer votre login  svp : \n ");
            scanf("%s",login);

            printf("Entrer votre mot de passe  svp : \n ");
           // scanf("%s",mdp);
                        while(1){
                                ch=getch();
                                if(ch==13) // touche entrer
                                {
                                    mdp[i]='\0';
                                    break;
                                }
                                else if (ch==8)
                                {
                                    if(i>0)
                                    {
                                        i--;
                                        printf("\b \b");
                                    }
                                }
                                else if (ch==9 || ch==32)
                                {
                                    continue;
                                }
                                else
                                {
                                    mdp[i]=ch;
                                    i++;
                                    printf("*");
                                }

                            }



            if(verifier_login_mdp(login,mdp) == 0){
                    menu_principal();

            }else {

                printf("################## mot de passe ou login incorectteeeee ####################");

                authentification();
            }

}



//###############################################################################################################################################






int verifier_login_mdp(char *login , char* mdp){
            char *loginfichier[50];
            char *mdpfichier[50];
            FILE *fichier_authentification = fopen("fichiers/authentification.txt" ,"r");

            if (fichier_authentification != NULL)
    {
        fscanf(fichier_authentification, "%s %s", loginfichier, mdpfichier);

      if((strcmp(login,loginfichier)==0) && (strcmp(mdp,mdpfichier)==0))
            return 0;
        else
            return 1;





    }
    else
    {

        printf("Impossible d'ouvrir le fichier");
    }






    }




//##############################################################################################################################################


int confirmer() {
	char confirmation;
	confirmation = 'o';
	puts("Confirmer ? (o/n)");
	scanf("%c", &confirmation);
	getc(stdin);
	if (confirmation == 'o' || confirmation == 'O') {
		return 1;
	} else {
		return 0;
	}
}



//####################################################################################################################################


Membre lire_membre() {
    int i;
	Membre membre;

	printf("Entrez les informations du membre.\n\n");

        printf("Numero du membre : \n");
	scanf("%d",&membre.numero);




	printf("Nom du membre: \n");
	scanf("%s",&membre.nom);

	printf("Prenom du membre: \n");
	scanf("%s",&membre.prenom);

	printf("Adresse du membre: \n");
	scanf("%s",&membre.adresse);
	printf("les classes du membre:\n\n ");
	printf("Combien de classes ? : ");
	scanf("%d",&membre.nbclasse);
	for(i=0;i<membre.nbclasse;i++){


        printf("Entrer le code de la %d  formation\n ",i+1);
	    scanf("%d",&membre.formation[i].code);
	    printf("Entrer le nom de la %d  formation\n ",i+1);
	    scanf("%s",&membre.formation[i].intitule);
	    printf("Entrer lannee de la %d formation: \n",i+1);
	    scanf("%d",&membre.formation[i].annee);



    }


	printf("Date de naissance du membre (jj/mm/aaaa):");
	scanf("%d/%d/%d",&membre.ddn.jour,&membre.ddn.mois,&membre.ddn.annee);
	getc(stdin);

	printf(" Numero : %d \nNom : %s \nPrenom :%s \nAdresse :%s \nDate de naissance : %d/%d/%d \n\n\n",membre.numero,membre.nom, membre.prenom, membre.adresse,
			membre.ddn.jour, membre.ddn.mois, membre.ddn.annee);


    printf("CLASSES : \n");
    for(i=0;i<membre.nbclasse;i++) printf("code  : %d  ,Intitule :  %s , Annee :  %d \n" ,membre.formation[i].code,membre.formation[i].intitule ,membre.formation[i].annee);

	// fgets lit les retours a la ligne, on les remplace par des caracteres nuls
	/*strtok(membre.nom, "\n");
	strtok(membre.prenom, "\n");
	strtok(membre.adresse, "\n");
	strtok(membre.formation.intitule, "\n");
	strtok(membre.formation.annee, "\n");*/


	return membre;
}


//#################################################################################################################################################


// ######################### MENU AJOUTER MEMBRE ~###################################


void ajouter_membre_menu() {
    system("CLS");
	Membre membre;

	membre = lire_membre();


	puts("Confirmer ? (O/n)");

	char confirmation;
	confirmation = 'o';
	scanf("%c", &confirmation);
	getc(stdin);
	if (confirmation == 'o' || confirmation == 'O') {
		  membre_ajouter_liste(membre);
		  membre_ajouter_fichier(membre);

	}

	menu_principal();
}

//##############################################################################################################################################

//           -------------------------- AJOUT D'UN MEMBRE ---------------------------------------


 void membre_ajouter_liste(Membre membre){

     /* Création du nouvel élément */
    liste *nouveau = malloc(sizeof(liste));
    nouveau->membre = membre;
    nouveau->suivant= NULL;

    /* Insertion de l'élément au début de la liste */


    //return nouveau;



}
void membre_ajouter_fichier(Membre membre){

int i;

FILE *fichier_membre = fopen("fichiers/membres.txt","a");
FILE *fichier_formation = fopen("fichiers/formations.txt","a");



if(fichier_membre!=NULL) {

fprintf(fichier_membre ,"%d:%s:%s:%s:%d/%d/%d:",membre.numero,membre.nom,membre.prenom,membre.adresse,membre.ddn.jour,membre.ddn.mois,membre.ddn.annee);
for(i=0;i<membre.nbclasse;i++) fprintf(fichier_membre,"%d:%s:%d:\n",membre.formation[i].code,membre.formation[i].intitule,membre.formation[i].annee);

for(i=0;i<membre.nbclasse;i++) fprintf(fichier_formation ,"%d:%d:%s:%d:\n",membre.numero,membre.formation[i].code,membre.formation[i].intitule,membre.formation[i].annee);
fclose(fichier_membre);
fclose(fichier_formation);


}


}



// ############################################FONCTIONS  FICHIERS #########################################################




int membre_compter() {
	FILE *f_membres;
	f_membres = fopen("fichiers/membres.txt", "r");
	int nbMembres = 0;

	char membre_csv[sizeof(Membre)];
	while(fgets(membre_csv, sizeof(Membre),f_membres)) {
		nbMembres++;
	}

	fclose(f_membres);
	return nbMembres;
}

int membre_ecrire_ligne(Membre membre, int ligne) {
	FILE *f_membres_lecture;
	FILE *f_membres_ecriture;
	f_membres_lecture = fopen("fichiers/membres.txt", "r");
	int nbMembres = membre_compter();
	if (ligne > nbMembres) {
		return 0;
	}
	if (ligne == nbMembres) {
		nbMembres++; // Si c'est une insertion a la fin du fichier, on reserve une case de plus dans le tableau
	}
	char membres[nbMembres][sizeof(Membre)];
	int i = 0;

	if (f_membres_lecture == NULL) {
		return 0;
	}

	while (fgets(membres[i], sizeof(Membre), f_membres_lecture)) {
		i++;
	}
	fclose(f_membres_lecture);

	sprintf(membres[ligne], "%d,%s,%s,%s,%d,%d,%d\n", membre.numero, membre.nom, membre.prenom, membre.adresse,
			membre.ddn.jour, membre.ddn.mois, membre.ddn.annee);

	f_membres_ecriture = fopen("fichiers/membres.txt", "w");

	if (f_membres_ecriture == NULL) {
		return 0;
	}

	for (i=0; i<nbMembres; i++) {
		fprintf(f_membres_ecriture, "%s", membres[i]);
	}
	fclose(f_membres_ecriture);
	return 1;
}

Membre membre_lire_ligne(int ligne) {
    int i=0;
    Membre membre;
	int lignesLues = 0;
	FILE *f_membres;
	char membre_csv[sizeof(Membre)];



	f_membres = fopen("fichiers/membres.txt", "r");



	while(lignesLues <= ligne && fgets(membre_csv, sizeof(Membre), f_membres)) {
		lignesLues++;
	}
	strtok(membre_csv, "\n"); // Suppression du caractere de retour a la ligne

	membre.numero = atoi(strtok(membre_csv, ":"));
	strcpy(membre.nom, strtok(NULL, ":"));
	strcpy(membre.prenom, strtok(NULL, ":"));
	strcpy(membre.adresse, strtok(NULL, ":"));
	membre.ddn.jour = atoi(strtok(NULL, ":"));
	membre.ddn.mois = atoi(strtok(NULL, ":"));
	membre.ddn.annee = atoi(strtok(NULL, ":"));
	for(i=0;i<membre.nbclasse;i++){
    membre.formation[i].code = atoi(strtok(NULL, ":"));
	strcpy(membre.formation[i].intitule, strtok(NULL, ":"));
	membre.formation[i].annee = atoi(strtok(NULL, ":"));
	}


	fclose(f_membres);
	return membre;
}

int membre_supprimer_ligne(int ligne) {
	FILE *f_membres;
	FILE *f_membres_replique;
	f_membres = fopen("fichiers/membres.txt", "r");
	f_membres_replique = fopen("fichiers/membres_replique.txt", "w");
	if (f_membres == NULL || f_membres_replique == NULL) {
		fclose(f_membres);
		fclose(f_membres_replique); // On ne sait pas lequel pose probleme, alors on ferme les deux
		return 0;
	}
	int i;
	int nbMembres = membre_compter();
	char membre_csv[sizeof(Membre)];
	for (i = 0; i < nbMembres; i++) {
		fgets(membre_csv, sizeof(Membre), f_membres);
		if (i != ligne) {
			fputs(membre_csv, f_membres_replique);
		}
	}

	fclose(f_membres);
	fclose(f_membres_replique);
	if (!rename("fichiers/membres_replique.csv", "fichiers/membres.csv")) {
		return 0;
	}
	return 1;
}

int membre_chercher_ligne(int id) {
	int i;
	for (i=0; i<membre_compter();i++) {
		if (membre_lire_ligne(i).numero == id) {
			return i;
		}
	}
	return 1;
}

int membre_ajouter(Membre membre) {
	int nbMembres = membre_compter();
	if (nbMembres != 0) {
		membre.numero = membre_lire_ligne(nbMembres-1).numero + 1;
	} else {
		membre.numero = 1;
	}
	if (membre.numero == 0) {
		return 0;
	}
	if(!membre_ecrire_ligne(membre, nbMembres)) {
		return 0;
	}

	return membre.numero;
}

int membre_existe(int id) {
	if (membre_chercher_ligne(id) != 1) {
		return 1;
	} else {
		return 0;
	}
}

Membre membre_chercher(int id) {
	int ligneMembre = membre_chercher_ligne(id);


	return membre_lire_ligne(ligneMembre);
}

int membre_supprimer(int id) {
	int ligneMembre = membre_chercher_ligne(id);
	if (ligneMembre == -1) {
		return 1;
	}

	if (!membre_supprimer_ligne(ligneMembre)) {
		return 0;
	}

	return 1;
}

int membre_modifier(int id, Membre membre) {
	int ligneMembre = membre_chercher_ligne(id);
	if (ligneMembre == 1) {
		return 0;
	}
	membre.numero = membre_lire_ligne(ligneMembre).numero;
	if(!membre_ecrire_ligne(membre, ligneMembre)) {
		return 0;
	}

	return 1;
}

/*=================================*/
int membre_liste(Membre *liste) {
	int i, nb_membres;
	nb_membres = membre_compter();
	Membre membre;

	for (i=0; i<nb_membres; i++) {
		membre = membre_lire_ligne(i);
		*liste = membre;
		liste++;
	}
}


//############################# MENU RECHERCHER MEMBRE ##################################################
void afficher_membre(Membre membre){
    int i =0;
printf(" Numero  : %s \n",membre.numero);
printf(" Nom : %s \n",membre.nom);
printf(" Prenom : %s \n",membre.prenom);
printf(" Adresse : %s \n",membre.adresse);
printf("CLASSES : \n");
    for(i=0;i<membre.nbclasse;i++) printf("code  : %d  ,Intitule :  %s , Annee :  %d \n" ,membre.formation[i].code,membre.formation[i].intitule ,membre.formation[i].annee);

}




void recherche_id_membre_menu() {
	int id_membre;
	printf("Entrez l'identifiant a rechercher: ");
	scanf("%d", &id_membre);
	getc(stdin);

	Membre membre;
	if (membre_existe(id_membre)) {
		membre = membre_chercher(id_membre);
		afficher_membre(membre);
	} else {
		puts("Cet identifiant n'existe pas.");
	}

	getc(stdin);
	menu_principal();
}





