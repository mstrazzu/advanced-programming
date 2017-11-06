#include <iostream>
#include <string>
#include <ctype.h> 
#include <math.h> 
#include <typeinfo>
#include <stdlib.h>


using namespace std;

void get_double ();

struct String {};

struct Double {};




int main() {
try{
    get_double();
}catch (const String) {
    cerr << "An integer is needed, you entered a string" << endl;
    return 1;
  } catch (const Double) {
    cerr << "An integer is needed, you entered an integer: put a dot after it, example: 1." <<endl;
    return 2;
  } catch (...) {
    cerr << "Unknown exception. Aborting.\n";
    return 3;
    }
    
 return 0;
 }
    
void get_double (){
    string user_double;
    cout << "Insert a number: \n";
    cin >> user_double;
    int first_letter_bool = isdigit(user_double.at(0)); // c'è un modo più intelligente per capire se sto inserendo numeri sul cin?
    if (first_letter_bool == 0)
    throw String{};
    double number = strtod(user_double.c_str(), NULL);
    cout << number << endl;
    if ((int)number != number)
    throw Double{};
    
    cout << "Well done: you entered: " << number <<endl;

}

    
