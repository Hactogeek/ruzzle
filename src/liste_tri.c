/**
 \file liste_tri.c
 \brief  Solver de Ruzzle
 \author Tony Marteau, Dimitri Bernot, Marvin Jean
 \version 1.0.0
 \date 09 novembre 2015
 
 \fn void ajoutElement(element * elem);
 \brief Fonction qui ajoute un élément dans la liste
 
 \fn void afficherListe();
 \brief Fonction permettant d'afficher la liste
 
 \fn void viderListe();
 \brief Fonction permettant de vider la liste
 */
 
 #include "../includes/general.h"
 
 t_element* racine = NULL;
 
 void ajoutElement(t_element * elem) {
 	t_element *nouveau, *element_courant, *precedent;
 	
 	nouveau = (t_element*)malloc(sizeof(t_element));
 	
 	strcpy(nouveau->chaine, elem->chaine);
 	nouveau->points = elem->points;
 	
 	if(!racine) { //Equivalent au liste_vide();
 		racine = (t_element*)malloc(sizeof(t_element));
 		strcpy(racine->chaine,nouveau->chaine);
 		racine->points = nouveau->points;
 	} else {
 		element_courant = (t_element*)malloc(sizeof(t_element));
 		
 		if(racine->points < nouveau->points) { //On échange la racine et le nouvel élément
 			nouveau->suivant = racine;
 			racine = nouveau;
 		}
 		
 		element_courant = racine;
 		
 		while(element_courant->suivant && (element_courant->suivant)->points > nouveau->points) {
 			element_courant = element_courant->suivant;
 		}
 		
 		if(element_courant->suivant) {
 			precedent = (t_element*)malloc(sizeof(t_element));
 			precedent = element_courant->suivant;
 			element_courant->suivant = nouveau;
 			nouveau->suivant = precedent;
 		} else {
 			element_courant->suivant = nouveau;
 		}
 	}
 }
 
 void afficherListe() {
 	t_element* tampon;
 	
 	tampon = (t_element*)malloc(sizeof(t_element));
 	tampon = racine;
 	
 	while(tampon) { //Correspond au !hors_liste()
 		printf("%s : %i points\n", tampon->chaine, tampon->points);
 		tampon = tampon->suivant;
 	}
 	
 	free(tampon);
 }
 
 void viderListe() {
 	t_element* tampon;
 	
 	tampon = (t_element*)malloc(sizeof(t_element));
 	tampon = racine;
 	
 	while(tampon->suivant) {
 		tampon = tampon->suivant;
 		free(racine);
 		racine = tampon;
 	}
 	free(tampon);
 }
