#include <string>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Lets do this
	string c;
	char dir;
	while(true) {
		//Wait for permission.
		cin >> c;
		switch(rand() % 4) {
			case 0: 
				dir = 'n';
				break;
			case 1:
				dir = 's';
				break;
			case 2:
				dir = 'e';
				break;
			case 3:
				dir = 'w';
				break;
		}
		cout << "move " << dir << endl;
	}
	return (EXIT_SUCCESS);
}

