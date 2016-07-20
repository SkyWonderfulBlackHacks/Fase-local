
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

void getBetterInterval(long long int dayArray[], long long int days) {
    long long int betterGain = 0, actualGain = 0;
    long long int betterFirstDay = - 1, betterLastDay = - 1;
    
    
    for (int i = 0; i < days; i++) {
        if (dayArray[i] < 0) continue;
        actualGain = 0;
        
        for (int j = i; j < days; j++) {
            actualGain += dayArray[j];
   
            if (dayArray[j] > 0) {
                if (actualGain > betterGain) {
                    betterGain = actualGain;
                    betterFirstDay = i;
                    betterLastDay = j;
                } else if (actualGain == betterGain) {
                    if ((j - i) < (betterLastDay - betterFirstDay)) {
                        betterGain = actualGain;
                        betterFirstDay = i;
                        betterLastDay = j;
                    }
                }
            } 
        }
    }
    
    std::cout << betterFirstDay+1 << " " << betterLastDay+1 << std::endl;
    
}