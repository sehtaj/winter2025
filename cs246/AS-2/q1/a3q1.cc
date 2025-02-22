#include "plan.h"
#include<iostream>
#include<string>

using namespace std;

int main() {
	Date date{2018, 9, 26}; 
	Call call{date, 500, 10};
	Plan plan;
    bool done = false;

	string stored;	

	while ( ! done ) {
		char command;
		cin >> command;
		cin.ignore();
		if ( cin.eof() ) break;

		switch( command ) {
			case '+':
				//cin >> call;
				cout << "getline started";
				getline(cin,stored);
				cout << "stored: " << stored;
				plan.add( call );
				break;
			case 'p':
				cout << plan;
				break;
			case 'b':
				plan.calculateBill();
				break;
			case 'q':
				done = true;
				break;
			default:
				cerr << "Unrecognized command: '" << command << "'" << endl;
		} // switch
	} // while
	return 0;
} // main
