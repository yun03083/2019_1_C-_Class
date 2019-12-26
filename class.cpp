#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
	string name ;
	float gpa ;

public:
	void setGPA(const float &grade){
		gpa = grade;
	}
	void setName(const string &studentname){
		name = studentname;
	}
	string getName(){
		return name;
	}
	float getGrade(){
		return gpa;
	}
} ;

class School {
private:
	string schoolName ;
	vector<Student> students ;

public:
	School(const string& name){
		schoolName = name;
	}
	void addStudent(const string& studentname, const float grade = 0.0f){
		Student student;
		student.setName(studentname);
		student.setGPA(grade);
		students.push_back(student);
	}
	void print(){
		cout << "School Name: " << schoolName << ", " << "Count: " << students.size() << endl;
		for(vector<Student>::iterator it = students.begin(); it != students.end(); ++it){
			cout << "Name: " << (*it).getName() << " GPA: " << (*it).getGrade() << endl;
		}
		cout << '\n';
	}
	void sort(){
		for(vector<Student>::iterator it1 = students.begin(); it1 != students.end(); ++it1){
			for(vector<Student>::iterator it2 = it1+1; it2 != students.end(); ++it2){
				if( (*it1).getGrade() < (*it2).getGrade() ){
					swap(*it1,*it2);
				}
			}
		}
	}
	Student &findStudentWithName(const string& name){ 
		for(vector<Student>::iterator it = students.begin(); it != students.end(); ++it){
			string studentname = (*it).getName();
			if ( studentname == name ) {
				return *it;
			}
		}
	}
	
} ;



int main() {
	School pnu("PNU") ;

	pnu.addStudent("Kim", 2.7F) ;
	pnu.addStudent("Hong", 3.5F) ;
	pnu.addStudent("Lee") ;
	pnu.addStudent("Joo", 1.5F) ;
	
	pnu.print() ;

	pnu.sort() ; // descending
	pnu.print() ;

	School knu("KNU") ;
	knu.addStudent("Seo", 2.5F) ;
	knu.addStudent("Lee", 3.8F) ;
	knu.print() ;


	Student& lee = pnu.findStudentWithName("Lee") ;
	lee.setGPA(3.3F) ;
	lee.setName("Yoon") ;

	pnu.print() ;

	knu.addStudent("Hong", 4.3F) ;
	Student& hong = knu.findStudentWithName("Hong") ;
	hong.setGPA(3.3F) ;
	hong.setName("Joon") ;
	knu.print() ;

	
	return 0;
}
