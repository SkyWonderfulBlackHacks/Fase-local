
#include <iostream>

void getBetterInterval(long long int dayArray[], long long int days);

int main() {
    int tests;
    long long int days;
    long long int *dayArray;
    
    std::cin >> tests;
    
    for (int i = 0; i < tests; i++) {
        std::cin >> days;
        dayArray = new long long int[days];
        for (int j = 0; j < days; j++) {
            std::cin >> dayArray[j];
        }
        
        getBetterInterval(dayArray, days);
        delete[] dayArray;
    }
    return 0;
}


void getBetterInterval2(long long int dayArray[], long long int days) {
    for (int j = 0; j < days; j++) {
        std::cout << dayArray[j] << std::endl;
    }
}

void getBetterInterval(long long int dayArray[], long long int days) {
    long long int betterGain = 0, actualGain = 0;
    long long int betterFirstDay = -1, betterLastDay = -1;
    
    
    for (int i = 0; i < days; i++) {
        if (dayArray[i] < 0) continue;
        actualGain = 0;
        
        for (int j = i; j < days; j++) {
            actualGain += dayArray[j];
            
            //std::cout << "Act1: " << actualGain << "  This: " << dayArray[j] << std::endl;
            //std::cout << dayArray[j] << std::endl;
            
            if (actualGain > betterGain) {
                betterGain = actualGain;
                betterFirstDay = i;
                betterLastDay = j;
                //std::cout << "Best1: " << betterGain << "  This: " << dayArray[j] << std::endl;
            } else if (actualGain == betterGain) {
                if ((j - i) < (betterLastDay - betterFirstDay)) {
                    betterGain = actualGain;
                    betterFirstDay = i;
                    betterLastDay = j;
                    //std::cout << "Best1: " << betterGain << "  This: " << dayArray[j] << std::endl;
                }
            }
            
            //if (actualGain < -10000 || actualGain > 10000) break;
            
        }
    }
    
    std::cout << betterFirstDay+1 << " " << betterLastDay+1 << std::endl;
    
}