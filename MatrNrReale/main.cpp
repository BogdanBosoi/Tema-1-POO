#include <bits/stdc++.h>
#include "matrice.h"

void swap(double &a, double &b){
    double aux;
    aux = a;
    a = b;
    b = aux;
}

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

Matrice operator*(Matrice & mArg1, Matrice &mArg2){
    Matrice mArg3(mArg1.GetLinii(), mArg2.GetColoane());
    int contorInm;
    for(int contorL = 1; contorL <= mArg3.GetLinii(); contorL++)
        for(int contorC = 1; contorC <= mArg3.GetColoane(); contorC++)
            {
                contorInm = 1;
                mArg3.element[contorL][contorC] = 0;
                while(contorInm <= mArg1.GetColoane())
                {
                    mArg3.element[contorL][contorC] += mArg1.GetElem(contorL, contorInm) * mArg2.GetElem(contorInm, contorC);
                    contorInm++;
                }
            }

    return mArg3;
}

Matrice operator+(Matrice & mArg1, Matrice &mArg2){
    Matrice mArg3(mArg1.GetLinii(), mArg1.GetColoane());
    for(int contorL = 1; contorL <= mArg3.GetLinii(); contorL++)
        for(int contorC = 1; contorC <= mArg3.GetColoane(); contorC++)
            mArg3.element[contorL][contorC] = mArg1.GetElem(contorL, contorC) + mArg2.GetElem(contorL, contorC);

    return mArg3;
}

Matrice operator/(double numar, Matrice & mArg1){

    for(int contorL = 1; contorL <= mArg1.n_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.n_coloane; mArg1.element[contorL][contorC] = numar / mArg1.element[contorL][contorC], contorC++);

    return mArg1;
}

Matrice operator/(Matrice & mArg1, double numar){
    for(int contorL = 1; contorL <= mArg1.n_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.n_coloane; mArg1.element[contorL][contorC] /= numar, contorC++);

    return mArg1;
}
Matrice operator^(Matrice & mArg1, double numar){



    if (mArg1.n_coloane != mArg1.n_linii)
        throw "Numarul coloanelor diferit de al liniilor!";
    if (numar != int(numar))
        throw "Exponentul trebuie sa fie numar intreg!";

    int iNumar = numar;
    Matrice mArg4(mArg1.n_linii, mArg1.n_coloane);
    ///Copiez matricea originala
    for(int contorL = 1; contorL <= mArg1.n_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.n_coloane; contorC++)
            mArg4.element[contorL][contorC] = mArg1.element[contorL][contorC];
    ///Vad daca e inversabila, tratez cazul exponentului negativ
    if(iNumar < 0){
        double det = 1;

        for(int contorD = 1; contorD <= mArg1.n_linii; contorD++)   ///parcurg diagonala
            {
                if(mArg1.element[contorD][contorD] == 0){
                    throw "Matricea nu este inversabila!";
                    return mArg4;
                }
                for(int contorL = 1; contorL <= mArg1.n_linii; contorL++)   ///parcurg coloana corespondenta diagonalei
                {
                    if(contorL != contorD)  ///Nu il scad pe el insusi
                    {
                        double depl = mArg1.element[contorL][contorD]/mArg1.element[contorD][contorD];  ///Imi fac elementul de scazut pentru diagonalizare
                        for(int contorC = 1; contorC <= mArg1.n_coloane; contorC++)
                                mArg1.element[contorL][contorC] -= depl * mArg1.element[contorD][contorC];
                    }
                }
            }

        for(int contorD = 1; contorD <= mArg1.n_linii; contorD++)
            det *= mArg1.element[contorD][contorD];

        if (det == 0){
            throw "Matricea nu este inversabila!";
            return mArg4;
        }
    ///Hooray, e inversabila, mai multa treaba
    ///Rescriu matricea originala
    for(int contorL = 1; contorL <= mArg1.n_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.n_coloane; contorC++)
            mArg1.element[contorL][contorC] = mArg4.element[contorL][contorC];
    ///Transpusa
    for(int contorL = 2; contorL <= mArg1.n_linii; contorL++)
        for(int contorC = 1; contorC <= contorL - 1; contorC++)
            swap(mArg1.element[contorL][contorC], mArg1.element[contorC][contorL]);
    ///Inversa
    for(int contorL = 1; contorL <= mArg1.n_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.n_coloane; contorC++)
            if((contorL + contorC) % 2 == 0)
                mArg1.element[contorL][contorC] *= 1/det;
            else mArg1.element[contorL][contorC] *= -1/det;
    iNumar *= -1;   ///Intru in cazul normal
    }

    ///
    mArg4 = mArg1;
    Matrice mArg2(mArg1.n_linii, mArg1.n_coloane), mArg3(mArg1.n_linii, mArg1.n_coloane);
    while(iNumar != 1){
        if(iNumar % 2 == 0)
        {
            mArg1 = mArg1 * mArg1;
            iNumar /= 2;
        }
        else
        {
            mArg2 = mArg2 * mArg4;
            iNumar--;
        }
    }
    mArg1 = mArg1 * mArg2;
    return mArg1;
}

///

///<----Operatori atribuire---->
Matrice Matrice::operator+=(Matrice & mArg){
    for(int contorL = 1; contorL <= this->n_linii; contorL++)
        for(int contorC = 1; contorC <= this -> n_coloane; contorC++)
            this->element[contorL][contorC] += mArg.element[contorL][contorC];
    return *this;
}

Matrice Matrice::operator-=(Matrice & mArg){
    for(int contorL = 1; contorL <= this->n_linii; contorL++)
        for(int contorC = 1; contorC <= this -> n_coloane; contorC++)
            this->element[contorL][contorC] -= mArg.element[contorL][contorC];
    return *this;
}

Matrice Matrice::operator*=(double numar){
    for(int contorL = 1; contorL <= this->n_linii; contorL++)
        for(int contorC = 1; contorC <= this -> n_coloane; contorC++)
            this->element[contorL][contorC] *= numar;
    return *this;
}

Matrice Matrice::operator*=(Matrice & mArg){
    Matrice mArg3(this->n_linii, mArg.n_coloane);
    int contorInm;
    for(int contorL = 1; contorL <= this -> n_linii; contorL++)
        for(int contorC = 1; contorC <= mArg.n_coloane; contorC++)
            {
                contorInm = 1;
                mArg3.element[contorL][contorC] = 0;
                while(contorInm <= this -> n_coloane)
                {
                    mArg3.element[contorL][contorC] += this -> element[contorL][contorInm] * mArg.element[contorInm][contorC];
                    contorInm++;
                }
            }

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

    stream << std::fixed;
    stream << std::setprecision(2);
    for(int contorL = 1; contorL <= mArg.n_linii; contorL++, stream << "\n")
        for(int contorC = 1; contorC <= mArg.n_coloane; stream << mArg.element[contorL][contorC++] << " ");

    return stream;

}

///<---------------------------------->


int main()
{
    Matrice M1(3, 3), M5(3, 3), M2(3, 3);
    std::cin >> M1 >> M2;
    M2 += M1;
    M2 *= 3;
    std::cout << M2;

    return 0;
}
