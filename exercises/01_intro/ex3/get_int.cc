#include <iostream>
#include <string>

//using namespace std;

int main() {

    double user_int;
    std::cout << "Insert an Integer: \n";
    std::cin >> user_int;
    while(std::cin.fail() || (int) user_int != user_int) {
        std::cout << "Error, try again!" << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cin >> user_int;
    }
    std::cout << "Well done: you entered: " << user_int << std::endl;

    return 0;
}
