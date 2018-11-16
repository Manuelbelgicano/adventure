all: adventure help author;

rebuild: clean-hard adventure;

obj/main.o obj/dungeon.o: include/dungeon.h

adventure: obj/dungeon.o obj/goblin.o obj/main.o
	g++ -Wall -g -o adventure obj/dungeon.o obj/goblin.o obj/main.o

obj/main.o: src/main.cpp
	g++ -Wall -g -I./include -c src/main.cpp -o obj/main.o

obj/dungeon.o: src/dungeon.cpp
	g++ -Wall -g -I./include -c src/dungeon.cpp -o obj/dungeon.o

obj/goblin.o: src/goblin.cpp include/goblin.h
	g++ -Wall -g -I./include -c src/goblin.cpp -o obj/goblin.o

clean-hard: clean-exec clean-obj clean-doxygen;

clean-exec:
	rm -f adventure

clean-obj:
	rm -f obj/*.o

clean-doxygen:
	rm -rf doc/html doc/latex

doxy: clean-doxygen
	doxygen doc/adventure.doxy
	firefox doc/html/index.html

zip: clean-hard | zipdir
	-rm -rf zip/*
	zip -r zip/adventure.zip *

zipdir:
	mkdir -p zip/

help:
	@echo "Posibles opciones:"
	@echo "		rebuild		Reconstruye el proyecto desde cero"
	@echo "		clean-hard	Borra todos los archivos creados por el makefile"
	@echo "		clean-exec	Borra el ejecutable"
	@echo "		clean-obj	Borra los archivos objeto"
	@echo "		clean-doxyen	Borra los archivos de documentación"
	@echo "		doxy		Genera la documentación del proyecto"
	@echo "		zip		Genera un zip con el proyecto"

author:
	@echo "Este proyecto ha sido creado por Manuel Gachs Ballegeer"
	@echo "https://github.com/Manuelbelgicano"
