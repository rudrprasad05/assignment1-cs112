#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    cout << "Prime numbers between 1 and 500 are:" << endl;
    
    for (int i = 1; i <= 500; ++i) {

        if(i == 1 || i == 2 || i == 3 || i == 5 || i == 7){
            cout << i << endl;
        }
        
        else if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0){
            cout << i << endl;
        }
    }
    
    
    
    return 0;
}
