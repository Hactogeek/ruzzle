/**
 \file main.c
 \brief  Solver de Ruzzle
 \author Tony Marteau, Dimitri Bernot, Marvin Jean
 \version 1.0.0
 \date 09 novembre 2015

 \fn int main();
 \brief Programme principal
 */

#include "../includes/general.h"

int main()
{
    
    //initGrille();
    
    
    grille[0][0].lettre = 'c';
    grille[0][1].lettre = 'n';
    grille[0][2].lettre = 'e';
    grille[0][3].lettre = 'a';
    
    grille[1][0].lettre = 'r';
    grille[1][1].lettre = 'u';
    grille[1][2].lettre = 'n';
    grille[1][3].lettre = 's';
    
    grille[2][0].lettre = 'l';
    grille[2][1].lettre = 'e';
    grille[2][2].lettre = 'i';
    grille[2][3].lettre = 'r';
    
    grille[3][0].lettre = 'd';
    grille[3][1].lettre = 'm';
    grille[3][2].lettre = 'g';
    grille[3][3].lettre = 'a';
    
    /*
    cnea
    runs
    leir
    dmga
    */
    
    
    afficherGrille();
    
    chercheMot();
 
    return 0;
}
