#include "../includes/general.h"

/* Déclaration de la structure */
typedef struct element { t_valeurMot mot ; struct element* pred ; struct element* succ ;} t_element;

/* Déclaration des pointeurs de drapeau et d'élement courant */
t_element * drapeau;
t_element * ec;

/* Primitives pour utiliser la liste */

void init_liste(void)
/* Crée la liste constituée du seul drapeau */
{	
	drapeau = (t_element*)malloc(sizeof(t_element));
	drapeau->pred = drapeau;
	drapeau->succ = drapeau;
	ec = drapeau;
}

int liste_vide(void)
/* Rend vrai si la liste est vide, faux sinon */
{	
	return (drapeau->succ == drapeau);
}

int hors_liste(void)
/* Rend vrai si l'elt courant est hors de la liste, faux sinon */
{	
	return(ec == drapeau);
}

void en_tete(void)
/* Positionne en tete de la liste */
{
	if(!liste_vide()) {
		ec = drapeau->succ;
	}
}

void en_queue(void)
/* Positionne en queue de la liste */
{
	if(!liste_vide()) {
		ec = drapeau->pred;
	}
}

void precedent(void)
/* Positionne sur l'elt precedent*/
{	
	if(!hors_liste()) {
		ec = ec->pred;

	}
}

void suivant(void)
/* Positionne sur l'elt suivant*/
{	
	if(!hors_liste()) {
		ec = ec->succ;
	}
}

void valeur_elt(t_valeurMot* m)
/* Renvoie dans e la veleur de l'elt courant */
{	
	if(!hors_liste())
		*m= ec;
}

void modif_elt(t_valeurMot m)
/* Affecte v à l'elt courant */
{
	if(!hors_liste()) 
		ec = m;
}

void oter_elt(void)
/* Supprime l'elt courant et positionne sur le precedent */
{	
	t_element * element_courant;
	
	element_courant = ec;
	(ec->pred)->succ = ec->succ;
	(ec->succ)->pred = ec->pred;
	element_courant = ec;
	
	precedent();
	
	free(element_courant);
}

void ajout_droit(t_valeurMot m)
/* Ajoute v a droite de l'elt courant */
{
	if(liste_vide()||!hors_liste())
	{
		t_element * nouvel_element = malloc(sizeof(t_element));
		nouvel_element->mot = m;
		nouvel_element->succ = ec->succ;
		nouvel_element->pred = ec;
		ec->succ = nouvel_element;
		(nouvel_element->succ)->pred = nouvel_element;
		
		ec = nouvel_element;
	}
}

void ajout_gauche(t_valeurMot m)
/* Ajoute v a gauche de l'elt courant */
{	
	if(liste_vide() || !hors_liste()) {
		t_element * nouvel_element = malloc(sizeof(t_element));
		
		nouvel_element->mot = m;
		nouvel_element->pred = ec->pred;
		nouvel_element->succ = ec;
		
		(ec->pred)->succ = nouvel_element;
		(ec->pred) = nouvel_element;
		
		
		ec = nouvel_element;
	}
}

/* Fonctions de manipulation de la liste */

void afficher_liste(void)
/* Affiche les valeurs de la liste */
{
	int elem;

	if(liste_vide())
		printf("La liste est vide\n");
	else
	{
		printf("\nLa liste contient: ");
		en_tete();
		while(!hors_liste())
		{
			valeur_elt(&elem);
			printf("%s : %i\n", elem.score, elem.mot);
			suivant();
		}
		printf("\n");
	}
}

void inserer(t_valeurMot mot) {
	/*Insère un élément dans la liste, en préservant l'ordre croissant des valeurs de la liste*/
	int valeur, valeur_actuelle;
	
	valeur = mot.score;
	
	
	if(liste_vide()) {
		ajout_droit(mot);
	} else {
		en_tete();
		valeur_elt(&valeur_actuelle);
		while(!hors_liste() && valeur_actuelle < valeur) {
			suivant();
			valeur_elt(&valeur_actuelle);
		}
		
		if(hors_liste()) {
			en_queue();
			ajout_droit(mot);
		} else {
			ajout_gauche(mot);
		}
	}
}
	

void supprimer(void)
/* Supprime toutes les occurrences d'un entier lu au clavier */
{
	int valeur;
	int valeur_actuelle;
	
	if(liste_vide()) {
		printf("La liste est vide\n");
	} else {
		printf("\nEntrez l'entier a supprimer dans la liste : ");
		scanf("%i", &valeur);
		en_queue();
		while(!hors_liste()) {
			valeur_elt(&valeur_actuelle);
			if(valeur_actuelle == valeur) {
				oter_elt();
			} else {
				precedent();
			}
		}
	}
}

void vider_liste(void)
/* Supprime tous les éléments de la liste */
{
	if(liste_vide()) {
		printf("La liste est deja vide.\n");
	} else {
		en_queue();
		while(!liste_vide()) {
			oter_elt();
		}
	}
}
