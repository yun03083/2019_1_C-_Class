#include <iostream>
#include <cstring>

using namespace std;

class Complex {
private:
	float real, imaginary;
public:
	Complex(float _real = 0.0f, float _imaginary = 0.0f)
		:real(_real), imaginary(_imaginary) {}
	bool operator == (const Complex& c) const {
		return real == c.real && imaginary == c.imaginary;
	}
};

class MyString {
private:
	char* str;
public:
	MyString() {}
	MyString(const char* _str)
		:str(new char[strlen(_str) + 1]) {
		strcpy(str, _str);
	}
	bool operator == (const MyString& m) const {
		return strcmp(str, m.str) == 0;
	}
};


template<typename T, int size>
class List {
	T* elem;
	int currentSize;
public:
	List() :elem(new T[size]), currentSize(0) {}
	int add(const T& item) {
		if (currentSize >= size) {
			cout << "Error: too much size" << endl;
		}
		else {
			elem[currentSize] = item;
			return currentSize++;
		}
	}
	void find(const T& item) const {
		int i = 0;
		for (i; i < currentSize; ++i) {
			if (item == elem[i]) {
				cout << "exist" << endl;
				return;
			}
		}
		cout << "not exist" << endl;
	}

	void remove(const T& item) {
		for (int i = 0; i < currentSize; ++i) {
			if (item == elem[i]) {
				for (int j = i; j < (currentSize - 1); j++) {
					elem[j] = elem[j + 1];
					currentSize--;
					return;
				}
			}
		}
		cout << "not exist" << endl;
	}

	void remove(const int location) {
		for (int i = 0; i < currentSize; ++i) {
			if (elem[i] == elem[location]) {
				for (int j = location; j < (currentSize - 1); j++) {
					elem[j] = elem[j + 1];
					currentSize--;
					return;
				}
			}
		}
		cout << "not exist" << endl;
	}

	List operator = (const List &L) {
		elem = new T[size];
		for (int i = 0; i < currentSize; i++) {
			elem[i] = L.elem[i];
		}
		return L;
	}

	~List() { delete[] elem; }
};



int main()
{
	List<Complex, 100> cList;
	List<MyString, 200> sList;
	//   
	int i1 = cList.add(Complex(0, 0));
	cList.add(Complex(1, 1));
	cList.find(Complex(0, 0));

	int i2 = sList.add("abc");
	sList.add("def");
	cList.find(Complex(1, 0));
	sList.find("def");
	cList.remove(i1) ;
	sList.remove("abc") ;

	List<MyString, 200> s2List(sList) ;
	List<MyString, 200> s3List ;
	s3List.add("123") ;
	s3List = s2List ;
	s3List.remove("def") ;

	return 0;
}
