#include <iostream>
#include <string>

using namespace std;

class StackException {
	const string msg;
public:
	StackException(const string& _msg) : msg(_msg)  {};
	void print() const { cout << msg << endl; }
};

class CharStack {
	int size;
	int top;
	char* s;
public:
	CharStack(int sz) { top = 0; s = new char[size = sz]; }
	CharStack(const CharStack &c) {
		size = c.size;
		top = c.top;
		s = new char[c.size];
		for (int i = 0; i < c.top; i++) {
			s[i] = c.s[i];
		}
		printf("Stack Copied\n");
	}
	void operator = (const CharStack &c) {
		size = c.size;
		top = c.top;
		delete []s;
		s = new char[c.size];
		for (int i = 0; i < c.top; i++) {
			s[i] = c.s[i];
		}
		printf("Stack assigned\n");
	}
	// destructor, copy constructor, and assignment operator
	void push(char c) {
		if (top == size) {
			throw StackException("Stack Full");
		}
		s[top++] = c;
	}
	char pop() {
		if (top <= 0) {
			throw StackException("Stack Empty");
		}
		char r = s[--top]; s[top] = '\0'; return r;
	}
	void print() const {
		for (int i = 0; i < top; i++) cout << s[i];
		cout << endl;
	}
	~CharStack() { delete []s; }
};


int main() {
	try {
		CharStack c(1);
		c.push('a');
		printf("Stack Full Cheack\n");
		c.push('b');
	}
	catch (const StackException& e) { cout << "Error: "; e.print(); }
	printf("--------------\n");
	try {
		CharStack c(1);
		printf("Stack Empty Cheack\n");
		char r = c.pop();
		printf("%c\n", r);
	}
	catch (const StackException& e) { cout << "Error: "; e.print(); }
	printf("--------------\n");
	try {
		CharStack c1(1);
		c1.push('a');
		CharStack c2(c1);
		printf("Stack Copy Cheack\n");
		char r1 = c1.pop();
		char r2 = c2.pop();
		printf("c1 pop is %c\n", r1);
		printf("c2 pop is %c\n", r2);
	}
	catch (const StackException& e) { cout << "Error: "; e.print(); }
	printf("--------------\n");
	try {
		CharStack c1(1);
		c1.push('b');
		CharStack c2(1);
		c2 = c1;
		printf("Stack assignment Cheack\n");
		char r1 = c1.pop();
		printf("c1 pop is %c\n", r1);
		char r2 = c2.pop();
		printf("c2 pop is %c\n", r2);
	}
	catch (const StackException& e) { cout << "Error: "; e.print(); }

	return 0;
}