#include <bits/stdc++.h>
#include "Matrice.hpp"

void Swap(double &arg1, double &arg2){
    double aux;
    aux = arg1;
    arg1 = arg2;
    arg2 = aux;
}

///<----Constructori si Destructori---->
Matrice::Matrice(int linii = 1, int coloane = 1)
{
    m_linii = linii;
    m_coloane = coloane;
    int contorL, contorC;
    m_element = new double*[m_linii + 1];
    for(contorL = 1; contorL <= m_linii; m_element[contorL++] = new double[m_coloane + 1]);
    for(contorL = 1; contorL <= m_linii; contorL++)
        for(contorC = 1; contorC <= m_coloane; contorC++)
            if (contorC == contorL)
                m_element[contorL][contorC] = 1;
            else
                m_element[contorL][contorC] = 0;

}

Matrice::~Matrice()
{
    for(int contorL = 1; contorL <= m_linii; contorL++)
        delete[] m_element[contorL];
    delete[] m_element;
}
///<----------------------------------->
///<----Setters si Getters---->
void Matrice::SetLinii(int linii){

    m_linii = linii;
}
void Matrice::SetColoane(int coloane){

    m_coloane = coloane;
}
void Matrice::SetElem(int lin, int col, int elem){

    m_element[lin][col] = elem;
}
int Matrice::GetLinii() const{

    return m_linii;
}
int Matrice::GetColoane() const{

    return m_coloane;
}
double Matrice::GetElem(int linie, int coloana){

    return m_element[linie][coloana];
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
            mArg3.m_element[contorL][contorC] = mArg1.GetElem(contorL, contorC) - mArg2.GetElem(contorL, contorC);

    return mArg3;
}

Matrice operator*(Matrice & mArg1, Matrice &mArg2){
    Matrice mArg3(mArg1.GetLinii(), mArg2.GetColoane());
        int contorInm;
        for(int contorL = 1; contorL <= mArg3.m_linii; contorL++)
            for(int contorC = 1; contorC <= mArg3.m_coloane; contorC++)
                {
                    contorInm = 1;
                    mArg3.m_element[contorL][contorC] = 0;
                    while(contorInm <= mArg1.GetColoane())
                    {
                        mArg3.m_element[contorL][contorC] += mArg1.GetElem(contorL, contorInm) * mArg2.GetElem(contorInm, contorC);
                        contorInm++;
                    }
                }

    return mArg3;
}

Matrice operator*(double arg2, Matrice & mArg1){
    Matrice mArg2 = mArg1;

    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; contorC++)
            mArg2.m_element[contorL][contorC] *= arg2;
    return mArg2;

}

Matrice operator*(Matrice & mArg1, double arg2){
    Matrice mArg2 = mArg1;

    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; contorC++)
            mArg2.m_element[contorL][contorC] *= arg2;
    return mArg2;

}

Matrice operator+(Matrice & mArg1, Matrice &mArg2){
    Matrice mArg3(mArg1.GetLinii(), mArg1.GetColoane());
    for(int contorL = 1; contorL <= mArg3.GetLinii(); contorL++)
        for(int contorC = 1; contorC <= mArg3.GetColoane(); contorC++)
            mArg3.m_element[contorL][contorC] = mArg1.GetElem(contorL, contorC) + mArg2.GetElem(contorL, contorC);

    return mArg3;
}

Matrice operator+(Matrice & mArg1, double arg2){
    Matrice mArg2 = mArg1;

    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; contorC++)
            mArg2.m_element[contorL][contorC] += arg2;
    return mArg2;

}

Matrice operator+(double arg2, Matrice & mArg1){
    Matrice mArg2 = mArg1;

    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; contorC++)
            mArg2.m_element[contorL][contorC] += arg2;
    return mArg2;

}

Matrice operator-(Matrice & mArg1, double arg2){
    Matrice mArg2 = mArg1;

    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; contorC++)
            mArg2.m_element[contorL][contorC] -= arg2;
    return mArg2;

}

Matrice operator-(double arg2, Matrice & mArg1){
    Matrice mArg2 = mArg1;

    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; contorC++)
            mArg2.m_element[contorL][contorC] = arg2 - mArg2.m_element[contorL][contorC];
    return mArg2;

}

Matrice operator/(double numar, Matrice & mArg1){

    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; mArg1.m_element[contorL][contorC] = numar / mArg1.m_element[contorL][contorC], contorC++);

    return mArg1;
}

Matrice operator/(Matrice & mArg1, double numar){


    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; mArg1.m_element[contorL][contorC] /= numar, contorC++);

    return mArg1;
}
Matrice operator^(Matrice & mArg1, double numar){



    if (mArg1.m_coloane != mArg1.m_linii)
        throw "Numarul coloanelor diferit de al liniilor!";
    if (numar != int(numar))
        throw "Exponentul trebuie sa fie numar intreg!";

    int iNumar = numar;
    Matrice mArg4(mArg1.m_linii, mArg1.m_coloane);
    ///Copiez matricea originala
    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; contorC++)
            mArg4.m_element[contorL][contorC] = mArg1.m_element[contorL][contorC];
    ///Vad daca e inversabila, tratez cazul exponentului negativ
    if(iNumar < 0){
        double det = 1;

        for(int contorD = 1; contorD <= mArg1.m_linii; contorD++)   ///parcurg diagonala
            {
                if(mArg1.m_element[contorD][contorD] == 0){
                    throw "Matricea nu este inversabila!";
                    return mArg4;
                }
                for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)   ///parcurg coloana corespondenta diagonalei
                {
                    if(contorL != contorD)  ///Nu il scad pe el insusi
                    {
                        double depl = mArg1.m_element[contorL][contorD]/mArg1.m_element[contorD][contorD];  ///Imi fac m_elementul de scazut pentru diagonalizare
                        for(int contorC = 1; contorC <= mArg1.m_coloane; contorC++)
                                mArg1.m_element[contorL][contorC] -= depl * mArg1.m_element[contorD][contorC];
                    }
                }
            }

        for(int contorD = 1; contorD <= mArg1.m_linii; contorD++)
            det *= mArg1.m_element[contorD][contorD];

        if (det == 0){
            throw "Matricea nu este inversabila!";
            return mArg4;
        }
    ///Hooray, e inversabila, mai multa treaba
    ///Rescriu matricea originala
    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; contorC++)
            mArg1.m_element[contorL][contorC] = mArg4.m_element[contorL][contorC];
    ///Transpusa
    for(int contorL = 2; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= contorL - 1; contorC++)
            Swap(mArg1.m_element[contorL][contorC], mArg1.m_element[contorC][contorL]);
    ///Inversa
    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; contorC++)
            if((contorL + contorC) % 2 == 0)
                mArg1.m_element[contorL][contorC] *= 1/det;
            else mArg1.m_element[contorL][contorC] *= -1/det;
    iNumar *= -1;   ///Intru in cazul normal
    }

    ///
    mArg4 = mArg1;
    Matrice mArg2(mArg1.m_linii, mArg1.m_coloane), mArg3(mArg1.m_linii, mArg1.m_coloane);
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

///<--------------------------->

///<----Operatori atribuire---->
Matrice Matrice::operator+=(Matrice & mArg){
for(int contorL = 1; contorL <= this->m_linii; contorL++)
        for(int contorC = 1; contorC <= this -> m_coloane; contorC++)
            this->m_element[contorL][contorC] += mArg.m_element[contorL][contorC];
    return *this;
}

Matrice Matrice::operator+=(double dArg){
    for(int contorL = 1; contorL <= this -> m_linii; contorL++)
        for(int contorC = 1; contorC <= this -> m_coloane; contorC++)
            this->m_element[contorL][contorC] += dArg;
    return *this;
}

Matrice Matrice::operator-=(Matrice & mArg){
for(int contorL = 1; contorL <= this->m_linii; contorL++)
        for(int contorC = 1; contorC <= this -> m_coloane; contorC++)
            this->m_element[contorL][contorC] -= mArg.m_element[contorL][contorC];
    return *this;
}

Matrice Matrice::operator-=(double dArg){
    for(int contorL = 1; contorL <= this->m_linii; contorL++)
        for(int contorC = 1; contorC <= this -> m_coloane; contorC++)
            this->m_element[contorL][contorC] -= dArg;
    return *this;
}

Matrice Matrice::operator*=(double numar){
    for(int contorL = 1; contorL <= this->m_linii; contorL++)
        for(int contorC = 1; contorC <= this -> m_coloane; contorC++)
            this->m_element[contorL][contorC] *= numar;
    return *this;
}

Matrice Matrice::operator*=(Matrice & mArg){
    Matrice mArg3(this->m_linii, mArg.m_coloane);
    int contorInm;
    for(int contorL = 1; contorL <= this -> m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg.m_coloane; contorC++)
            {
                contorInm = 1;
                mArg3.m_element[contorL][contorC] = 0;
                while(contorInm <= this -> m_coloane)
                {
                    mArg3.m_element[contorL][contorC] += this -> m_element[contorL][contorInm] * mArg.m_element[contorInm][contorC];
                    contorInm++;
                }
            }

    return mArg3;
}

///<-------------------------->

///<----Operatori conditionali---->
bool operator==(Matrice & mArg1, Matrice & mArg2){
    if((mArg1.m_linii != mArg2.m_linii) ||(mArg1.m_coloane != mArg2.m_coloane))
        throw "Numar linii-coloane inegal";

    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; contorC++)
            if(mArg1.m_element[contorL][contorC] != mArg2.m_element[contorL][contorC])
                return 0;

    return 1;
}

bool operator!=(Matrice & mArg1, Matrice & mArg2){
    if((mArg1.m_linii != mArg2.m_linii) ||(mArg1.m_coloane != mArg2.m_coloane))
        throw "Numar linii-coloane inegal";

    for(int contorL = 1; contorL <= mArg1.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg1.m_coloane; contorC++)
            if(mArg1.m_element[contorL][contorC] == mArg2.m_element[contorL][contorC])
                return 0;

    return 1;
}
///<------------------------------>

///<----Operator accesare---->

Matrice Matrice::operator[](const int index){
    if (this -> m_coloane < index)
        throw "Index mai mare decat numarul de linii!";
    Matrice mArg(1, this -> m_coloane);
    for(int contorC = 1; contorC <= this -> m_coloane; contorC++)
        mArg.m_element[1][contorC] = this -> m_element[index][contorC];
    return mArg;
}

///<------------------------->

///<----Operatori Citire + Scriere---->

std::istream & operator>>(std::istream & stream, Matrice & mArg)
{

    for(int contorL = 1; contorL <= mArg.m_linii; contorL++)
        for(int contorC = 1; contorC <= mArg.m_coloane; stream >> mArg.m_element[contorL][contorC++]);

    return stream;
}

std::ostream & operator<<(std::ostream& stream, Matrice & mArg)
{

    stream << std::fixed;
    stream << std::setprecision(2);
    for(int contorL = 1; contorL <= mArg.m_linii; contorL++, stream << "\n")
        for(int contorC = 1; contorC <= mArg.m_coloane;
            mArg.m_element[contorL][contorC] == int(mArg.m_element[contorL][contorC]) ? stream << std::setprecision(0) : stream << std::setprecision(2),
            stream << mArg.m_element[contorL][contorC++] << " ");

    return stream;

}

///<---------------------------------->


int main()
{
    Matrice M1(1, 3), M2(3, 3);
    ///std::cin >> M1;
    M2 = 3.45 - M1;
    std::cout << M2;

    return 0;
}
