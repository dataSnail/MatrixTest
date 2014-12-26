#include "matrix.h"

#include <sstream>

using namespace std;

Matrix box_mul;
Matrix box_inver;
Matrix box_change;
Matrix box_plus;
Matrix box_cut;

void Matrix::readMatrix(string fileName)
{
	ifstream ifile(fileName.c_str(), ios::in);

	//读取文件内容
	double temp;
	string line;

	vector<double> tem_row;

	while (getline(ifile, line))
	{
		istringstream istr(line);
		while (istr >> temp)
		{
			tem_row.push_back(temp);
		}
		this->col = tem_row.size();
		_mat.push_back(tem_row);
		tem_row.clear();
		istr.clear();
		line.clear();
	}
	this->row = _mat.size();
	ifile.close();
}

void Matrix::showMatrix()
{
	cout << "matrix:" << endl;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++)
		{
			cout << _mat[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::writeMatrix(string str)
{
	ofstream os(str, ios::trunc);

	if (os)
	{
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				os << _mat[i][j] << " ";
			}
			os << endl;
		}
	}
	else
	{
		cerr << "Can not open the file!" << endl;
	}
}

void Matrix::operator+(Matrix &mt)
{
	double b[200][200];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			b[i][j] = _mat[i][j] + mt._mat[i][j];
		}
	}
	box_plus.col = col;
	box_plus.row = row;
	box_plus._mat.clear();
	vector<double> t;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			t.push_back(b[i][j]);
		}

		box_plus._mat.push_back(t);
		t.clear();
	}
}

void Matrix::operator*(Matrix &mt)
{
	double b[200][200];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < mt.col; j++)
		{
			b[i][j] = 0;
			for (int k = 0; k < col; k++)
			{
				b[i][j] += _mat[i][k] * mt._mat[k][j];
			}
		}
	}
	box_mul.col = mt.col;
	box_mul.row = row;//行列数设置好
	box_mul._mat.clear();
	vector <double> t;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<mt.col;j++)
		{
			t.push_back( b[i][j]);
		}
		box_mul._mat.push_back(t);//数据输入_mat量中   
		t.clear();
	}
}