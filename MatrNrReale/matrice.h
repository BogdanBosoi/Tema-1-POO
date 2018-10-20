#pragma once

class Matrice{
    int n_linii, n_coloane;
    double **element;

public:
    Matrice(int, int);
    ~Matrice();
    int GetLinii();
    int GetColoane();
    double GetElem(int, int);
    void SetLinii(int);
    void SetColoane(int);
    void SetElem(int, int, int);

    Matrice operator-() const;
    Matrice operator+() const;
    friend Matrice operator-(Matrice &, Matrice &);
    friend Matrice operator+(Matrice &, Matrice &);
    Matrice operator+=(Matrice &);
    Matrice operator-=(Matrice &);
    Matrice operator*=(double);
    Matrice operator*=(Matrice &);
    friend Matrice operator*(Matrice &, Matrice &);
    friend Matrice operator/(Matrice &, double);
    friend Matrice operator^(Matrice &, double);
    friend Matrice operator/(double, Matrice &);
    friend std::istream& operator>>(std::istream &, Matrice &);
    friend std::ostream& operator<<(std::ostream &, Matrice &);


};
