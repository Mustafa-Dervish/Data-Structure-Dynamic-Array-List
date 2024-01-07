#ifndef ARRAYLIST_HEADER
#define ARRAYLIST_HEADER

#include <iostream>

class ArrayListe {
private:
int lenght;
int size;
int* item;
public:


  ArrayListe();
  std::string sayilar;
  ArrayListe(int sayi);

  friend ArrayListe operator+(ArrayListe birinci, ArrayListe ikinic);
  std::string getir();
  ArrayListe Carp(ArrayListe ikinci);
};

#endif /* ARRAYLIST_HEADER */
