#include <iostream>

int main() {
  double d = 9.9;
  double &ref = d; //pointer = another variable with the address of the variable "d" (the first bit number) // &ref = ALIAS
  double *ptr = &d;
  std::cout << "content of   d: " << d << std::endl;
  std::cout << "content of ref: " << ref << std::endl;
  std::cout << "content of ptr: " << ptr << std::endl << std::endl;
  std::cout << "address of   d: " << &d << std::endl;
  std::cout << "address of ref: " << &ref << std::endl;
  std::cout << "address of ptr: " << &ptr << std::endl;
}
