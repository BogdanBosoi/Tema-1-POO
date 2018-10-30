#pragma once

#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {

public:

	//<---- Constructori si Destructor ---->

	Matrix(int, int);
	Matrix(Matrix &);
	~Matrix();

	//<---- Setters si getters ---->

	int GetLine() const;
	int GetColumn() const;
	void SetElem(const int line, const int column, const double value);

	//<---- Operatori unari ---->

	Matrix operator-();
	Matrix operator+();

	//<---- Operatori binari ---->

	friend Matrix& operator-(Matrix &, Matrix &);
	friend Matrix& operator-(double, Matrix &);
	friend Matrix& operator-(Matrix &, double);
	friend Matrix& operator+(double, Matrix &);
	friend Matrix& operator+(Matrix &, Matrix &);
	friend Matrix& operator+(Matrix &, double);
	friend Matrix& operator*(Matrix &, Matrix &);
	friend Matrix& operator*(double, Matrix &);
	friend Matrix& operator*(Matrix &, double);
	friend Matrix& operator/(Matrix &, double);
	friend Matrix& operator^(Matrix &, int);
	friend Matrix& operator/(double, Matrix &);

	//<---- Operatori compusi de atribuire ---->

	Matrix operator+=(const Matrix &);
	Matrix operator+=(double);
	Matrix operator-=(const Matrix &);
	Matrix operator-=(double);
	Matrix operator*=(double);
	Matrix operator*=(const Matrix &);

	//<---- Operator de accesare ---->

	Matrix operator[](const int);

	//<---- Operatori relationali ---->

	friend bool operator==(Matrix &, Matrix &);
	friend bool operator!=(Matrix &, Matrix &);

	//<---- Operatori Citire si Scriere ---->

	friend std::istream& operator>>(std::istream &, Matrix &);
	friend std::ostream& operator<<(std::ostream &, Matrix &);

private:
	int m_lines;
	int m_columns;
	double **m_element;

};

#endif