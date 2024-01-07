/**
* @file             Application.cpp
* @description      Ana uygulama
* @course           c++
* @assignment       c++
* @date             5 Ağustos 2022 Cuma
* @author           Mustafa derviş
*/

#include <iostream>
#include <fstream>
#include "../include/ArrayListe.h"

using namespace std;

int main() {
  int sayi = 0;
  cout << "Lutfen faktoriyal sayisini giriniz:\n ";
  cin >> sayi;

  ArrayListe cevap = ArrayListe(sayi);
  if (sayi != 0) {
    for (int a = 1; a < sayi; a++) {
      ArrayListe toplam = ArrayListe(0);
      for (char h: to_string(sayi - a)) toplam = toplam + cevap.Carp(ArrayListe((int) h - 48));
      cevap = toplam;
    }
  }

  ofstream Dosya("Sonuc.txt");
  if (!Dosya.is_open()) {
    cout << "Bir hata oluştu" << endl;
    exit(EXIT_FAILURE);
  }
  Dosya << (cevap.getir() == "" ? to_string(0) : cevap.getir());
  Dosya.close();

  return EXIT_SUCCESS;
}
