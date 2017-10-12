#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    double inches;
    cout << "Insert inches to convert: \n";
    cin >> inches;
    double m;
    m = 0.0254*inches;
    cout << inches << " inches = " << m << " m \n";
 
    
    return 0;  
}
