#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::toupper;

string getCommand(){
	cout << "Enter command: (add, sum, average, quit) ";
	
	string commandString;
	cin >> commandString;
	return commandString;
}

string toUpperString(const string& command){
	string upperString;
	
	for(int i = 0; i < command.size(); i++){
		const char charInString = command[i];
		const char charUpper = toupper(charInString);
		upperString += charUpper;
	}
	return upperString;
}

void add(int scores[], int& count, int& maxSize){
	if(maxSize <= count){
		cout << '\t' << "Too many scores" << endl;
	}
	else {
		cout << "Enter score: ";
		int consider;
		cin >> consider;
	
		if(consider < 0 || consider > 100){
			cout << '\t' << "Score should be between 0 and 100" << endl;
		}
		else if(consider == 0){
			cout << '\t' << consider << " added" << endl;
			count++;
		}
		else{
			scores[count] = consider;
			cout << '\t' << consider << " added" << endl;
			count++;		
		}
	}
}

void sum(int scores[], int& count){
	int sum = 0;
	for(int i = 0; i < count ; i++){
		sum += scores[i];
	}
	
	cout << '\t' << "Sum: " << sum << endl;
}

void average(int scores[], int& count){
	int sum = 0;
	double average = 0;
	if (count == 0){
		cout << "You should input at least one score." << endl;
	}
	else{
		for(int i = 0; i < count ; i++){
			sum += scores[i];
		}
		average = (double)sum / count;
		cout << '\t' << "Average: " << average << endl;
	}
}

void executeCommand(const string& command, int scores[], int& count, int& maxSize){
	if(command == "ADD"){
		add(scores, count, maxSize);
	}
	if(command == "SUM"){
		sum(scores, count);
	}
	if(command == "AVERAGE"){
		average(scores, count);
	}
}

int main() {
	cout << "Enter the score count: ";
	int maxSize;
	cin >> maxSize;
	int* const scores = new int[maxSize]();
	int count = 0;
	while(true){
		const string& commandString = getCommand();
		const string& commandUpperString = toUpperString(commandString);
		if ( commandUpperString == "QUIT"){
			cout << '\t' << "Bye" << endl;
			break;
		}
		executeCommand(commandUpperString, scores, count, maxSize);
	}
	delete [] scores;
	return 0;
}
