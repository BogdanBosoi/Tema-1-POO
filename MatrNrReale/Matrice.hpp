#pragma once

class Matrice{

public:

    ///<---- Constructori si Destructor ---->

    Matrice(int, int);
    Matrice(Matrice &);
    ~Matrice();

    ///<----------------------------------->

    ///<---- Setters si getters ---->

    int GetLinii() const;
    int GetColoane() const;
    void SetLinii(const int);
    void SetColoane(const int);
    void SetElem(const int, const int, const double);

    ///<---------------------------->

    ///<---- Operatori unari ---->

    Matrice operator-();
    Matrice operator+();

    ///<------------------------->

    ///<---- Operatori binari ---->

    friend Matrice operator-(Matrice &, Matrice &);
    friend Matrice operator-(double, Matrice &);
    friend Matrice operator-(Matrice &, double);
    friend Matrice operator+(double, Matrice &);
    friend Matrice operator+(Matrice &, Matrice &);
    friend Matrice operator+(Matrice &, double);
    friend Matrice operator*(Matrice &, Matrice &);
    friend Matrice operator*(double, Matrice &);
    friend Matrice operator*(Matrice &, double);
    friend Matrice operator/(Matrice &, double);
    friend Matrice operator^(Matrice &, double);
    friend Matrice operator/(double, Matrice &);

    ///<-------------------------->

    ///<---- Operatori compusi de atribuire ---->

    Matrice operator+=(Matrice &);
    Matrice operator+=(double);
    Matrice operator-=(Matrice &);
    Matrice operator-=(double);
    Matrice operator*=(double);
    Matrice operator*=(Matrice &);

    ///<---------------------------------------->

    ///<---- Operator de accesare ---->

    Matrice operator[](const int);

    ///<------------------------------>

    ///<---- Operatori relationali ---->

    friend bool operator==(Matrice &, Matrice &);
    friend bool operator!=(Matrice &, Matrice &);

    ///<------------------------------->

    ///<---- Operatori Citire si Scriere ---->

    friend std::istream& operator>>(std::istream &, Matrice &);
    friend std::ostream& operator<<(std::ostream &, Matrice &);

    ///<------------------------------------->

private:
    int m_linii, m_coloane;
    double **m_element;

};
