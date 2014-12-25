#ifndef MATRIX_H 
#define MATRIX_H
#include "string"
#include "iostream"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

class Matrix
{
public:
	void readMatrix(string fileName);
	void showMatrix();
	void writeMatrix(string str);
	void inversion();//Çó¾ØÕóÄæ¾ØÕó
	void change();//Çó¾ØÕó×ªÖÃ

	void operator +(Matrix &m);
	void operator -(Matrix &m);
	void operator *(Matrix &m);
	void operator =(Matrix &m);

	vector<vector<double>> _mat;
	int row;
	int col;
};

#endif