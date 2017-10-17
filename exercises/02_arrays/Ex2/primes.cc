#include <iostream>

using namespace std;

int main(){
    const unsigned int threshold {100};
    int number {1};
    unsigned int size {1};
    unsigned int* primes {new unsigned int[1]};
    primes[0] = 2;
    while (number <= threshold){
        for (int i = 2; i < number; ++i){
            if (number%i == 0){
            break; // breaks at the first exact division
        }
        else if(number%i != 0){ 
            if (i == number - 1){
                size = size + 1;            // increase size
                unsigned int* temp {new unsigned int[size]}; // create new bigger array.
                for (int i=0; i<size; i++) {
                    temp[i] = primes[i];       // copy values to new array.
                    }
                delete [] primes;              // free old array memory.
                primes = temp;
                primes[size-1] = number;               // allocates the last prime found
                }         
        }
        }
        number = number + 1;
    }
    for (int i=0; i<size; i++) {
        cout << primes[i] << endl;    
        }
    delete[] primes;
}

