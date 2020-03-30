#include "UkladRownanLiniowych.hh"

UkladRownanLiniowych::UkladRownanLiniowych()
{
  //this->macierz.();
  //this->wektor.();
}


UkladRownanLiniowych::UkladRownanLiniowych(const Macierz & M, const Wektor & W)
{
  this->macierz = M;
  this->wektor = W;
}

const Wektor UkladRownanLiniowych::rozwiaz() const
{
  
  Macierz M2(this->macierz);
  //std::cout << M2;
  //Cramer
  double W,WX,WY,WZ;
  W = M2.Wyznacznik();

  M2[0] = wektor;
  WX = M2.Wyznacznik();
  M2[0] = this->macierz[0];

  M2[1] = wektor;
  WY = M2.Wyznacznik();
  M2[1] = this->macierz[1];

  M2[2] = wektor;
  WZ = M2.Wyznacznik();
  M2[2] = this->macierz[2];

  if (W != 0)
  {
    Wektor wynik(WX/W, WY/W, WZ/W);
    return wynik;
  }
  else exit(1);
}

const Wektor & UkladRownanLiniowych::getwektor() const
{
   return wektor;
}
void UkladRownanLiniowych::setwektor(const Wektor & W)
{
  this->wektor = W;
}

const Macierz & UkladRownanLiniowych::getmacierz() const
{
  return macierz;
}

void UkladRownanLiniowych::setmacierz(const Macierz & M)
{
  this->macierz = M;
}

//************Funkcje


std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
  Wektor tempW;
  Macierz tempM;
  Strm >> tempM >> tempW;
  UklRown.setmacierz(tempM);
  UklRown.setwektor(tempW);
  return Strm; 
}


std::ostream& operator << ( std::ostream &Strm,  const UkladRownanLiniowych &UklRown)
{
  Strm << "Macierz A^T:" << std::endl; 
  Strm << UklRown.getmacierz() << std::endl;
  Strm << "Wektor wyrazow wolnych b:" << std::endl;  
  Strm << UklRown.getwektor() << std::endl;
  return Strm; 
}
