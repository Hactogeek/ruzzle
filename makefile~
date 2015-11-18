SRC=./src/
INCLUDE=./includes/

prog : $(SRC)main.c $(SRC)matrice.o $(SRC)rechercheGrille.o $(SRC)liste.o $(INCLUDE)general.h
	gcc -Wall $(SRC)main.c $(SRC)matrice.o $(SRC)rechercheGrille.o $(SRC)liste.o -o ./bin/prog -g

matrice : $(SRC)matrice.c $(INCLUDE)general.h
	gcc -g -Wall $(SRC)matrice.c

rechercheGrille : $(SRC)rechercheGrille.c $(INCLUDE)general.h
	gcc -g -Wall $(SRC)rechercheGrille.c

liste : $(SRC)liste.c $(INCLUDE)general.h
	gcc -g -Wall $(SRC)liste.c
	
clean:
	rm -i $(SRC)*.o
	rm -i $(SRC)*.*~
