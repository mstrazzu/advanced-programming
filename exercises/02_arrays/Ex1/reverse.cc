#include <iostream>
#include <typeinfo>


template <typename elements>
elements* new_array(const int n); // inizializza gli array
template <typename elements> // devo davvero ripetere ogni volta?
void print_reverse (elements* element, const int n); // printa reverse

int main() {
    int len;
    std::cin >> len;
    double* my_array {new_array<double>(len)};
    print_reverse<double>(my_array, len);
    delete[] my_array;

    return 0;
}

template <typename elements>
elements* new_array(const int n){
    elements* vector {new elements[n]};
    for (int i = 0; i < n; ++i) {
      std::cin >> vector[i] ;
    }
    return vector;
}
template <typename elements>
void print_reverse(elements* element, const int n){
    for (int i = n-1; i>= 0; --i) {
    
    std::cout << element[i] << std::endl;
    
    }

}

