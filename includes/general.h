#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 4

typedef struct {char lettre; int point; char bonus[2]; int passage;} t_donnee;

#include "rechercheGrille.h"
#include "matrice.h"

t_donnee grille[N][N];
