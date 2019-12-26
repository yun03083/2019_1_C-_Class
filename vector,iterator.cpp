#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

const int SUBJECT_NO = 3;

struct StudentInfo {
	string name;
	int scores[SUBJECT_NO];
	int sum;
	float average;
};

int getstudentnumber(){
	int i;
	cin >> i;
	return i;
}

int getstudentinfo(int &studentnumber, vector <StudentInfo> &studentvector){
	for (int i = 0; i < studentnumber; ++i){
		cin >> studentvector[i].name;
		for (int j=0; j < SUBJECT_NO; j++){
			cin >> studentvector[i].scores[j];
			studentvector[i].sum += studentvector[i].scores[j];
		}
		studentvector[i].average = (float)studentvector[i].sum / SUBJECT_NO;
	}
	
}


void printstudentvector(int &studentnumber, vector <StudentInfo> &studentvector){
	int number = 1;
	for ( vector<StudentInfo>::iterator it = studentvector.begin() ; it != studentvector.end() ; ++ it ){
		cout << number << '\t';
		cout << it->name << '\t';
		number++;
		for (int i = 0; i < SUBJECT_NO; i++){
			cout << it->scores[i] << '\t';
		}
		cout << it->sum << '\t';
		cout << it->average << endl;
	}
}

void printscoretotal(int &studentnumber, vector <StudentInfo> &studentvector){
	int totalscores[SUBJECT_NO]={0,};
	int totalsum = 0;
	for ( vector<StudentInfo>::iterator it = studentvector.begin() ; it != studentvector.end() ; ++ it ){
		for (int i = 0; i < SUBJECT_NO; i++){
				totalscores[i] += it->scores[i];
			}
		totalsum += it->sum;
		}
	cout << "Total" << '\t';
	for (int i = 0; i < SUBJECT_NO; i++){
		cout << totalscores[i] << '\t';
	}
	cout << totalsum << endl;
}

int main() {
	int studentnumber = getstudentnumber();
	
	vector<StudentInfo> studentvector(studentnumber);
	
	getstudentinfo(studentnumber, studentvector);
	
	printstudentvector(studentnumber, studentvector);
	printscoretotal(studentnumber, studentvector);
	
	
	return 0;
}



