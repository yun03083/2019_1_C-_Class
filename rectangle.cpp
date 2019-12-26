#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cassert>
#include <algorithm>

using namespace std;

struct Rectangle {
	int width ;
	int height ;
} ;


enum CommandKind { ADD, SORT, PRINT, CLEAR, EXIT, INVALID} ;

CommandKind getCommandKind(const string &commandString){
	CommandKind enumUpperCommand;
	string stringUpperCommand;
	for (int i = 0; i < commandString.size(); i++){
		const char charInCommand = commandString[i];
		const char charUpper = toupper(charInCommand);
		stringUpperCommand += charUpper;
	}
	if(stringUpperCommand == "ADD"){
		enumUpperCommand = ADD;
	}
	if(stringUpperCommand == "SORT"){
		enumUpperCommand = SORT;
	}
	if(stringUpperCommand == "PRINT"){
		enumUpperCommand = PRINT;
	}
	if(stringUpperCommand == "CLEAR"){
		enumUpperCommand = CLEAR;
	}
	if(stringUpperCommand == "EXIT"){
		enumUpperCommand = EXIT;
	}
	if(stringUpperCommand == "INVALID"){
		enumUpperCommand = INVALID;
	}
	return enumUpperCommand;
}

Rectangle getRectangle(){
	Rectangle rectangle;
	int width, height;
	cin >> width >> height;
	rectangle.width = width;
	rectangle.height = height;
	
	return rectangle;
}

void print(const Rectangle& rectangles){
	int multiply = (rectangles.width)*(rectangles.height);
	cout << '\t' << rectangles.width << '\t' << rectangles.height << '\t' << multiply << endl;
}

void print(const vector<Rectangle> &rectangles){
	cout << "Rectangle Count: " << rectangles.size() << endl;
	for (vector<Rectangle>::const_iterator it = rectangles.begin(); it != rectangles.end(); ++ it){
		Rectangle iter;
		iter.width = it->width;
		iter.height = it->height;
		print(iter);
	}
}



void sort(vector<Rectangle> &rectangles){
	for( vector<Rectangle>::iterator itone = rectangles.begin(); itone != rectangles.end(); itone++){
		for( vector<Rectangle>::iterator ittwo = itone+1; ittwo != rectangles.end(); ittwo++){
			if ( ((itone->width)*(itone->height)) > ((ittwo->width)*(ittwo->height)) ){
				swap(*itone,*ittwo);
			}
		}
	}
}

int main() {
	vector<Rectangle> rectangles ;
	while ( true ) {
		string commandString;
        cin >> commandString;
		const CommandKind command = getCommandKind(commandString) ;
		switch ( command ) {
			case ADD : {
				const Rectangle newRectangle = getRectangle() ;
				rectangles.push_back(newRectangle) ;
				break ;
				}
			case PRINT:
				print(rectangles) ;
				// use const_iterator in print()
				// define and call print(const Rectangle&)
				break ;
			case SORT: {
				sort(rectangles) ; // define and call swap in sort()
				print(rectangles) ;
				break ;
				}
			case CLEAR: { rectangles.clear() ; break ;}
			case EXIT: break ;
			default:  assert (false) ; break ;
		}
		if ( command == EXIT ) break ;
	}
	
	return 0;
}

