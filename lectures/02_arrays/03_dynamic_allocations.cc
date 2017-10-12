#include <iostream>

int main() {
  std::cout << "Please insert array lenght: ";
  int n;
  std::cin >> n;
  int* da = new int[n];  // allocated on the HEAP, or free-store (portion of memory that could not be recovered without the pointer)

  for (int i = 0; i < n; ++i)
    da[i] = i * 10;

  for (int i = 0; i < n; ++i)
    std::cout << "da[" << i << "] = " << da[i] << std::endl;

  delete[] da; // in order to be sure not to write on the pointer write also p = nullptr; // and [] represents the array
  return 0;
}
