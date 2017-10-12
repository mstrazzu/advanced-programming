#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

 string line;

 // How to get a string/sentence with spaces
 cout << "Please enter a valid sentence (with spaces):\n>";
 getline(cin, line);
 cout << "You entered: " << line << endl << endl;
return 0;
}
