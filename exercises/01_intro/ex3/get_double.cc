#include <iostream>
#include <string>

//using namespace std;

int main() {

    double user_double;
    std::cout << "Insert an Integer: \n";
    std::cin >> user_double;
    while(std::cin.fail() || (int) user_double == user_double) {
        std::cin.clear();
        std::cin.ignore();
        std::cin >> user_double;
        std::cout << "Error, try again!" << std::endl;
    }
    std::cout << "Well done: you entered: " << user_double << std::endl;

    return 0;
}
