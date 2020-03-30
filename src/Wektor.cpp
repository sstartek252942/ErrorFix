#include "Wektor.hh"
#include <math.h>

//Konstruktory

Wektor::Wektor()
{
  for (int i=0; i<ROZMIAR; i++)
  (*this)[i] = 0;
}


Wektor::Wektor(double xx,double yy,double zz)
{
  (*this)[0] = xx;
  (*this)[1] = yy;
  (*this)[2] = zz;
}


Wektor::Wektor(double *tab)
{
  for (int i=0; i<ROZMIAR; i++)
  (*this)[i] = tab[i];
}

Wektor::Wektor(const Wektor & W2)
{
  for (int i=0; i<ROZMIAR; i++)
  (*this)[i] = W2[i];
}

const double & Wektor::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << "poza zakresem" << std::endl;
    exit(1);
  }
  return this->array[index];
}
  
double & Wektor::operator[] (int index)
{
  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << "poza zakresem" << std::endl;
    exit(1);
  }
  return this->array[index];
}

//metody: przeciazenia operatorow

const Wektor Wektor::operator + (Wektor const &Wek) const
{
  Wektor tempWek;
  double tempDouble;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    tempDouble = (*this)[i] + Wek[i];
    tempWek[i] = tempDouble;
  }
  return tempWek;
}

const Wektor Wektor::operator - (Wektor const &Wek) const
{
  Wektor tempWek;
  double tempDouble;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    tempDouble = (*this)[i] - Wek[i];
    tempWek[i]=tempDouble;
  }
  return tempWek;
}

double Wektor::operator * (Wektor const &Wek) const
{
  double tempDouble = 0;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    tempDouble += (*this)[i] * Wek[i];
  }

  return tempDouble;
}

const Wektor Wektor::operator * (double const &a) const
{
  Wektor tempWek;
  double tempDouble;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    tempDouble = (*this)[i] * a;
    tempWek[i]=tempDouble;
  }
  return tempWek;
}

double Wektor::dlugosc() const
{
  return sqrt((*this)[0]*(*this)[0]+(*this)[1]*(*this)[1]+(*this)[2]*(*this)[2]);
}

bool Wektor::operator == (const Wektor & W2) const
{ 
  bool flag = true;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    if ((*this)[i] != W2[i])
    flag = false;
  }
  return flag;
}

bool Wektor::operator != (const Wektor & W2) const
{
  return !(*this==W2);
}
//funkcje

Wektor operator*(double a, const Wektor & W2)
{
  return W2*a;
}

std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
  for (int i = 0; i < ROZMIAR; i++)    
  {
    double newElement;
    Strm>>newElement;
    Wek[i] = newElement;
  }
  return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
  for (int i = 0; i < ROZMIAR; i++)    
  {
    Strm<<Wek[i] << "   ";
  }

  return Strm;
}
