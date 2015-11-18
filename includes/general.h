#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 4

typedef struct {char lettre; int point; char bonus[2]; int passage;} t_donnee;
typedef struct element { char chaine[17] ; int points ; struct element *suivant ; } t_element;

#include "rechercheGrille.h"
#include "matrice.h"
#include "liste_tri.h"

t_donnee grille[N][N];
