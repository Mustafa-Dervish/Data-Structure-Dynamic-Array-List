/**
 * @file             ArrayListe.cpp
 * @description      ArrayListe uygulaması
 * @course           c++
 * @assignment       c++
 * @date             5 Ağustos 2022 Cuma
 * @author           Mustafa derviş
 */

#include <iostream>
#include "../include/ArrayListe.h"

ArrayListe operator+(ArrayListe birinci,ArrayListe ikinci) {
  if(birinci.sayilar.size() < ikinci.sayilar.size())
    birinci.sayilar.append(ikinci.sayilar.size() - birinci.sayilar.size(), 0);

  int birLen = birinci.sayilar.size();
  int rem = 0;
  int mod = 0;
  for (int i = 0; i < birLen;i++){
    mod = ikinci.sayilar.size() > i ? (birinci.sayilar[i] + ikinci.sayilar[i]) : birinci.sayilar[i];
    mod += rem;
    rem = mod / 10;
    birinci.sayilar[i] = (mod % 10);
  }
  if(rem != 0) birinci.sayilar.push_back(rem);
  return birinci;
}
ArrayListe ArrayListe::Carp(ArrayListe ikinci) {
  ArrayListe birinci = *this;
  long int *yeniArr = new long int[this->sayilar.size() + ikinci.sayilar.size()]();
  int birLen = (*this).sayilar.size();
  for (int a = 0; a < birLen;a++)
    for (int in = 0; in < ikinci.sayilar.size();in++) {
      yeniArr[a + in] += (birinci.sayilar[a] ) * (ikinci.sayilar[in]);
    }

  birLen += ikinci.sayilar.size();
  birinci.sayilar.resize(birLen + ikinci.sayilar.size() - 1);
  for (int a = 0, b = 0, c = 0; b < birLen;b++) {
    a = c + yeniArr[b];
    birinci.sayilar[b] = a%10;
    yeniArr[b] = a % 10;
    c = a / 10;
  }

  for (int a = 1; a < birLen;a++) {
    if (yeniArr[birLen - a]) break;
    else{
      birinci.sayilar.pop_back();
    }
  }
  if (yeniArr) delete[] yeniArr;
  return birinci;
}

ArrayListe::ArrayListe(int sayi) {
  while (sayi > 0) {
    int yeni = sayi % 10;
    sayi = sayi / 10;
    sayilar.push_back(yeni);
  }
}

std::string ArrayListe::getir() {
  std::string stringSayi;
  for (int sayi = 0; sayi < sayilar.size();sayi++) {
    stringSayi.append(std::to_string((short) sayilar[sayilar.size() - sayi - 1]));
  }
  return stringSayi;
}
