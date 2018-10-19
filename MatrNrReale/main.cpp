#include <bits/stdc++.h>
#include "matrice.h"

Matrice::Matrice(int linii = 1, int coloane = 1)
{
    n_linii = linii;
    n_coloane = coloane;
    int contorL;
    element = new double*[n_linii + 1];
    for(contorL = 1; contorL <= n_linii; element[contorL++] = new double[n_coloane + 1]);
    for(contorL = 1; contorL <= n_linii; contorL++)
        for(int contorC = 1; contorC <= n_coloane; element[contorL][contorC] = (contorC++ == contorL) ? 1 : 0);

    /*for(contorL = 1; contorL <= n_linii; contorL++, std::cout << '\n')
        for(int contorC = 1; contorC <= n_coloane; std::cout << element[contorL][contorC++] << " ");*/

}

void Matrice::SetLinii(int linii)
{
    n_linii = linii;
}
void Matrice::SetColoane(int coloane)
{
    n_coloane = coloane;
}
void Matrice::SetElem(int lin, int col, int elem)
{
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

Matrice::~Matrice()
{
    for(int contorL = 1; contorL <= n_linii; contorL++)
        delete[] element[contorL];
    delete[] element;
}

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


void writeStats(int arg1, int arg2)
{
    std::cout << arg1 << " " << arg2 << '\n';
}

std::istream & operator>>(std::istream & stream, Matrice & mArg)
{
    ///writeStats(mArg.n_linii, mArg.n_coloane);
    for(int contorL = 1; contorL <= mArg.n_linii; contorL++)
        for(int contorC = 1; contorC <= mArg.n_coloane; stream >> mArg.element[contorL][contorC++]);

    return stream;
}

std::ostream & operator<<(std::ostream& stream, Matrice & mArg)
{
    ///stream << mArg.n_linii << " " << mArg.n_coloane << "\n";

    for(int contorL = 1; contorL <= mArg.n_linii; contorL++, stream << "\n")
        for(int contorC = 1; contorC <= mArg.n_coloane; stream << mArg.element[contorL][contorC++] << " ");

    return stream;

}


/*Matrice operator+(Matrice & mArg1, Matrice & mArg2){


}*/



/*double Matrice::GetElem(int linie, int coloana){
    return Matrice.element[linie][coloana];
}*/

int main()
{
    Matrice M1(4, 4), M5(4, 4);
    std::cin >> M1;




    /*for(int i = 1; i <= 4; i++, std::cout << '\n')
        for(int j = 1; j <= 4; j++)
            std::cout << M1.GetElem(i, j) << " ";*/
    return 0;
}
