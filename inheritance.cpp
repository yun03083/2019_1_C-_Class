#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum EmployeeLevel { 사원, 대리, 과장, 차장, 부장 };
class Employee {
	string name;
	const EmployeeLevel level;
public:
	Employee();
	Employee(const string &name, const EmployeeLevel &_level):level(_level) {
		this->name = name;
	}
	string getName() const {
		return name;
	}
	EmployeeLevel getLevel() const {
		return level;
	}
	friend ostream& operator << (ostream &os, Employee &e);
	~Employee(){}
};
class Manager : public Employee {
	vector<Employee*> group;
public:
	Manager(const string &name, const EmployeeLevel &level):Employee(name, level) {
	}
	void addEmployee (Employee *employee) {
		group.push_back(employee);
	}
	void print() const {
		cout << getLevel() << '\t' << getName() << endl;
	}
	friend ostream& operator << (ostream &os, Manager &m);
	~Manager() {}
};

ostream& operator << (ostream &os, Employee &e) {
	os << e.getLevel() << '\t' << e.getName() << endl;
	return os;
}
ostream& operator << (ostream &os, Manager &m) {
	m.print();
	cout << "List of employees managed by me" << endl;
	for (vector<Employee*>::iterator it = (m.group).begin(); it != (m.group).end(); ++it) {
		os << (*it)->getLevel() << '\t' << (*it)->getName() << endl;
	}
	return os;
}
int main() {
	Employee e1("홍", 사원), e2("김", 대리), e3("차", 사원);
	cout << e1 << e2 << e3;

	Manager m1("Tom", 차장);
	m1.addEmployee(&e1);
	m1.addEmployee(&e2);
	m1.addEmployee(&e3);
	cout << endl << "Information for Manager" << endl;
	cout << m1;
}
