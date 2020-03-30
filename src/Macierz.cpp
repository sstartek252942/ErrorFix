#include "Macierz.hh"

//konstruktory

Macierz::Macierz()
{
  for (int j = 0; j < ROZMIAR; j++)
    for (int i = 0; i < ROZMIAR; i++)
       this->array[i][j] = 0;
}

Macierz::Macierz(const Macierz & M2)
{
  for (int i=0; i<ROZMIAR; i++)
  (*this)[i] = M2[i];
}

Macierz::Macierz(Wektor A, Wektor B, Wektor C)
{
  (*this)[0] = A;
  (*this)[1] = B;
  (*this)[2] = C;
}

const Wektor  & Macierz::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << "poza zakresem" << std::endl;
    exit(1);
  }
  return this->array[index];
}

Wektor & Macierz::operator[] (int index)
{
  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << "poza zakresem" << std::endl;
    exit(1);
  }
  return this->array[index];
}

const Macierz Macierz::operator +(const Macierz & M2) const
{
  Macierz temp;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    temp[i] = (*this)[i] + M2[i];
  }
  return temp;
}

const Macierz Macierz::operator -(const Macierz & M2) const
{
  Macierz temp;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    temp[i] = (*this)[i] - M2[i];
  }
  return temp;
}

const Macierz Macierz::operator *(const Macierz & M2) const
{
  Macierz temp;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    temp[i] = (*this)[i] - M2[i];
  }
  return temp;
}

const Macierz Macierz::operator *(double a) const
{
  Macierz temp;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    temp[i] = (*this)[i] * a;
  }
  return temp;
}

bool Macierz::operator == (const Macierz & M2) const
{
  bool flag = true;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    if ((*this)[i] != M2[i])
    flag = false;
  }
  return flag;
}

bool Macierz::operator != (const Macierz & M2) const
{
  return !(*this==M2);
}
  
Macierz Macierz::transponuj() const
{
  Macierz M2;
  for (int j = 0; j < ROZMIAR; j++)
    for (int i = 0; i < ROZMIAR; i++)
        M2[j][i]= (*this)[i][j];
  
  return M2;
}

/*const Macierz Macierz::odwroc() const
{
  Macierz M2;
  for (int j = 0; j < ROZMIAR; j++)
    for (int i = 0; i < ROZMIAR; i++)
        M2[j][i]= (*this)[i][j];
  
  return M2;
}*/

double Macierz::Wyznacznik(Metoda metoda) const //laplace, gauss
{
  double temp = 0;
  if (metoda == sarrus)
  {
    for (int i = 0; i < ROZMIAR; i++)
      temp += (*this)[i % ROZMIAR][0] * (*this)[(i+1) % ROZMIAR][1] * (*this)[(i+2) % ROZMIAR][2];
    for (int i = 0; i < ROZMIAR; i++)
      temp -= (*this)[i % ROZMIAR][0] * (*this)[(i+2) % ROZMIAR][1] * (*this)[(i+1) % ROZMIAR][2];
    return temp;
  }
  else if (metoda == laplace)
  {
    temp += (*this)[0][0] * ((*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1]);
    temp -= (*this)[1][0] * ((*this)[0][1] * (*this)[2][2] - (*this)[0][2] * (*this)[2][1]);
    temp += (*this)[2][0] * ((*this)[0][1] * (*this)[1][2] - (*this)[1][1] * (*this)[0][2]);
    return temp;
  }
  else if(metoda == gauss)
  {
    Macierz tempMacierz(*this);

    tempMacierz[1] = tempMacierz[1] - tempMacierz[0] * (tempMacierz[1][0] / tempMacierz[0][0]);
    tempMacierz[2] = tempMacierz[2] - tempMacierz[0] * (tempMacierz[2][0] / tempMacierz[0][0]);
    tempMacierz[2] = tempMacierz[2] - tempMacierz[1] * (tempMacierz[2][1] / tempMacierz[1][1]);

    temp += tempMacierz[0][0] * tempMacierz[1][1] * tempMacierz[2][2];
    return temp;
  }
  
}

//Funkcje

std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
    for (int i = 0; i < ROZMIAR; i++)
    {
      Strm>>Mac[i];
    }
  return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
  for (int i = 0; i < ROZMIAR; i++)
  {
     Strm << Mac[i] << std::endl;
  }
  return Strm;
}

const Macierz operator *(double a, const Macierz M)
{
  return M*a;
}
