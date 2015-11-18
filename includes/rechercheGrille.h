typedef struct{int x; int y;}coord;

void applicationBonus(t_donnee emplacement, int * pscore, int * pbonus);
int rechercheLettre(char c, int * pscore, int * pbonus);
int chercheMotGrille(char mot[N*N]);
void chercheMot();

coord coordonnee;
