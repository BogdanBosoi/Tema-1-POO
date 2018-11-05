
#include <iostream>
#include "Matrix.hpp"

void Swap(double &arg1, double &arg2) {
	double aux;
	aux = arg1;
	arg1 = arg2;
	arg2 = aux;
}

//<----Constructors and Destructors---->

Matrix::Matrix(int lines = 1, int columns = 1)
{
	m_lines = lines;
	m_columns = columns;
	m_element.resize(lines);
	for (int contorL = 0; contorL < lines; contorL++) m_element[contorL].resize(columns);
	int contorL, contorC;
	for (contorL = 0; contorL < m_lines; contorL++)
		for (contorC = 0; contorC < m_columns; contorC++)
			if (contorC == contorL)
				m_element[contorL][contorC] = 1;
			else
				m_element[contorL][contorC] = 0;

}

Matrix::Matrix(const Matrix & mArg) {
	int contorL;
	m_lines = mArg.m_lines;
	m_columns = mArg.m_columns;
	m_element.resize(m_lines);
	for (int contorL = 0; contorL < m_lines; contorL++) m_element[contorL].resize(m_columns);

	m_element = mArg.m_element;

}

//<----Setters and Getters---->

int Matrix::GetLine() const {

	return m_lines;
}
int Matrix::GetColumn() const {

	return m_columns;
}

//<----Unary Operators---->

Matrix Matrix::operator+()
{
	return *this;
}

Matrix Matrix::operator-()
{
	*this *= -1;
	return *this;
}

//<----Binary Operators---->

Matrix operator-(Matrix & mArg1, Matrix &mArg2) {
	
		Matrix mArg3(mArg1);
		try {
		mArg3 -= mArg2;
		}
		catch (std::runtime_error const & e){
			std::cout << e.what() << "\n";
		}
		return mArg3;
	
}

Matrix operator*(Matrix & mArg1, Matrix &mArg2) {
	Matrix mArg3(mArg1);
	try {
		mArg3 *= mArg2;
	} catch (std::runtime_error const & e) {
		std::cout << e.what() << "\n";
	}
	return mArg3;
}

Matrix operator*(double arg1, Matrix & mArg1) {
	Matrix mArg2(mArg1);
	mArg2 *= arg1;
	return mArg2;
}

Matrix operator*(Matrix & mArg1, double arg1) {
	Matrix mArg2(mArg1);
	mArg2 *= arg1;
	return mArg2;
}

Matrix operator+(Matrix & mArg1, Matrix & mArg2) {
	Matrix mArg3(mArg1);
	try {
		mArg3 += mArg2;
	} catch (std::runtime_error const & e) {
		std::cout << e.what() << "\n";
	}
	return mArg3;
}

Matrix operator+(Matrix & mArg1, double arg1) {
	Matrix mArg2(mArg1);
	mArg2 += arg1;
	return mArg2;

}

Matrix operator+(double arg1, Matrix & mArg1) {
	Matrix mArg2(mArg1);
	mArg2 += arg1;
	return mArg2;

}

Matrix operator-(Matrix & mArg1, double arg1) {
	Matrix mArg2(mArg1);
	mArg2 -= arg1;
	return mArg2;

}

Matrix operator-(double arg1, Matrix & mArg1) {
	Matrix mArg2(mArg1);
	mArg2 *= -1;
	mArg2 += arg1;
	return mArg2;

}

Matrix operator/(double arg1, Matrix & mArg1) {

	Matrix mArg2(mArg1);
	
	for (int contorL = 0; contorL < mArg1.m_lines; contorL++)
		for (int contorC = 0; contorC < mArg2.m_columns; 
			mArg1.m_element[contorL][contorC] = arg1 / mArg2.m_element[contorL][contorC], contorC++);

	return mArg1;
}

Matrix operator/(Matrix & mArg1, double arg1) {
	Matrix mArg2(mArg1);
	mArg2 /= arg1;
	return mArg2;
}

Matrix operator^(Matrix & mArg1, int numar) {

	if (mArg1.m_columns != mArg1.m_lines) 
		throw std::runtime_error("Matrix need to be square type!");
	if (numar < 0) 
		throw std::runtime_error("Exponent is not natural!");

	int iNumar = numar;

	Matrix mArg2(mArg1.m_lines, mArg1.m_columns);
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
	mArg1 *= mArg2;
	return mArg1;
}

//<----Composite assignment operators---->

Matrix & Matrix::operator+=(const Matrix mArg) {

	if (m_lines != mArg.m_lines || m_columns != mArg.m_columns) 
		throw std::runtime_error("Can't sum!");

	for (int contorL = 0; contorL < this->m_lines; contorL++)
		for (int contorC = 0; contorC < this->m_columns; contorC++)
			this->m_element[contorL][contorC] += mArg.m_element[contorL][contorC];

	return *this;
}

Matrix & Matrix::operator+=(double dArg) {
	for (int contorL = 0; contorL < this->m_lines; contorL++)
		for (int contorC = 0; contorC < this->m_columns; contorC++)
			this->m_element[contorL][contorC] += dArg;
	return *this;
}

Matrix Matrix::operator-=(const Matrix & mArg) {

	if (m_lines != mArg.m_lines || m_columns != mArg.m_columns) 
		throw std::runtime_error("Can't substract!");

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

Matrix & Matrix::operator*=(const Matrix & mArg) {

	if (m_columns != mArg.m_lines) 
		throw std::runtime_error("Can't multiply!");
	Matrix mTemp(mArg);
	
	Matrix mArg3(*this);

	for (int contorL = 0; contorL < m_lines; contorL++)
		for (int contorC = 0; contorC < m_columns; contorC++)
			m_element[contorL][contorC] = 0;

	for (int contorL = 0; contorL < mArg3.m_lines; contorL++)
		for (int contorC = 0; contorC < mTemp.m_columns; contorC++)
			for (int contorInm = 0; contorInm < mArg3.m_columns; contorInm++)
				m_element[contorL][contorC] += mArg3.m_element[contorL][contorInm] * mTemp.m_element[contorInm][contorC];
	
	m_columns = mTemp.m_columns;
	return *this;
}

Matrix Matrix::operator/=(double dArg) {
	for (int contorL = 0; contorL < m_lines; contorL++)
		for (int contorC = 0; contorC < m_columns; contorC++)
			m_element[contorL][contorC] /= dArg;
	return *this;
}

//<----Operatori conditionali---->

bool operator==(Matrix & mArg1, Matrix & mArg2) {

	if ((mArg1.m_lines != mArg2.m_lines) || (mArg1.m_columns != mArg2.m_columns))
		throw std::runtime_error("Number of lines-columns is not equal");

	for (int contorL = 0; contorL < mArg1.m_lines; contorL++)
		for (int contorC = 0; contorC < mArg1.m_columns; contorC++)
			if (mArg1.m_element[contorL][contorC] != mArg2.m_element[contorL][contorC])
				return 0;

	return 1;
}

bool operator!=(Matrix & mArg1, Matrix & mArg2) {
	return !(mArg1 == mArg2);
}

//<----Accessing Operator---->

Matrix Matrix::operator[](const int index) {
	if (m_columns < index && m_lines < index)
		throw std::runtime_error("Index is greater than the dimensions of the matrix!");

	if (m_lines == 1) {
		Matrix mArg;
		mArg.m_element[0][0] = m_element[0][index - 1];
		return mArg;
	}

	Matrix mArg(1, m_columns);

	for (int contorC = 0; contorC < m_columns; contorC++)
		mArg.m_element[0][contorC] = m_element[index - 1][contorC];
	return mArg;
}

//<----Reading and Writing Operators---->

std::istream & operator>>(std::istream & stream, Matrix & mArg)
{

	for (int contorL = 0; contorL < mArg.m_lines; contorL++)
		for (int contorC = 0; contorC < mArg.m_columns; 
			stream >> mArg.m_element[contorL][contorC],
			contorC++);

	return stream;
}

std::ostream & operator<<(std::ostream & stream, const Matrix & mArg)
{
	for (int contorL = 0; contorL < mArg.m_lines; contorL++, stream << "\n")
		for (int contorC = 0; contorC < mArg.m_columns;
			stream << mArg.m_element[contorL][contorC] << " ", contorC++);

	return stream;

}
