/**
 \file rechercheGrille.c
 \brief  Solver de Ruzzle
 \author Tony Marteau, Dimitri Bernot, Marvin Jean
 \version 1.0.0
 \date 09 novembre 2015
 
 \fn void applicationBonus(t_donnee emplacement, int * pscore, int * pbonus)
 \brief Fonction ajoutant le score de la lettre trouvée et prenant les bonus en mémoire
 
 \fn int rechercheLettre(char c);
 \brief Fonction qui recherche compare les lettres adjacentes
 
 \fn int chercheMotGrille(char mot[])
 \brief Fonction qui cherche le mot dans la grille
 
 \fn void chercheMot()
 \brief Fonction qui sort un mot du dictionnaire et le appel la fonction chercherMotGrille() pour trouver le mot dans la grille
 */

#include "../includes/general.h"

void applicationBonus(t_donnee emplacement, int * pscore, int * pbonus)
{
	/* Prise en compte des bonus et ajout du score */
	if(!strcmp(emplacement.bonus, "dl"))
	{
		*pscore += 2*emplacement.point;
	}
	else if(!strcmp(emplacement.bonus, "tl"))
	{
	     	*pscore += 3*emplacement.point;
	} else
	{
	      	*pscore += emplacement.point;
	}
		      
	if(!strcmp(emplacement.bonus, "dw"))
	{
	      	*pbonus *= 2;
	}
	else if(!strcmp(emplacement.bonus, "tw"))
	{
	    	*pbonus *= 3;
	}
}

int rechercheLettre(char c, int * pscore, int * pbonus)
{
    int i, j;
    
    bool trouve = false;
    
    /* Ont parcours les lettres adjacents a la lettre précédente */
    
    for(i=-1;i<=1 && !trouve; i++)
    {
        for(j=-1; j<=1 && !trouve; j++)
        {
            
            /* Vérification si les coordonees sont bien dans la grille de jeu */
            
            if(coordonnee.x+i>=0 && coordonnee.x+i<N && coordonnee.y+j>=0 && coordonnee.y+j<N )
            {
                
                /* Vérification si la lettre correspond et si ont n'est pas passe sur la case */
                
                if(c == grille[coordonnee.x+i][coordonnee.y+j].lettre && grille[coordonnee.x+i][coordonnee.y+j].passage == 0)
                {
                    trouve = true;
                    coordonnee.x=coordonnee.x+i;
                    coordonnee.y=coordonnee.y+j;
                    grille[coordonnee.x][coordonnee.y].passage=1;
                    
                    /* Puisque la lettre est bonne, on augmente le score et on regarde les bonus */
                    applicationBonus(grille[coordonnee.x][coordonnee.y], pscore, pbonus);
                
                    return 1;
                }
            }
        }
    }
    return 0;
}

int chercheMotGrille(char mot[])
{
    int i, j;
    int score = 0;
    int * pscore = &score; //Score de la lettre
    int bonus = 1;
    int * pbonus = &bonus; //Bonus accordé au mot entier
    
    bool present = false;
    bool trouve = false;
    
    /* Cherche la premiere lettre du mot dans la grille */
    
    for(i=0; i<N && !trouve; i++)
    {
        for(j=0; j<N && !trouve; j++)
        {
            if(mot[0]==grille[i][j].lettre)
            {
                coordonnee.x=i;
                coordonnee.y=j;
                trouve=true;
                present=true;
                grille[coordonnee.x][coordonnee.y].passage=1;
                
                applicationBonus(grille[i][j], pscore, pbonus);
            }
        }
    }
    
    /* Si la premiere lettre a été trouvé dans la grille on cherche a savoir si les autres lettres sont présentes autour de la première lettre */
    
    for(i=1; i<strlen(mot) && present; i++)
    {
        if(!rechercheLettre(mot[i], pscore, pbonus))
        {
            /* La n-ième lettre n'a pas été trouvé, donc le mot n'est pas présent */
            
            present = false;
        }
    }
    
    /* Une fois terminé ont remet a 0 nos passage */
    
    for(i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            grille[i][j].passage=0;
        }
    }
    
    if(present)
    {
        /* Si le mot a ete trouve dans la grille */
        
        /* Prise en compte des bonus de lettres */
        score *= bonus; 
        
        //printf("%s : %i\n", mot, score);
        inserer();
        return 1;
    }
    
    return 0;
}

void chercheMot()
{
    int i,j;
    int k=0;
    
    char lettre;
    
    /* Initialise les cases de passage à 0 */
    
    for(i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            grille[i][j].passage=0;
        }
    }
    
    t_valeurMot mot;
    
    /* Ouvre le dictionnaire optimise */
    
    FILE * dictionnaire;
    
    dictionnaire=fopen("asset/dico_opti.txt", "r");
    
    if(dictionnaire!=NULL)
    {
        do{
            
            /* Sort le mot du dictionnaire par caractère */
            
            lettre=fgetc(dictionnaire);
            if(lettre=='\n')
            {
                mot.mot[k]='\0';
                
                if(chercheMotGrille(mot.mot))
                {
                    /* Va chercher si le mot sortit du dictionnaire est dans la grille */
                    
                    //printf("OK");
                }
                
                k=0;
            }
            else
            {
                mot.mot[k]=lettre;
                k++;
            }
        }while (!feof(dictionnaire));
        
        fclose(dictionnaire);
    }
    else
    {
        printf("Erreur dans l'ouverture du dictionnaire");
    }
}
