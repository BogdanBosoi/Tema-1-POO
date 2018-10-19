#include <bits/stdc++.h>
#include "matrice.h"

///<----Constructori si Destructori---->
Matrice::Matrice(int linii = 1, int coloane = 1)
{
    n_linii = linii;
    n_coloane = coloane;
    int contorL;
    element = new double*[n_linii + 1];
    for(contorL = 1; contorL <= n_linii; element[contorL++] = new double[n_coloane + 1]);
    for(contorL = 1; contorL <= n_linii; contorL++)
        for(int contorC = 1; contorC <= n_coloane; element[contorL][contorC] = (contorC++ == contorL) ? 1 : 0);

}

Matrice::~Matrice()
{
    for(int contorL = 1; contorL <= n_linii; contorL++)
        delete[] element[contorL];
    delete[] element;
}
///<----------------------------------->
///<----Setters si Getters---->
void Matrice::SetLinii(int linii){
    n_linii = linii;
}
void Matrice::SetColoane(int coloane){
    n_coloane = coloane;
}
void Matrice::SetElem(int lin, int col, int elem){
    element[lin][col] = elem;
}
int Matrice::GetLinii(){
    return n_linii;
}
int Matrice::GetColoane(){
    return n_coloane;
}
double Matrice::GetElem(int linie, int coloana){
    return element[linie][coloana];
}
///<-------------------------->

///<---Operatori---->
///<----Unari---->
Matrice operator+(Matrice & mArg)
{
    return mArg;
}

Matrice operator-(Matrice & mArg)
{
    Matrice argNou(mArg.GetLinii(), mArg.GetColoane());
    for (int contorL = 1; contorL <= argNou.GetLinii(); contorL++)
        for(int contorC = 1; contorC <= argNou.GetColoane(); contorC++)
            argNou.SetElem(contorL, contorC, -mArg.GetElem(contorL, contorC));

    return argNou;
}
///<------------->

///<----Binari---->

Matrice operator-(Matrice & mArg1, Matrice &mArg2){
    Matrice mArg3(mArg1.GetLinii(), mArg1.GetColoane());
    for(int contorL = 1; contorL <= mArg3.GetLinii(); contorL++)
        for(int contorC = 1; contorC <= mArg3.GetColoane(); contorC++)
            mArg3.element[contorL][contorC] = mArg1.GetElem(contorL, contorC) - mArg2.GetElem(contorL, contorC);

    return mArg3;
}

Matrice operator+(Matrice & mArg1, Matrice &mArg2){
    Matrice mArg3(mArg1.GetLinii(), mArg1.GetColoane());
    for(int contorL = 1; contorL <= mArg3.GetLinii(); contorL++)
        for(int contorC = 1; contorC <= mArg3.GetColoane(); contorC++)
            mArg3.element[contorL][contorC] = mArg1.GetElem(contorL, contorC) + mArg2.GetElem(contorL, contorC);

    return mArg3;
}

///

///<----Operatori Citire + Scriere---->

std::istream & operator>>(std::istream & stream, Matrice & mArg)
{

    for(int contorL = 1; contorL <= mArg.n_linii; contorL++)
        for(int contorC = 1; contorC <= mArg.n_coloane; stream >> mArg.element[contorL][contorC++]);

    return stream;
}

std::ostream & operator<<(std::ostream& stream, Matrice & mArg)
{

    for(int contorL = 1; contorL <= mArg.n_linii; contorL++, stream << "\n")
        for(int contorC = 1; contorC <= mArg.n_coloane; stream << mArg.element[contorL][contorC++] << " ");

    return stream;

}

///<---------------------------------->


int main()
{
    Matrice M1(4, 4), M5(4, 4), M2(4, 4);
    std::cin >> M1 >> M5;
    M2 = M1 - M5;
    std::cout << M2;
    M1 = M5 + M2;
    std::cout << M1;

    return 0;
}
