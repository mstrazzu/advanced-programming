#include <iostream>
#include <string>

int main() {
  std::cout << "Insert your name and age:\n";
  std::string name;
  unsigned int age;
  std::cin >> name >> age;  //operator overflowing (no two lines)
  std::cout << "Hello, " << name << " [" << age << "]\n";
  return 0;
}
