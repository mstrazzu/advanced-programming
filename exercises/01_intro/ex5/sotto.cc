#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
   cout << "Insert the text to format \n";
   string word;
   getline(cin, word);
   
   unsigned int l = word.length(); // non posso mettere {}
   //cout << l << endl;
   
   unsigned int L = 27;
  cout << word.find_last_of (' ') << endl;
  string line = "";
  while (l > L){
   line = word.substr(0,L);
   //cout << line << "\n";
   int lim = line.find_last_of (' '); 
   cout << line.substr(0,lim) << endl;
   string new_line;
   new_line = word.substr(lim + 1, l);
    word = new_line;
    l = word.length();

}
cout << word << "\n";
  return 0;
}
