/*

Right Code

#include <iostream>

int main(){
    std::cout << "Hello World! \n";
    return 0;
}

*/



#include <iostream>

void add(int &a);
void addpo(int *p);

int main(){
    double a {7.5};
    add(a);
    std::cout << a << "\n";
    //int *p = &a;
    addpo(&a);
    std::cout << a << "\n";
    
    return 0;
}

void add(int &a){
a = a + 1;
}

void addpo(int *p){
*p = *p + 1;
}

