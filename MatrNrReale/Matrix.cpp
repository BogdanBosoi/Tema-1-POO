
#include <iostream>
#include "Matrix.hpp"

void Swap(double &arg1, double &arg2) {
	double aux;
	aux = arg1;
	arg1 = arg2;
	arg2 = aux;
}

//<----Constructori si Destructori---->

Matrix::Matrix(int lines = 1, int columns = 1)
{
	m_lines = lines;
	m_columns = columns;

	int contorL, contorC;

	m_element = new double*[m_lines];

	for (contorL = 0; contorL < m_lines; m_element[contorL++] = new double[m_columns]);
	for (contorL = 0; contorL < m_lines; contorL++)
		for (contorC = 0; contorC < m_columns; contorC++)
			if (contorC == contorL)
				m_element[contorL][contorC] = 1;
			else
				m_element[contorL][contorC] = 0;

}

Matrix::Matrix(Matrix & mArg) {
	int contorL;
	m_lines = mArg.m_lines;
	m_columns = mArg.m_columns;
	m_element = new double*[m_lines];
	for (contorL = 0; contorL < m_lines; m_element[contorL++] = new double[m_columns]);

	for (contorL = 0; contorL < m_lines; contorL++)
		for (int contorC = 0; contorC < m_columns; contorC++)
			m_element[contorL][contorC] = mArg.m_element[contorL][contorC];

}

Matrix::~Matrix()
{
	for (int contorL = 0; contorL < m_lines; contorL++)
		delete[] m_element[contorL];
	delete[] m_element;
}

//<----Setters si Getters---->

void Matrix::SetElem(const int line, const int column, const double value) {

	m_element[line][column] = value;
}
int Matrix::GetLine() const {

	return m_lines;
}
int Matrix::GetColumn() const {

	return m_columns;
}

//<----Operatori Unari---->

Matrix Matrix::operator+()
{
	return *this;
}

Matrix Matrix::operator-()
{
	*this *= -1;
	return *this;
}

///<----Operatori Binari---->

Matrix& operator-(Matrix & mArg1, Matrix &mArg2) {
	Matrix mArg3(mArg1);
	mArg3 -= mArg2;
	return mArg3;
}

Matrix& operator*(Matrix & mArg1, Matrix &mArg2) {
	Matrix mArg3(mArg1);
	mArg3 *= mArg2;
	return mArg3;
}

Matrix& operator*(double arg1, Matrix & mArg1) {
	Matrix mArg2(mArg1);
	mArg2 *= arg1;
	return mArg2;
}

Matrix& operator*(Matrix & mArg1, double arg1) {
	Matrix mArg2(mArg1);
	mArg2 *= arg1;
	return mArg2;
}

Matrix& operator+(Matrix & mArg1, Matrix &mArg2) {
	Matrix mArg3(mArg1);
	mArg3 += mArg2;
	return mArg3;
}

Matrix& operator+(Matrix & mArg1, double arg1) {
	Matrix mArg2(mArg1);
	mArg2 += arg1;
	return mArg2;

}

Matrix& operator+(double arg1, Matrix & mArg1) {
	Matrix mArg2(mArg1);
	mArg2 += arg1;
	return mArg2;

}

Matrix& operator-(Matrix & mArg1, double arg1) {
	Matrix mArg2(mArg1);
	mArg2 -= arg1;
	return mArg2;

}

Matrix& operator-(double arg1, Matrix & mArg1) {
	Matrix mArg2(mArg1);
	mArg2 *= -1;
	mArg2 += arg1;
	return mArg2;

}

Matrix& operator/(double arg1, Matrix & mArg1) {

	Matrix mArg2(mArg1);

	for (int contorL = 0; contorL < mArg1.m_lines; contorL++)
		for (int contorC = 0; contorC < mArg2.m_columns; 
			mArg1.m_element[contorL][contorC] = arg1 / mArg2.m_element[contorL][contorC], contorC++);

	return mArg2;
}

Matrix& operator/(Matrix & mArg1, double arg1) {

	Matrix mArg2(mArg1);

	for (int contorL = 0; contorL < mArg1.m_lines; contorL++)
		for (int contorC = 0; contorC < mArg1.m_columns; 
			mArg2.m_element[contorL][contorC] /= arg1, contorC++);

	return mArg2;
}

Matrix& operator^(Matrix & mArg1, int numar) {

	if (mArg1.m_columns != mArg1.m_lines) 
		throw std::runtime_error("Nu se poate ridica la putere o matrice nepatratica!");
	if (numar < 0) 
		throw std::runtime_error("Exponentul nu este natural");

	int iNumar = numar;

	Matrix mArg2(mArg1);
	Matrix mArg3(mArg1);

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

//<----Operatori compusi de atribuire---->

Matrix Matrix::operator+=(const Matrix & mArg) {

	if (m_lines != mArg.m_lines || m_columns != mArg.m_columns) 
		throw std::runtime_error("Nu se poate efectua adunarea!");

	for (int contorL = 0; contorL < this->m_lines; contorL++)
		for (int contorC = 0; contorC < this->m_columns; contorC++)
			this->m_element[contorL][contorC] += mArg.m_element[contorL][contorC];
	return *this;
}

Matrix Matrix::operator+=(double dArg) {
	for (int contorL = 0; contorL < this->m_lines; contorL++)
		for (int contorC = 0; contorC < this->m_columns; contorC++)
			this->m_element[contorL][contorC] += dArg;
	return *this;
}

Matrix Matrix::operator-=(const Matrix & mArg) {

	if (m_lines != mArg.m_lines || m_columns != mArg.m_columns) 
		throw std::runtime_error("Nu se poate efectua scaderea!");

	for (int contorL = 0; contorL < this->m_lines; contorL++)
		for (int contorC = 0; contorC < this->m_columns; contorC++)
			this->m_element[contorL][contorC] -= mArg.m_element[contorL][contorC];
	return *this;
}

Matrix Matrix::operator-=(double dArg) {
	for (int contorL = 0; contorL < this->m_lines; contorL++)
		for (int contorC = 0; contorC < this->m_columns; contorC++)
			this->m_element[contorL][contorC] -= dArg;
	return *this;
}

Matrix Matrix::operator*=(double numar) {
	for (int contorL = 0; contorL < this->m_lines; contorL++)
		for (int contorC = 0; contorC < this->m_columns; contorC++)
			this->m_element[contorL][contorC] *= numar;
	return *this;
}

Matrix Matrix::operator*=(const Matrix & mArg) {

	if (m_columns != mArg.m_lines) 
		throw std::runtime_error("Nu se poate efectua inmultirea!");

	Matrix mArg3(this->m_lines, mArg.m_columns);
	int contorInm;
	for (int contorL = 0; contorL < this->m_lines; contorL++)
		for (int contorC = 0; contorC < mArg.m_columns; contorC++)
		{
			contorInm = 0;
			mArg3.m_element[contorL][contorC] = 0;
			while (contorInm <= this->m_columns)
			{
				mArg3.m_element[contorL][contorC] += this->m_element[contorL][contorInm] * mArg.m_element[contorInm][contorC];
				contorInm++;
			}
		}

	return mArg3;
}

//<----Operatori conditionali---->

bool operator==(Matrix & mArg1, Matrix & mArg2) {

	if ((mArg1.m_lines != mArg2.m_lines) || (mArg1.m_columns != mArg2.m_columns))
		throw std::runtime_error("Numar linii-coloane inegal");

	for (int contorL = 0; contorL < mArg1.m_lines; contorL++)
		for (int contorC = 0; contorC < mArg1.m_columns; contorC++)
			if (mArg1.m_element[contorL][contorC] != mArg2.m_element[contorL][contorC])
				return 0;

	return 1;
}

bool operator!=(Matrix & mArg1, Matrix & mArg2) {
	return !(mArg1 == mArg2);
}

//<----Operator accesare---->

Matrix Matrix::operator[](const int index) {
	if (this->m_columns < index)
		throw std::runtime_error("Index mai mare decat numarul de linii!");
	Matrix mArg(1, this->m_columns);
	for (int contorC = 0; contorC < this->m_columns; contorC++)
		mArg.m_element[0][contorC] = this->m_element[index][contorC];
	return mArg;
}

//<----Operatori Citire + Scriere---->

std::istream & operator>>(std::istream & stream, Matrix & mArg)
{

	for (int contorL = 0; contorL < mArg.m_lines; contorL++)
		for (int contorC = 0; contorC < mArg.m_columns; 
			stream >> mArg.m_element[contorL][contorC],
			contorC++);

	return stream;
}

std::ostream & operator<<(std::ostream& stream, Matrix & mArg)
{

	stream << std::fixed;
	stream.precision(2);
	for (int contorL = 0; contorL < mArg.m_lines; contorL++, stream << "\n")
		for (int contorC = 0; contorC < mArg.m_columns;
			mArg.m_element[contorL][contorC] == int(mArg.m_element[contorL][contorC]) 
			? stream.precision(0) : stream.precision(2),
			stream << mArg.m_element[contorL][contorC++] << " ");

	return stream;

}
