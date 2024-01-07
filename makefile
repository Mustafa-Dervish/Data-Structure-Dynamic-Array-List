cevap: ArrayListe Application
	g++ lib/Application.o lib/ArrayListe.o -o bin/uygulama.exe

Application: ArrayListe
	g++ -c src/Application.cpp -o lib/Application.o

ArrayListe:
	g++ -c src/ArrayListe.cpp -o lib/ArrayListe.o
