#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char* argv[]){
if (argc != 2) {
    cout << "I need exactly one argument\n";
    return 7;
  }
    const unsigned int threshold = atoi(argv[1]);
    unsigned int* Eratos{new unsigned int[threshold]};
    
    for(int i = 0; i <= threshold; ++i){
        Eratos[i] = true;
    }
    
    for (int i = 2; i <= sqrt(threshold); ++i){
    
    if (Eratos[i] == true){
        for(int k = 1; k <= threshold; ++k){
        
        for (int j = i*i; j <= threshold; j = j + k*i )
        {Eratos[j] = false;
        
        }
    }
    }
    
    }
    
    for (int i=2; i<=threshold; i++){
       
       if (Eratos[i] == true){
          cout << i << endl;
      }
  }
    delete[] Eratos;
}
