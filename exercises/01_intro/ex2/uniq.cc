#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    //std::istringstream f("ciao\nciao\nsono\nMaria!");
    string line; 
    string tmp_line = "";
    while (getline(cin, line)) {     // con cin non funziona
        if (tmp_line != line){
        cout << line << endl;
        tmp_line = line;
        }
    
    
    }
    
  return 0;  
}
