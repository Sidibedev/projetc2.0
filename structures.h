#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED



#endif // STRUCTURE_H_INCLUDED


  // les structures qu'on aura a utiliser seront definit ici

  typedef struct {
	int jour ;
	int mois ;
	int annee;
} Date;

typedef struct {
	int code;

	char intitule[30];
	char departement[100];
	int  annee;

}Formation ;

  typedef struct {
	int numero;
	int nbclasse;
	char nom[100];
	char prenom[100];
	char adresse[200];
	char classe[100];
	Date ddn;
	Formation formation[5];

} Membre;




typedef struct liste {
Membre membre ;
struct liste *suivant ;
}liste;

typedef struct Listepremier
{
    Membre *premier;
}Listepremier;

