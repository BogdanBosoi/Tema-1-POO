#pragma once

#include <vector>
#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {

public:

	//<---- Constructors and Destructors---->

	Matrix(int, int);
	Matrix(const Matrix &);

	//<---- Setters and getters ---->

	int GetLine() const;
	int GetColumn() const;

	//<----Unary Operators ---->

	Matrix operator-();
	Matrix operator+();

	//<---- Binary Operators ---->

	friend Matrix  operator-(Matrix &, Matrix &);
	friend Matrix  operator-(double, Matrix &);
	friend Matrix  operator-(Matrix &, double);
	friend Matrix  operator+(double, Matrix &);
	friend Matrix  operator+(Matrix &, Matrix &);
	friend Matrix  operator+(Matrix &, double);
	friend Matrix  operator*(Matrix &, Matrix &);
	friend Matrix  operator*(double, Matrix &);
	friend Matrix  operator*(Matrix &, double);
	friend Matrix  operator/(Matrix &, double);
	friend Matrix  operator/(double, Matrix &);
	friend Matrix  operator^(Matrix &, int);
	

	//<---- Compound operators ---->

	Matrix & operator+=(const Matrix);
	Matrix & operator+=(double);
	Matrix operator-=(const Matrix &);
	Matrix operator-=(double);
	Matrix operator*=(double);
	Matrix & operator*=(const Matrix &);
	Matrix operator/=(double);

	//<---- Access Operator ---->

	Matrix operator[](const int);

	//<---- Boolean Operators ---->

	friend bool operator==(Matrix &, Matrix &);
	friend bool operator!=(Matrix &, Matrix &);

	//<---- Read and Write Operators---->

	friend std::istream& operator>>(std::istream &, Matrix &);
	friend std::ostream& operator<<(std::ostream &, const Matrix &);

private:
	int m_lines;
	int m_columns;
	std::vector<std::vector<double>> m_element;

};

#endif