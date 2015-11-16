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
    
    init_liste();
    
    
    grille[0][0].lettre = 'c';
    grille[0][0].point = 2;
    strcpy(grille[0][0].bonus, "tl");
    grille[0][1].lettre = 'n';
    grille[0][1].point = 2;
    strcpy(grille[0][1].bonus, "dl");
    grille[0][2].lettre = 'e';
    grille[0][2].point = 1;
    grille[0][3].lettre = 'a';
    grille[0][3].point = 1;
    
    grille[1][0].lettre = 'r';
    grille[1][0].point = 1;
    grille[1][1].lettre = 'u';
    grille[1][1].point = 1;
    strcpy(grille[1][1].bonus, "dw");
    grille[1][2].lettre = 'n';
    grille[1][2].point = 2;
    grille[1][3].lettre = 's';
    grille[1][3].point = 2;
    
    grille[2][0].lettre = 'l';
    grille[2][0].point = 3;
    grille[2][1].lettre = 'e';
    grille[2][1].point = 1;
    grille[2][2].lettre = 'i';
    grille[2][2].point = 2;
    grille[2][3].lettre = 'r';
    grille[2][3].point = 1;
    strcpy(grille[2][3].bonus, "dw");
    
    grille[3][0].lettre = 'd';
    grille[3][0].point = 3;
    strcpy(grille[3][0].bonus, "tw");
    grille[3][1].lettre = 'm';
    grille[3][1].point = 2;
    grille[3][2].lettre = 'g';
    grille[3][2].point = 4;
    strcpy(grille[3][2].bonus, "tl");
    grille[3][3].lettre = 'a';
    grille[3][3].point = 1;
    
    /*
    c_2_tl n_2_dl e_1_00 a_1_00
    r_1_00 u_1_dw n_2_00 s_2_00
    l_3_00 e_1_00 i_2_00 r_1_dw
    d_3_tw m_2_00 g_4_tl a_1_00
    */
    
    
    afficherGrille();
    
    chercheMot();
    
    afficher_liste();
 
    return 0;
}
