#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


enum Metoda {laplace, gauss, sarrus};


class Macierz {
  Wektor array[ROZMIAR];

  public: 
  Macierz();
  /*Macierz(double *array);*/
  Macierz(Wektor A, Wektor B, Wektor C);
  Macierz(const Macierz & M2);

  const Wektor  & operator[] (int index) const;
  Wektor & operator[] (int index);

  const Macierz operator +(const Macierz & B) const;
  const Macierz operator -(const Macierz & B) const;
  const Macierz operator *(const Macierz & B) const;
  const Macierz operator *(double B) const;

  bool operator == (const Macierz & W2) const;
  bool operator != (const Macierz & W2) const;
  
  Macierz transponuj() const;
  //void transponuj();

  double Wyznacznik(Metoda metoda = sarrus) const;

  //const Macierz & odwroc() const;
  //void odwroc(); //z definicji, gauss
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);

const Macierz operator *(double B, const Macierz M);

//Macierz MacierzJednostkowa();

#endif
