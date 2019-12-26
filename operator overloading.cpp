#include <iostream>

using namespace std;

class Matrix {
	int** values ;
	int row, column ;
public:
	Matrix(int row=0, int column = 0) {
		this->row = row;
		this->column = column;
		values = new int*[row];
		for(int i = 0; i < row; i++){
			values[i] = new int[column];
		}
	}
	Matrix operator+ (const Matrix &m) const {
		Matrix temp(row, column);
		for(int i = 0; i < row; i++){
			for(int j = 0; j < column; j++){
				temp.values[i][j] = values[i][j] + m.values[i][j];
			}
		}
		return temp;
	}
	Matrix operator* (const int val) const {
		Matrix temp(row, column);
		for(int i = 0; i < row; i++){
			for(int j = 0; j < column; j++){
				temp.values[i][j] = values[i][j] * val;
			}
		}
		return temp;
	}
	friend istream &operator >> (istream &is, Matrix &m);
	friend ostream &operator << (ostream &os, const Matrix &m);
	~Matrix() {
		for (int i = 0; i < row; i++) {
			delete[] values[i];
		}
		delete[] values;
	}
} ;
istream &operator >> (istream &is, Matrix &m){
	for(int i = 0; i < m.row; i++){
		for(int j = 0; j < m.column; j++){
			is >> m.values[i][j];
		}
	}
	return is;
}
ostream &operator << (ostream &os, const Matrix &m){
	for(int i = 0; i < m.row; i++){
		for(int j = 0; j < m.column; j++){
			os << m.values[i][j] << '\t';
		}
		os << endl;
	}
	return os;
}

int main() {
	Matrix m1(2, 2), m2(2, 2) ;
	cin >> m1 ;
	cin >> m2 ;

	Matrix m3(m1 + m2);
	Matrix m4(2, 2);

    m4 = m3 * 10 ;

	cout << m3 << endl << m4 << endl ;
}

