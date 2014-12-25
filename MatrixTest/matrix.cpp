#include "matrix.h"

#include <sstream>

using namespace std;

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

}