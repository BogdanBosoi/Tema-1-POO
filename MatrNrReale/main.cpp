#include <iostream>
#include <cstdio>
#include "Matrice.hpp"

void Swap(double &arg1, double &arg2) {
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

	m_element = new double*[m_linii];

	for (contorL = 0; contorL < m_linii; m_element[contorL++] = new double[m_coloane]);
	for (contorL = 0; contorL < m_linii; contorL++)
		for (contorC = 0; contorC < m_coloane; contorC++)
			if (contorC == contorL)
				m_element[contorL][contorC] = 1;
			else
				m_element[contorL][contorC] = 0;

}

Matrice::Matrice(Matrice & mArg) {
	int contorL = 0;
	m_linii = mArg.m_linii;
	m_coloane = mArg.m_coloane;
	m_element = new double*[m_linii];
	for (contorL = 0; contorL < m_linii; m_element[contorL++] = new double[m_coloane]);

	for (contorL = 0; contorL < m_linii; contorL++)
		for (int contorC = 0; contorC < m_coloane; contorC++)
			m_element[contorL][contorC] = mArg.m_element[contorL][contorC];

}

Matrice::~Matrice()
{
	for (int contorL = 0; contorL < m_linii; contorL++)
		delete[] m_element[contorL];
	delete[] m_element;
}
///<----------------------------------->
///<----Setters si Getters---->
void Matrice::SetLinii(const int linii) {

	m_linii = linii;
}
void Matrice::SetColoane(const int coloane) {

	m_coloane = coloane;
}
void Matrice::SetElem(const int lin, const int col, const double elem) {

	m_element[lin][col] = elem;
}
int Matrice::GetLinii() const {

	return m_linii;
}
int Matrice::GetColoane() const {

	return m_coloane;
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
	mArg *= -1;
	return mArg;
}
///<------------->

///<----Binari---->

Matrice operator-(Matrice & mArg1, Matrice &mArg2) {
	Matrice mArg3(mArg1);
	mArg3 -= mArg2;
	return mArg3;
}

Matrice operator*(Matrice & mArg1, Matrice &mArg2) {
	Matrice mArg3(mArg1);
	mArg3 *= mArg2;
	return mArg3;
}

Matrice operator*(double arg1, Matrice & mArg1) {
	Matrice mArg2(mArg1);
	mArg2 *= arg1;
	return mArg2;
}

Matrice operator*(Matrice & mArg1, double arg1) {
	Matrice mArg2(mArg1);
	mArg2 *= arg1;
	return mArg2;
}

Matrice operator+(Matrice & mArg1, Matrice &mArg2) {
	Matrice mArg3(mArg1);
	mArg3 += mArg2;
	return mArg3;
}

Matrice operator+(Matrice & mArg1, double arg1) {
	Matrice mArg2(mArg1);
	mArg2 += arg1;
	return mArg2;

}

Matrice operator+(double arg1, Matrice & mArg1) {
	Matrice mArg2(mArg1);
	mArg2 += arg1;
	return mArg2;

}

Matrice operator-(Matrice & mArg1, double arg1) {
	Matrice mArg2(mArg1);
	mArg2 -= arg1;
	return mArg2;

}

Matrice operator-(double arg1, Matrice & mArg1) {
	Matrice mArg2(mArg1);
	mArg2 *= -1;
	mArg2 += arg1;
	return mArg2;

}

Matrice operator/(double arg1, Matrice & mArg1) {

	Matrice mArg2(mArg1);

	for (int contorL = 0; contorL < mArg1.m_linii; contorL++)
		for (int contorC = 0; contorC < mArg2.m_coloane; mArg1.m_element[contorL][contorC] = arg1 / mArg2.m_element[contorL][contorC], contorC++);

	return mArg2;
}

Matrice operator/(Matrice & mArg1, double arg1) {

	Matrice mArg2(mArg1);

	for (int contorL = 0; contorL < mArg1.m_linii; contorL++)
		for (int contorC = 0; contorC < mArg1.m_coloane; mArg2.m_element[contorL][contorC] /= arg1, contorC++);

	return mArg2;
}

Matrice operator^(Matrice & mArg1, double numar) {

	if (mArg1.m_coloane != mArg1.m_linii) throw;
	if (numar != int(numar)) throw;

	int iNumar = numar;

	Matrice mArg2(mArg1);
	Matrice mArg3(mArg1);

	while (iNumar != 1) {
		if (iNumar % 2 == 0)
		{
			mArg1 *= mArg1;
			iNumar /= 2;
		}
		else
		{
			mArg2 *= mArg3;
			iNumar--;
		}
	}
	mArg1 = mArg1 * mArg2;
	return mArg1;
}

///<--------------------------->

///<----Operatori compusi de atribuire---->
Matrice Matrice::operator+=(Matrice & mArg) {
	for (int contorL = 0; contorL < this->m_linii; contorL++)
		for (int contorC = 0; contorC < this->m_coloane; contorC++)
			this->m_element[contorL][contorC] += mArg.m_element[contorL][contorC];
	return *this;
}

Matrice Matrice::operator+=(double dArg) {
	for (int contorL = 0; contorL < this->m_linii; contorL++)
		for (int contorC = 0; contorC < this->m_coloane; contorC++)
			this->m_element[contorL][contorC] += dArg;
	return *this;
}

Matrice Matrice::operator-=(Matrice & mArg) {
	for (int contorL = 0; contorL < this->m_linii; contorL++)
		for (int contorC = 0; contorC < this->m_coloane; contorC++)
			this->m_element[contorL][contorC] -= mArg.m_element[contorL][contorC];
	return *this;
}

Matrice Matrice::operator-=(double dArg) {
	for (int contorL = 0; contorL < this->m_linii; contorL++)
		for (int contorC = 0; contorC < this->m_coloane; contorC++)
			this->m_element[contorL][contorC] -= dArg;
	return *this;
}

Matrice Matrice::operator*=(double numar) {
	for (int contorL = 0; contorL < this->m_linii; contorL++)
		for (int contorC = 0; contorC < this->m_coloane; contorC++)
			this->m_element[contorL][contorC] *= numar;
	return *this;
}

Matrice Matrice::operator*=(Matrice & mArg) {
	Matrice mArg3(this->m_linii, mArg.m_coloane);
	int contorInm;
	for (int contorL = 0; contorL < this->m_linii; contorL++)
		for (int contorC = 0; contorC < mArg.m_coloane; contorC++)
		{
			contorInm = 0;
			mArg3.m_element[contorL][contorC] = 0;
			while (contorInm <= this->m_coloane)
			{
				mArg3.m_element[contorL][contorC] += this->m_element[contorL][contorInm] * mArg.m_element[contorInm][contorC];
				contorInm++;
			}
		}

	return mArg3;
}

///<-------------------------->

///<----Operatori conditionali---->
bool operator==(Matrice & mArg1, Matrice & mArg2) {
	if ((mArg1.m_linii != mArg2.m_linii) || (mArg1.m_coloane != mArg2.m_coloane))
		throw "Numar linii-coloane inegal";

	for (int contorL = 0; contorL < mArg1.m_linii; contorL++)
		for (int contorC = 0; contorC < mArg1.m_coloane; contorC++)
			if (mArg1.m_element[contorL][contorC] != mArg2.m_element[contorL][contorC])
				return 0;

	return 1;
}

bool operator!=(Matrice & mArg1, Matrice & mArg2) {
	if (mArg1 == mArg2)
		return 0;
	return 1;
}
///<------------------------------>

///<----Operator accesare---->

Matrice Matrice::operator[](const int index) {
	if (this->m_coloane < index)
		throw "Index mai mare decat numarul de linii!";
	Matrice mArg(1, this->m_coloane);
	for (int contorC = 0; contorC < this->m_coloane; contorC++)
		mArg.m_element[0][contorC] = this->m_element[index][contorC];
	return mArg;
}

///<------------------------->

///<----Operatori Citire + Scriere---->

std::istream & operator>>(std::istream & stream, Matrice & mArg)
{

	for (int contorL = 0; contorL < mArg.m_linii; contorL++)
		for (int contorC = 0; contorC < mArg.m_coloane; stream >> mArg.m_element[contorL][contorC++]);

	return stream;
}

std::ostream & operator<<(std::ostream& stream, Matrice & mArg)
{

	stream << std::fixed;
	stream.precision(2);
	for (int contorL = 0; contorL < mArg.m_linii; contorL++, stream << "\n")
		for (int contorC = 0; contorC < mArg.m_coloane;
			mArg.m_element[contorL][contorC] == int(mArg.m_element[contorL][contorC]) ? stream .precision(0) : stream.precision(2),
			stream << mArg.m_element[contorL][contorC++] << " ");

	return stream;

}

///<---------------------------------->


int main()
{
	Matrice M1(3, 3), M2(3, 3), M3(3, 3);
	///std::cin >> M1;
	M2 = M1 + M3;
	std::cout << M2;

	return 0;
}
