SRC=./src/
INCLUDE=./includes/

prog : $(SRC)main.c $(SRC)matrice.o $(SRC)rechercheGrille.o $(INCLUDE)general.h
	gcc -Wall $(SRC)main.c $(SRC)matrice.o $(SRC)rechercheGrille.o -o ./bin/prog

matrice : $(SRC)matrice.c $(INCLUDE)general.h
	gcc -g -Wall $(SRC)matrice.c

rechercheGrille : $(SRC)rechercheGrille.c $(INCLUDE)general.h
	gcc -g -Wall $(SRC)rechercheGrille.c
	
clean:
	rm -i $(SRC)*.o
	rm -i $(SRC)*.*~
