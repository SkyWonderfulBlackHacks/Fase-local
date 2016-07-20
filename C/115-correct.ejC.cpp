#include <iostream>

int main() {
    int tests, nTemps;
    
    std::cin >> tests;
    
    for (int i = 0; i < tests; i++) {
        int picos = 0, valles = 0;
        std::cin >> nTemps;
        
        int *temps = new int[nTemps];
        
        for (int j = 0; j < nTemps; j++) {
            std::cin >> temps[j];
        }

        int tempAnt, tempAct, tempSgt;
        
        for (int k = 1; k < nTemps - 1; k++) {
            tempAnt = temps[k - 1];
            tempAct = temps[k];
            tempSgt = temps[k + 1];
            
            if (tempAnt < tempAct && tempAct > tempSgt) {
                picos++;
            }
            else if (tempAnt > tempAct && tempAct < tempSgt) {
                valles++;
            }
        }  
     
        delete[] temps;
        
        std::cout << picos << " " << valles << std::endl;
    }
}