#include <iostream>

int main() {
  int a{5};
  int* pi{&a};
  *pi = 9;
  std::cout << "a is now " << a << std::endl; //prints 9

  char** ppc;

  int* ap[7]; // this is an array of  pointers

  int (*fp)(char*); // pointer to funtions that returns an integer and a pointer char as argument

  int* f(char*); // function thata returns an integer if you give a pointer to a char to it

  void* pv{pi}; // pointer that can point to everything but it does not know the size [problems]
  // *pv; // we cannot dereference void*
  // ++pv; // we cannot increment. Why?
  int* pi2 = static_cast<int*>(pv); // cast checked in compile time 

  pi = nullptr;   // nullptr USE IT! SO YOU REMEMBER THAT IS A POINTER!!
  ppc = nullptr;
  // ap = nullptr;			// error, why?
  fp = nullptr;
  pv = nullptr;
  pi2 = 0;  // older codes. gets the nullptr

  const int* pc = &a;
  // *pc = 7; 			// error
  a = 15;  // I can obviously change a

  int* const cp = &a;
  int b = 8;
  a = b;
  // cp = &b			// error

  const int* const cpc = &a;  // points to a fixed memory location
  // and cannot change it
  a = 99;

  return 0;
}
