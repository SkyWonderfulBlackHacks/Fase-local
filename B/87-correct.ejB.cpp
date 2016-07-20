#include <iostream>

int main() {
    int tests, s, c, result;
    std::cin >> tests;
    
    for (int i = 0; i < tests; i++) {
        std::cin >> s >> c;
        
        result = s + c;
        
        if (result >= 0) {
            std::cout << "SI" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}