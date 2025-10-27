#include <iostream>
#include <cstring>

using namespace std;

int main() {

	char input[80];

	bool running = true;

	while(running) {

		cin >> input;
		if (strcmp(input, "QUIT") == 0) running = false; 

	}


	return 0;

}
