#include <iostream>
#include <string>

using namespace std;

char getGrade(int score);

int main() {	
	while (1){
		string name;
		int score;
		char grade;
		cout << "Enter a name and score: ";
		cin >> name;
		cin >> score;
		if (score < 0 || score >100){
			cout << "Bye " << name;
			break;
		}
		grade = getGrade(score);
		cout << "Hi: " << name << "! Your grade is " << grade << endl;
	}
	return 0;
}

char getGrade(int score) {
	if (score >= 90){
		char grade = 'A';
		return grade;
	}
	else if (80 <= score && score < 90){
		char grade = 'B';
		return grade;
	}
	else if (70 <= score && score < 80){
		char grade = 'C';
		return grade;
	}
	else if(60 <= score && score < 70){
		char grade = 'D';
		return grade;
	}
	else {
		char grade = 'F';
		return grade;
	}
}


