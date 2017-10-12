#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    cout << "Insert the text to format \n";
    string word;
    getline(cin, word);
   
    unsigned int l = word.length(); // non posso mettere {}
    unsigned int L = 27;
    string line = "";
    while (l > L){
        line = word.substr(0,L);
        int lim = line.find_last_of (' '); 
        cout << line.substr(0,lim) << endl;
        string new_line;
        new_line = word.substr(lim + 1, l);
        //cout << new_line.length();
        word = new_line;
        l = word.length();
    }
    cout << word << "\n";
    return 0;
}
