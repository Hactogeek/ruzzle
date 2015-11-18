SRC=./src/
INCLUDE=./includes/

prog : $(SRC)main.c $(SRC)matrice.o $(SRC)rechercheGrille.o $(SRC)liste_tri.o $(INCLUDE)general.h
	gcc -Wall $(SRC)main.c $(SRC)matrice.o $(SRC)rechercheGrille.o $(SRC)liste_tri.o -o ./bin/prog -g

matrice : $(SRC)matrice.c $(INCLUDE)general.h
	gcc -g -Wall $(SRC)matrice.c

rechercheGrille : $(SRC)rechercheGrille.c $(INCLUDE)general.h
	gcc -g -Wall $(SRC)rechercheGrille.c

liste_tri : $(SRC)liste_tri.c $(INCLUDE)general.h
	gcc -g -Wall $(SRC)liste_tri.c
	
clean:
	rm -i $(SRC)*.o
	rm -i $(SRC)*.*~
