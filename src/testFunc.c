#include"CUnit/CUnit.h"
#include"CUnit/Basic.h"
#include "../includes/general.h"

int rechercheLettre(char c)
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
                    return 1;
                }
            }
        }
    }
    return 0;
}

void testRechercheLettre(void)
{
	CU_ASSERT (rechercheLettre('c')==1);
	CU_ASSERT (rechercheLettre('z')==1);
	CU_ASSERT (rechercheLettre('z')==0);
}

int main()
{
	grille[0][0].lettre = 'c';
    grille[0][0].point = 2;
    strcpy(grille[0][0].bonus, "tl");
    grille[0][1].lettre = 'n';
    grille[0][1].point = 1;
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

	CU_pSuite pSuite = NULL;
	if (CUE_SUCCESS != CU_initialize_registry()) 
		return CU_get_error();
	pSuite = CU_add_suite("Suite_1", 0, 0);
	
	if (!pSuite) { 
		CU_cleanup_registry();
		return CU_get_error(); 
	}

	if (!CU_add_test(pSuite, "test of fprintf()", testRechercheLettre))
	{ 
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
	
}
