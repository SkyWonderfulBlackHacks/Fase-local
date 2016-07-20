
#include <iostream>

void getBetterInterval(int dayArray[], int days);

int main() {
    int tests;
    int days;
    int *dayArray;
    
    std::cin >> tests;
    
    for (int i = 0; i < tests; i++) {
        std::cin >> days;
        dayArray = new int[days];
        for (int j = 0; j < days; j++) {
            std::cin >> dayArray[j];
        }
        
        getBetterInterval(dayArray, days);
        delete[] dayArray;
    }
    return 0;
}

void getBetterInterval(int dayArray[], int days) {
    int betterGain = 0, actualGain = 0;
    int betterFirstDay = - 1, betterLastDay = - 1;
    
    
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